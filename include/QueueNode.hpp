/**
* @file Queue.cpp
* @description Radix Sort için kuyruk düğümünün başlık dosyası
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 13.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#ifndef  QUEUENODE_HPP
#define QUEUENODE_HPP

class QueueNode{
public:    
    QueueNode(int data);  
    QueueNode* next;
    int data;
};

#endif // QUEUENODE_HPP