#include "italianchef.h"
#include <iostream>

using namespace std;

ItalianChef::ItalianChef(string chefName):Chef(chefName), flour(0), water(0) {

    // Viittaus yläluokkaan Chef YHDELLÄ kaksoipisteellä ":Chef"
    // Asetetaan samalla Chef-luokan jauhojen ja veden määrä tässä konstruktorissa nollaksi, koska teemme pitsaa myöhemmin annetuilla arvoilla

    cout << "ItalianChef " << chefName << " konstruktori" << endl;
}

ItalianChef::~ItalianChef()
{
    // Destruktorin muodostus squiggly linella ~

    cout << "ItalianChef " << chefName << " destruktori" << endl;
}

bool ItalianChef::askSecret(string triedPassword,int jauho,int vesi) {

    // The string::compare() function in C++ is used to compare a string or the part of string with another string or substring

    if ((triedPassword.compare(password)) == 0){
        cout << endl << "Password is ok!" << endl << endl;
        flour = jauho;
        water = vesi;
        makepizza();
        return true;
    }
    else {
        cout << endl << "Wrong password!" << endl;
        return false;
    }

}

int ItalianChef::makepizza(){

    // The std::min() is used to find the minimum element among the given elements.
    // Tarkistetaan min-funktiolla, että molempien jauhojen sekä veden määrästä tulee 5 jaettuna tulokseksi 1, jolloin se muodostaa kokonaisen pitsan

    int pitsojenMaara = min(flour/5,water/5);
    cout << "ItalianChef " << chefName << " with " << flour << " flour and " << water << " water can make " << pitsojenMaara << " pizzas" << endl;
    return pitsojenMaara;


}
