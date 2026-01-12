#include <iostream>
#include <cstdlib> //Random-kirjasto
#include <ctime> //time


using namespace std;

int game(int maxnum);

int main()
{
    srand(time(NULL)); // Asetetaan siemenluku nykyhetken mukaan
    int arvottu = rand() % 20 + 1; // Arvotaan satunnainen luku väliltä 1–20
    int arvaus; // Käyttäjän syöte

    do {
        cout << "Arvaa luku arvoasteikolta 1-20: ";
        cin >> arvaus;

        if (arvaus < arvottu) {
            cout << "Luku on suurempi kuin arvauksesi!" << endl;
        } else if (arvaus > arvottu) {
            cout << "Luku on pienempi kuin arvauksesi!" << endl;
        } else {
            cout << "Oikea vastaus!" << endl;
        }
    } while (arvaus != arvottu);

    return 0;
}
