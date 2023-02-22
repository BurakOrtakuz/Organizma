/**
* @file Queue.cpp
* @description Radix Sort gövdesi
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 13.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#include <math.h>
#include <iostream>
#include "Radix.hpp"

Radix::Radix()
{
    queues = new Queue*[10];
    queues[0]= new Queue();
    queues[1]= new Queue();
    queues[2]= new Queue();
    queues[3]= new Queue();
    queues[4]= new Queue();
    queues[5]= new Queue();
    queues[6]= new Queue();
    queues[7]= new Queue();
    queues[8]= new Queue();
    queues[9]= new Queue();
}

Radix::~Radix()
{
    delete queues[0];
    delete queues[1];
    delete queues[2];
    delete queues[3];
    delete queues[4];
    delete queues[5];
    delete queues[6];
    delete queues[7];
    delete queues[8];
    delete queues[9];
    delete queues;

}

void Radix::sort(Tissue *tissue)
{
    Cell *temp;
    int counter = 0;
    int digit = 0;
    for(int i=0; i<biggestOrder(tissue); i++)//En büyük basamak değeri kadar dönüyor.
    {
        temp=tissue->getFirst();
        while(temp != nullptr)
        {
            digit = digitValue(temp->data,counter);
            queues[digit]->enqueue(temp->data);
            temp = temp->next;
        }
        tissue->clean();
        for(int i=0; i<10; i++)
        {
            while(!queues[i]->isEmpty())
            {
                tissue->add(queues[i]->peek());
                queues[i]->dequeue();
            }
        }
        counter++;        
    }
}

int Radix::order(int number)
{
    int order = 0;
    while(number!=0)
    {
        number= number / 10;
        order++;
    }
    return order;
}

int Radix::digitValue(int number, int digit)
{
    for(int i=0;i<digit;i++)
    {
        number/=10;
    }
    return number%10;
}

int Radix::biggestOrder(Tissue *tissue)
{
    Cell* temp = tissue->getFirst();
    int biggestOrder = 0;
    while(temp != nullptr)
    {
        if(order(temp->data)>biggestOrder)
        {
            biggestOrder= order(temp->data);
        }
        temp = temp->next;
    }
    return biggestOrder;
}