/**
* @file System.cpp
* @description System dosyasının gövdesi
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 20.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#include "System.hpp"
#include <iostream>

System::System()
{
    size = 0;
    first = nullptr;
    last = nullptr;
}
System::~System()
{
    clean();
}
void System::add(Organ *data)
{
    SystemNode* temp= new SystemNode(data);
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
void System::deleteOrgan(int position)//bool çevir ve yazdırma ile haberleş
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

    SystemNode* temp = first;
    
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
        SystemNode *deletedSystemNode= temp->next;         
        temp->next = temp->next->next;
        delete deletedSystemNode;

    }else{//Son eleman olması durumu
        last = temp;
        last->next = nullptr;
        delete temp->next; 
    }
    size--;
}
void System::clean()
{
    for(int i = size; i >= 0; i--)
    {
        deleteOrgan(i);
    }
}

void System::mutation()
{      
    SystemNode *temp = first;
    while(temp != nullptr)
    {
        if(temp->data->getRoot()->data->median() % 50 == 0)//Kök değerinin 50'ye bölünmesi
        {
            Tissue **mutationList= temp->data->postOrderTreversal();
            Organ *organ = new Organ();
            for(int i=0; i<20; i++)//Organdaki her elamanı dolaşma
            {
                Tissue *tissue = new Tissue();
                Cell *cell = mutationList[i]->getFirst();
                while(cell != nullptr)//Sıfırdan dokunun oluşturulması
                {
                    /*
                    if(cell->data % 2 == 0)//Ödeve göre olması gereken ama yaptığımda hatalı çıktıya neden olan kısım
                    {
                        cell->data /= 2;
                    }
                    */
                    tissue->add(cell->data);
                    cell = cell->next;
                }
                organ->insert(tissue);       
            }
            temp->data->clean();//Eski dokunun silinmesi
            temp->data = organ;//Yeni dokunun eklenmesi
        }
        temp = temp->next;
    }
}

void System::print()
{
    SystemNode *temp = first;
    while(temp != nullptr)
    {
        if(temp->data->isBalanced())
        {
            std::cout<<" ";
        }
        else{
            std::cout<<"#";
        }   
        temp = temp->next;
    }
}
