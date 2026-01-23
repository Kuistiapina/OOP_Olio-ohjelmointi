#include <iostream>
#include "chef.h"
#include "italianchef.h"


using namespace std;

int main()
{
    Chef chef1("Seppo");
    chef1.makeSalad(16);
    chef1.makeSoup(22);

    cout << endl << "--------------------------------------------------------------------" << endl << endl;

    Chef chef2("Marco");
    chef2.makeSalad(1900);
    chef2.makeSoup(10000);

    cout << endl << "--------------------------------------------------------------------" << endl << endl;

    ItalianChef chef3("Santtu");
    chef3.askSecret("pizza",10000,10000);

    cout << endl << "--------------------------------------------------------------------" << endl << endl;

    ItalianChef chef4("Pasi");
    chef4.askSecret("salasana",10,10);

    cout << endl << "--------------------------------------------------------------------" << endl << endl;

    return 0;
}
