#ifndef ASIAKAS_H
#define ASIAKAS_H
#include "pankkitili.h"
#include "luottotili.h"
#include <string>
using namespace std;

class asiakas
{
public:
    asiakas(string asiakkaanNimi, double luottoRaja);
    string getNimi();
    void showSaldo(); // Tulostus molempien tilien saldoista
    bool talletus(double); // Pankkitili
    bool nosto(double); // Pankkitili
    bool luotonMaksu(double); // Luottotili
    bool luotonNosto(double); // Luottotili
    bool tiliSiirto(double siirronMaara, asiakas &siirronVastaanottaja);  // Pankkitilisiirto: tästä asiakkaasta toiseen (viittauksella)



private:

    string nimi;
    pankkitili kayttotili;
    luottotili luottotili;
};

#endif // ASIAKAS_H
