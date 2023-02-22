/**
* @file Tissue.cpp
* @description Tissue dosyasının gövdesi
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 15.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#include "Tissue.hpp"
#include <iostream>
Tissue::Tissue()
{
    size = 0;
    first = nullptr;
    last = nullptr;
}
Tissue::~Tissue()
{
    clean();
}
void Tissue::add(int data)
{
    Cell* temp= new Cell(data);
    if(first==nullptr)//İlk elemanın eklenmesi durumu
    {
        first=temp;
        last=temp;
        size++;
    }else{//İlk sırada olmayan elamanların eklenmesi durumu
        last->next=temp;
        last = temp;
        size++;
    }
}
void Tissue::deleteCell(int position)//bool çevir ve yazdırma ile haberleş
{
    if(size==0)//Elaman olmaması durumu
        return;
    if(size==1)//tek eleman olması durumu
    {
        first = nullptr;
        last = nullptr;
        size--;
        return;
    }

    Cell* temp = first;
    
    if(position == 1)//İlk elemanı silme durumu
    {
        first = temp->next;
        delete temp;
        size--;
        return;
    }
    
    int i = 1;
    
    while(temp->next != nullptr)//Silinecek elemanı arıyoruz
    {
        if(i==position)
            break;
        i++;
        temp = temp->next;
    }
    if(temp != last)//Son eleman olmaması durumu
    {    
        Cell *deletedCell= temp->next;         
        temp->next = temp->next->next;
        delete deletedCell;

    }else{//Son eleman olması durumu
        last = temp;
        last->next = nullptr;
        delete temp->next; 
    }
    size--;
}
void Tissue::clean()
{
    for(int i = size; i > 0; i--)
    {
        deleteCell(i);
    }
}

int Tissue::median()
{
    Cell *temp = first;
    for(int i=0; i<size/2; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

Cell *Tissue::medianCell()
{
    Cell *temp = first;
    for(int i=0; i<size/2; i++)
    {
        temp = temp->next;
    }
    return temp;
}

Cell* Tissue::getFirst()
{
    return first;
}

int Tissue::getSize()
{
    return size;
}