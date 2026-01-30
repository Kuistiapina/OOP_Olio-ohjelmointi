#include "pankkitili.h"
#include <iostream>

using namespace std;

pankkitili::pankkitili(string tilinOmistaja) {

    omistaja = tilinOmistaja;
    cout << "Pankkitili luotu " << omistaja << ":lle" << endl;
}

double pankkitili::getBalance()
{

    return saldo;

}

bool pankkitili::deposit(double depositAmount)
{

// deposit() tekee talletuksen tilille.
// Negatiivisia talletuksia ei voi tehdä!
// Palauttaa true/false sen mukaan onnistuiko talletus/nosto.


    if (depositAmount <= 0){

        cout <<"Talletettava summa on liian pieni!" << endl << endl;
        return false;
    }

    else {
        saldo = saldo + depositAmount;
        cout << omistaja << ":n pankkitilille " << depositAmount << " talletus suoritettu" << endl << endl;
        return true;

    }



}

bool pankkitili::withdraw(double withdrawAmount)
{

// withdraw() noston tililtä.
// Negatiivisia nostoja ei voi tehdä!
// Pankkitilin saldo ei saa mennä negatiiviseksi, eli enempää ei voi nostaa kun mitä saldo on!
// Palauttaa true/false sen mukaan onnistuiko talletus/nosto.


    if (withdrawAmount <= 0){

        cout <<"Nostettava summa on liian pieni!" << endl << endl;
        return false;

    }
    else if (saldo - withdrawAmount < 0){

        cout <<"Nostettava summa on liian suuri, tilin saldo ei voi mennä miinukselle!" << endl << endl;
        return false; // Ei nostoa ettei mene miinukselle
    }
    else {

        saldo = saldo - withdrawAmount;
        cout << omistaja << ":n pankkitililtä" << withdrawAmount << " nosto suoritettu" << endl << endl;
        return true;

    }

}
