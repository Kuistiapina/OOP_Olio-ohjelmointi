#include "notifikaattori.h"
#include <iostream>

using namespace std;

Notifikaattori::Notifikaattori()
{

}

void Notifikaattori::lisaa(Seuraaja *uusiSeuraaja)
{
    // A->next = B
    uusiSeuraaja->next = seuraajat;                     // Kiilataan uusi solmu listan alkuun. uusiSeuraaja osoittaa siihen, mikä oli ennen listan alku (seuraajat)
    // alku = A                                         // Jos lista oli tyhjä (seuraajat == nullptr), next jää nullptriksi
    // [uusiSeuraaja] -> [S1] -> [S2] -> [S3] -> nullptr
    seuraajat = uusiSeuraaja;                           // Siirretään listan "alku" osoittamaan tähän uuteen seuraajaan. Nyt uusi solmu on ensimmäisenä listassa.
    // seuraajat  →  [uusiSeuraaja]  →  [S1]  →  [S2]  →  [S3]  →  nullptr

}

void Notifikaattori::poista(Seuraaja *poistaSeuraaja)
{
    Seuraaja *alku = nullptr;                           // Edellinen osoitin eli listassa ennen poistettavaa
    Seuraaja *nykyinenListalla = seuraajat;             // Nykyinen osoitin eli se, joka mahdollisesti poistetaan. Aloitetaan listan alusta.

    while (nykyinenListalla != nullptr)                 // Loopataan listaa läpi
    {
        if (nykyinenListalla == poistaSeuraaja)         // Poistettava löydetty
        {
            if (alku == nullptr)                        // Jos alku = nullptr, nykyinenListalla on listan ensimmäinen eli poistettava
            {
                seuraajat = nykyinenListalla->next;     // Siirretään listan alku seuraavaan solmuun eli hypätään ensimmäinen (poistettava) yli
            }
            else                                        // Listan poistettava on keskellä tai lopussa eli käytännössä alku != nullptr
            {
                alku->next = nykyinenListalla->next;    // Laitetaan alku-solmun (edeltäjän) next osoittamaan siihen solmuun, joka tulee poistettavan solmun jälkeen.
            }

            delete nykyinenListalla;                    // Poistettava irroitetaan listalta ja poistetaan muistista
            return;                                     // Poistaminen valmis, palataan funktiosta ulos
        }

        alku = nykyinenListalla;                        // Tehdään poiston jälkeen nykyisestä listan ensimmäinen
        nykyinenListalla = nykyinenListalla->next;      // Siirrytään listalla seuraavaan
    }

}

void Notifikaattori::tulosta()
{
    Seuraaja *alku = seuraajat;

    if (alku == nullptr){

        cout << "Seuraajien lista on tyhjä!" << endl;
        return;
    }
    while (alku != nullptr){
        cout << "Listalla nyt " <<  alku->getNimi() << endl;
        alku = alku->next;        // tehdään silmukassa jotain oliolle alku = alku->next
        if (alku != nullptr) {
            cout << "Listassa seuraava: " << alku->getNimi() << endl;
        }
        else {
            cout << "Lista loppui!" << endl;
        }
    };
}

void Notifikaattori::postita(string v)
{
    Seuraaja *alku = seuraajat;

    while (alku != nullptr){
        alku->paivitys(v);
        alku = alku->next;
    }

}
