/**
* @file OrgNode.cpp
* @description Organizma sınıfının düğümünün gövdesi
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 23.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#include "OrgNode.hpp"

OrgNode::OrgNode(System *data)//Kurucu sınıf
{
    this->data = data;
    this->next = nullptr;
}
OrgNode::~OrgNode()//Yıkıcı sınıf
{
    delete data;
}