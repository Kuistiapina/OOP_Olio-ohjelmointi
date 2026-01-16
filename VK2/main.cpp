#include <iostream>
#include <cstdlib> //Random-kirjasto
#include <ctime> //time
#include "game.h"


using namespace std;

int main()
{
    Game ArvausPeli(10);
    ArvausPeli.play();

    return 0;
}
