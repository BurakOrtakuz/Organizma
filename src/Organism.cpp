/**
* @file Organism.cpp
* @description Organizma sınıfının gövdesi
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 23.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#include "Radix.hpp"
#include "Organism.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

Organism::Organism()
{
    size = 0;
    first = nullptr;
    last = nullptr;
    std::ifstream reader("./Veri.txt");
    std::string data ="";
    Radix *radix= new Radix();
    while(!reader.eof())//Dosya sonuna kadar okuma
    {   
        System *system = new System();
        for(int i=0; i<100; i++)//Her sistemdeki organları ekleme
        {
            Organ *organ = new Organ();
            for(int j=0; j < 20;j++)//Her organa dokuları ekleme
            {
                std::getline(reader,data);
                data = data + " ";//Veri dosyasının sonunda boşluk olmadığından parçalama işleminin verdiği hatanın çözümü
                Tissue *tissue = new Tissue();
                while(data!="") //Her satırı parçalara ayırma ve dokuya ekleme
                {
                    tissue->add(stoi(data.substr(0,data.find_first_of(" "))));
                    data=data.substr(data.find_first_of(" ")+1,data.length()-data.find_first_of(" ")); 
                }
                radix->sort(tissue);
                organ->insert(tissue);       
            }
            system->add(organ);
        }
        add(system);
    }
    delete radix;
    reader.close();
}
Organism::~Organism()
{
    clean();
}
void Organism::add(System *data)
{
    OrgNode* temp= new OrgNode(data);
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
void Organism::deleteOrgan(int position)//bool çevir ve yazdırma ile haberleş
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

    OrgNode* temp = first;
    
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
        OrgNode *deletedOrgNode= temp->next;         
        temp->next = temp->next->next;
        delete deletedOrgNode;

    }else{//Son eleman olması durumu
        last = temp;
        last->next = nullptr;
        delete temp->next; 
    }
    size--;
}
void Organism::clean()
{
    for(int i = size; i >= 0; i--)
    {
        deleteOrgan(i);
    }
}

void Organism::print(bool mutation)
{
    OrgNode *temp = first;
    system("cls");
    std::cout<<std::setw(50)<<"ORGANIZMA";
    if(mutation)
        std::cout<<"(MUTASYONA UGRADI)"<<std::endl;
    else
        std::cout<<std::endl;
    while(temp != nullptr)
    {
        if(mutation)
            temp->data->mutation();
        temp->data->print();
        std::cout<<std::endl;
        temp = temp->next;
    }
}
