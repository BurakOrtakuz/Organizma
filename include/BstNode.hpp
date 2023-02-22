/**
* @file BstNode.hpp
* @description Binary Search Tree Node'unun başlık dosyası
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 16.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include "Tissue.hpp"

class BstNode
{
public:
    BstNode(Tissue *tissue);
    ~BstNode();
    Tissue* data;
    BstNode* left;
    BstNode* right;
};
#endif // BSTNODE_HPP