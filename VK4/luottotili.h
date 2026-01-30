#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include "pankkitili.h"
#include <string>
using namespace std;

// Luottotili-luokka perii Pankkitilin.
// Tarvitsee siis tehdä omat toteutukset luottotililtä nostolle/luottovelan maksulle, perittyihin virtuaalifunktioihin.
// Hox! Muistakaa avainsana override.


class luottotili: public pankkitili
{
public:

    luottotili(string, double);
    bool deposit(double) override;
    bool withdraw(double) override;

protected:

    double luottoRaja = 0;
};

#endif // LUOTTOTILI_H
