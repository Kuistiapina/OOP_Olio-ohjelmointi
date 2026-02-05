#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H
#include "seuraaja.h"
#include <iostream>

using namespace std;

class Notifikaattori
{
public:
    Notifikaattori();
    void lisaa(Seuraaja *tilaaja);
    void poista(Seuraaja *tilaaja);
    void tulosta();
    void postita(string v);

private:

   Seuraaja *seuraajat = nullptr;
};

#endif // NOTIFIKAATTORI_H
