/**
* @file SystemNode.cpp
* @description SystemNode dosyasının gövdesi
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 20.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#include "SystemNode.hpp"

SystemNode::SystemNode(Organ *data)//Kurucu sınıf
{
    this->data = data;
    this->next = nullptr;
}
SystemNode::~SystemNode()
{
    delete data;
}