/**
* @file Queue.cpp
* @description Radix Sort için kuyruk gövdesi
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 13.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#include "Queue.hpp"
#include <iostream>
#include <math.h>
Queue::Queue()
{
    head=0;
    tail=0;
}
Queue::~Queue()
{
    remove();
}
void Queue::enqueue(int data){
    QueueNode* temp= new QueueNode(data);

    if(head==0)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }    
}
void Queue::dequeue(){
    if(head!=0)
    {
        QueueNode *temp = head->next;
        delete head;
        head=temp;
        if(head==0)
            tail=0;
    }
}
void Queue::remove(){
    while(!isEmpty()){
        dequeue();
    }
}

bool Queue::isEmpty(){
    if(head==0)
        return true;
    return false;    
}
int Queue::peek()
{   
    if(head!=0)
        return head->data;
    throw std::out_of_range("Queue is empty!");
}