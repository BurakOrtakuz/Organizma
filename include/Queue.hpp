/**
* @file Queue.cpp
* @description Radix Sort için kuyruğun başlık dosyası
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 13.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "QueueNode.hpp"

class Queue
{
private:      

public:    
    QueueNode* head;
    QueueNode* tail;
    Queue();
    ~Queue();
    void enqueue(int data);
    void dequeue();
    bool isEmpty();
    void remove();
    int peek();
};

#endif // QUEUE_HPP