/**
* @file BstNode.cpp
* @description Binary Search Tree Node'unun gövdesi
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 16.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#include "BstNode.hpp"

BstNode::BstNode(Tissue *tissue)
{
    left = 0;
    right = 0;
    this->data = tissue;
}
BstNode::~BstNode()
{
    delete data;
}