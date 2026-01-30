#include "luottotili.h"
#include <iostream>

using namespace std;

luottotili::luottotili(string omistaja, double luottoSaldo):pankkitili(omistaja), luottoRaja(luottoSaldo) {

    // Konstruktorissa on nyt parametrit tilinomistajan nimi ja henkilökohtainen luottoraja.
    saldo = luottoSaldo;
    cout << "Luottotili luotu " << omistaja << ":lle " << getBalance() << " luottorajalla." << endl << endl;

}

bool luottotili::deposit(double depositAmount){

    // deposit() tekee talletuksen tilille.
    // Negatiivisia velanmaksuja ei voi tehdä. Esim. velanmaksun parametriksi ei voi antaa summaa -123.
    // Palauttaa true/false sen mukaan onnistuiko talletus/nosto.


    if (depositAmount <= 0){

        cout <<"Talletettava summa on liian pieni!" << endl << endl;
        return false;
    }
    double uusiLuottoSaldo = saldo + depositAmount;

    if (uusiLuottoSaldo > luottoRaja){

        cout <<"Talletettava summa on liian suuri, luoton kokonaismäärä ylitetty!" << endl << endl;
        return false;       // Ei saa mennä yli nollan
    }

    saldo = uusiLuottoSaldo;
    return true;


}

bool luottotili::withdraw(double withdrawAmount)
{

    // withdraw() tekee noston tililtä.
    // Negatiivisia nostoja ei voi tehdä. Esim. velanmaksun parametriksi ei voi antaa summaa -123.
    // Luottotilin saldo saa mennä negatiiviseksi, mutta ei alle luottorajan.
    // Palauttaa true/false sen mukaan onnistuiko talletus/nosto.


    if (withdrawAmount <= 0){

        cout <<"Nostettava summa on liian pieni!" << endl << endl;
        return false;
    }

    double uusiLuottoSaldo = saldo - withdrawAmount;
    if (uusiLuottoSaldo < -(luottoRaja)){

        cout <<"Nostettava summa on liian suuri, luottoraja ylitetty!" << endl << endl;
        return false; // Ei saa mennä alle luottorajan
    }

    saldo = uusiLuottoSaldo;
    return true;


}
