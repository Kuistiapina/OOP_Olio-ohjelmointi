#include <iostream>
#include "asiakas.h"
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Finnish_Finland.1252");

    asiakas Seppo("Sepi", 2000.88);
    asiakas Santtu("Santeri", 4753.00);

    Seppo.talletus(500.30);       // Talletus pankkitilille
    Seppo.nosto(120.0);           // Nosto pankkitililtä
    Seppo.luotonNosto(200.0);     //
    Seppo.luotonMaksu(100.0);     //

    Seppo.tiliSiirto(200.0, Santtu); // Tehtävän osio 2: siirto pankkitililtä pankkitilille viittauksella vastaanottajaan

    Seppo.showSaldo();
    Santtu.showSaldo();

    return 0;
}
