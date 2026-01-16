#include <iostream>
#include <cstdlib> //Random-kirjasto
#include <ctime> //time


using namespace std;

int game(int maxnum);

int main()
{
    cout << "Anna arvottujen numeroiden maksimiluku: ";
    int maxnum;
    cin >> maxnum;
    int tulos = game(maxnum);
    cout << "Arvauksia oli: "<<tulos<<endl;


    return 0;
}

int game(int maxnum){
    srand(time(NULL)); // Asetetaan siemenluku nykyhetken mukaan
    int arvottu = rand() % maxnum + 1; // Arvotaan satunnainen luku väliltä 1–käyttäjän syöte
    int arvaus; // Käyttäjän syöte
    int arvaustenMaara = 0;

    do {
        cout << "Arvaa luku arvoasteikolta 1-" <<maxnum << ": ";
        cin >> arvaus;

        if (arvaus < arvottu) {
            cout << "Luku on suurempi kuin arvauksesi!" << endl;
        } else if (arvaus > arvottu) {
            cout << "Luku on pienempi kuin arvauksesi!" << endl;
        } else {
            cout << "Oikea vastaus!" << endl;
        }
        arvaustenMaara++;
    } while (arvaus != arvottu);
    return arvaustenMaara;
}
