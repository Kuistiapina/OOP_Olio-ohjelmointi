#include "asiakas.h"
#include <iostream>


using namespace std;

asiakas::asiakas(string asiakkaanNimi, double luottoRaja):nimi(asiakkaanNimi),kayttotili(nimi),luottotili(nimi,luottoRaja) {

    cout << "Asiakkuus luotu " << nimi << ":lle " << endl;
    cout << "Käyttötilin saldo: "  << kayttotili.getBalance()  << endl;
    cout << "Luottotilin saldo: "  << luottotili.getBalance()  << endl << endl << endl;

}

void asiakas::showSaldo(){


    cout << "Asiakas: " << nimi << endl;
    cout << "  Pankkitilin saldo: " << kayttotili.getBalance() << endl;
    cout << "  Luottotilin saldo: " << luottotili.getBalance() << endl;

}

bool asiakas::talletus(double talletuksenMaara){

    return kayttotili.deposit(talletuksenMaara);
}

bool asiakas::nosto(double nostonMaara){

    return kayttotili.withdraw(nostonMaara);
}

bool asiakas::luotonMaksu(double luottoMaksunMaara){

    return luottotili.deposit(luottoMaksunMaara);
}

bool asiakas::luotonNosto(double luottoNostonMaara){

    return luottotili.withdraw(luottoNostonMaara);
}

bool asiakas::tiliSiirto(double siirronMaara, asiakas &siirronVastaanottaja) {

    if (siirronMaara <= 0){

        cout <<"Siirrettävä summa on liian pieni!" << endl << endl;
        return false;

    }

    if (kayttotili.withdraw(siirronMaara) && siirronVastaanottaja.talletus(siirronMaara)) {

        kayttotili.deposit(siirronMaara);
        return true;
    }


    cout <<"Rahan nosto siirtoa varten epäonnistui!" << endl << endl;
    return false; // Palautetaan bool-arvolle false jos rahan nosto tililtä epäonnistuu (esim. tilillä ei ole tarpeeksi rahaa)
}

