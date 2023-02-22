/**
* @file Queue.cpp
* @description Radix Sort'un başlık dosyası
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 13.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#ifndef RADIX_HPP
#define RADIX_HPP

#include "Queue.hpp"
#include "Tissue.hpp"

class Radix
{
private:
    Queue **queues;
public:

    Radix();
    ~Radix();
    void sort(Tissue *tissue);
    int order(int number);
    int digitValue(int number, int digit);
    int biggestOrder(Tissue *tissue);
};
#endif // RADIX_HPP