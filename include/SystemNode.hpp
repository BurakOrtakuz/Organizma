/**
* @file SystemNode.hpp
* @description SystemNode dosyasının başlık dosyası
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 20.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#ifndef SYSTEMNODE_HPP
#define SYSTEMNODE_HPP

#include "Organ.hpp"

class SystemNode
{
public:
    SystemNode(Organ *data);
    ~SystemNode(); 
    Organ *data;
    SystemNode* next;
};
#endif // SYSTEMNODE_HPP