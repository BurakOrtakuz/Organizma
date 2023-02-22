/**
* @file Cell.hpp
* @description Node dosyasının başlık dosyası
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 15.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#ifndef CELL_HPP
#define CELL_HPP

class Cell
{
public:
    Cell(int data);
    int data;
    Cell* next;
};
#endif // CELL_HPP