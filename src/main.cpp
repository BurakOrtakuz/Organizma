/**
* @file main.cpp
* @description main dosyası
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 13.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#include "Organism.hpp"
#include <iostream>

int main(void)
{   
    Organism *organism= new Organism();
    organism->print(false);
    std::cin.ignore();
    organism->print(true);
    delete organism;
}