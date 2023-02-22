/**
* @file Tissue.hpp
* @description Doku dosyasının başlık dosyası
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 15.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#ifndef TISSUE_HPP
#define TISSUE_HPP

#include "Cell.hpp"

class Tissue
{
private:
    int size;
    Cell* first;
    Cell* last;
public:
    Tissue();
    ~Tissue();
    void add(int data);
    void deleteCell(int position);
    void clean();
    int median();
    Cell *medianCell();
    Cell* getFirst();
    int getSize();
};
#endif // TISSUE_HPP