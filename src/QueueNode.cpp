/**
* @file Queue.cpp
* @description Radix Sort için kuyruk düğümü
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 13.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#include "Queue.hpp"
#include <iostream>
QueueNode::QueueNode(int data)
{
    this->next=0;
    this->data= data;
}
