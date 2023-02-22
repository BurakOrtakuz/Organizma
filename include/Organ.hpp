/**
* @file Organ.hpp
* @description Binary Search Tree'nin başlık dosyası
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 16.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#ifndef ORGAN_HPP
#define ORGAN_HPP

#include "BstNode.hpp"

class Organ
{
public:
    Organ();
    ~Organ();
    void insert(Tissue *tissue);
    void clean();
    Tissue **postOrderTreversal();
    bool isBalanced();
    BstNode *getRoot();
private:
    void insertFunction(BstNode *currentNode, Tissue *data);
    void postOrderTreversal(BstNode *currentNode, Tissue **tissue);
    int height(BstNode *currentNode);
    void clean(BstNode *currentNode);
    BstNode* root;
    int i;
    int size;
};
#endif // ORGAN_HPP