/**
* @file System.hpp
* @description Sistem dosyasının başlık dosyası
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 20.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "SystemNode.hpp"
#include "Radix.hpp"
class System
{
private:
    int size;
    SystemNode* first;
    SystemNode* last;
public:
    System();
    ~System();
    void add(Organ *data);
    void deleteOrgan(int position);
    void clean();
    void mutation();
    void print();
};
#endif // SYSTEM_HPP