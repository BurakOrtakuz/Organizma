/**
* @file Organism.hpp
* @description Organizma dosyasının başlık dosyası
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 23.12.2022
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#ifndef ORGANISM_HPP
#define ORGANISM_HPP

#include "OrgNode.hpp"

class Organism
{
private:
    int size;
    OrgNode* first;
    OrgNode* last;
public:
    Organism();
    ~Organism();
    void add(System *data);
    void deleteOrgan(int position);
    void clean();
    void print(bool mutation);
};
#endif // ORGANISM_HPP