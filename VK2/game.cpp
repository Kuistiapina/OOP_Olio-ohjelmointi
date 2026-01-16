#include "game.h"
#include <iostream>
#include <cstdlib> //Random-kirjasto
#include <ctime> //time

using namespace std;

Game::Game(int maxnum) {

    maxNumber = maxnum;
    srand(time(NULL)); // Asetetaan siemenluku nykyhetken mukaan
    randomNumber = rand() % maxNumber + 1; // Arvotaan satunnainen luku väliltä 1–käyttäjän syöte
}

 void Game::play(){


    do {
        cout << "Arvaa luku arvoasteikolta 1-" <<maxNumber << ": ";
        cin >> playerGuess;

        if (playerGuess < randomNumber) {
            cout << "Luku on suurempi kuin arvauksesi!" << endl;
        } else if (playerGuess > randomNumber) {
            cout << "Luku on pienempi kuin arvauksesi!" << endl;
        } else {
            cout << "Oikea vastaus!" << endl;
        }
        numOfGuesses++;
    } while (playerGuess != randomNumber);
    printGameResult();
    //return numOfGuesses;
}

 void Game::printGameResult(){
     cout << "Arvauksesi oli oikein! Arvauksia oli: "<<numOfGuesses<<endl;
 }

 Game::~Game(){

    cout << "GAME DESTRUCTOR: Object cleared from stack memory" <<endl;
 }
