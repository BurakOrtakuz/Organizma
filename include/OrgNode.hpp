/**
* @file OrgNode.hpp
* @description Organizma düğümünün dosyasının başlık dosyası
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 23.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#ifndef ORGNODE_HPP
#define ORGNODE_HPP

#include "System.hpp"

class OrgNode
{
public:
    OrgNode(System *data);
    ~OrgNode(); 
    System *data;
    OrgNode* next;
};
#endif // SYSTEMNODE_HPP