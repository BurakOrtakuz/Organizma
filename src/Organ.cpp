/**
* @file Organ.cpp
* @description Binary Search Tree'nin gövdesi
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 16.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#include "Organ.hpp"
#include <algorithm>
#include <iostream>
Organ::Organ()
{
    root = 0;
    size = 0;
    i = 0;
}

Organ::~Organ()
{
    clean();
}

void Organ::insert(Tissue *tissue)
{
    if(root)
    {
       insertFunction(root, tissue); 
    }
    else
    {
        root = new BstNode(tissue);
    }
    size ++;
}

Tissue **Organ::postOrderTreversal()
{
    Tissue **mutationList = new Tissue*[20];
    postOrderTreversal(root, mutationList);
    return mutationList;
}

bool Organ::isBalanced()
{
    if(root)
    {
        if(std::abs(height(root->left) - height(root->right)) > 1)
        {
            return false;
        }
        else
        {
            return true;
        }        
    }
    throw std::out_of_range("Kök bulunamadı");
}

BstNode *Organ::getRoot()
{
    return root;
}
//Private Fonksiyonlar
void Organ::insertFunction(BstNode *currentNode, Tissue *data)
{
    if(currentNode->data->median()>=data->median())
    {
        if(currentNode->left)
        {
            insertFunction(currentNode->left,data);
        }
        else
        {
            currentNode->left = new BstNode(data);
        }
    }
    else if(currentNode->data->median()<data->median())
    {
        if(currentNode->right)
        {
            insertFunction(currentNode->right,data);
        }
        else
        {
            currentNode->right = new BstNode(data);
        }
    }
}

int Organ::height(BstNode *currentNode)
{
    if(currentNode)
    {
        return 1 + std::max(height(currentNode->left), height(currentNode->right));
    }
    return -1;
}

void Organ::clean()
{
    clean(root);
    root = 0;
    size = 0;
    i = 0;
}

void Organ::postOrderTreversal(BstNode *currentNode,Tissue **tissue)
{
    if(currentNode)//Ağacı post order dolaşıp verileri tissue dizisine ekleme
    {
        postOrderTreversal(currentNode->left, tissue);
        postOrderTreversal(currentNode->right, tissue);
        tissue[i] = currentNode->data;
        i++;
    }
}

void Organ::clean(BstNode* currentNode)
{
    if(currentNode)
    {
        clean(currentNode->left);
        clean(currentNode->right);
        delete currentNode;
    }
}