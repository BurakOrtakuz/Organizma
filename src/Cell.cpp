/**
* @file Cell.cpp
* @description Cell dosyasının gövdesi
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 15.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#include "Cell.hpp"

Cell::Cell(int data)//Kurucu sınıf
{
    this->data = data;
    this->next = nullptr;
}