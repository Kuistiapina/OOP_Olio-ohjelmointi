#include "seuraaja.h"
#include "notifikaattori.h"
#include <iostream>

using namespace std;

int main()
{
    Seuraaja *A = new Seuraaja("Arttu");
    // Smartpointerilla näin: unique_ptr<Seuraaja> A(new Seuraaja("Arttu")); Ei tarvitse erikseen deleteä!
    Seuraaja *B = new Seuraaja("Berttu");
    Seuraaja *C = new Seuraaja("Certtu");
    Seuraaja *D = new Seuraaja("Daavidin Serkku");
    Seuraaja *E = new Seuraaja("Antoine Dolohov");

    //Static-muuttujilla:

    // Seuraaja D("Derp");
    // Seuraaja E("Eerp");

    Notifikaattori *N = new Notifikaattori();

    N->lisaa(A);
    N->lisaa(B);
    N->lisaa(C);
    N->lisaa(D);
    N->lisaa(E);

    cout << "Seuraajien lista: " << endl;
    N->tulosta();

    N->postita("perunamuussia tarjolla koulun ruokalassa!");

    N->poista(B);

    cout << "Seuraajien lista poiston tapahduttua: " << endl;
    N->tulosta();

    N->postita("perunamuussi pian loppumassa!");

    N->poista(C);

    cout << "Seuraajien lista toisen poiston tapahduttua: " << endl;

    N->tulosta();

    //N->postita("perunamuussi loppui, kiitokset osallistujille!");

    N->poista(E);

    cout << "Seuraajien lista toisen poiston tapahduttua: " << endl;

    N->tulosta();

    //A->next = B;
    //B->next = C;

    // Staticille next alla

    // D.next = &E;

    delete N;

    return 0;
}
