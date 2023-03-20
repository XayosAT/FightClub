//
// Created by Christoph on 14.03.2023.
//
#include "Game.h"
#include <iostream>
#include "Ability.h"


int main() {

    Game game;
    bool run = true;

    while (run){

        cout << "Welcome to Fight Club!" << endl;
        game.start();
        cout << "Do you want to play again? (y/n)" << endl;
        char input;
        cin >> input;
        while (input != 'y' && input != 'n') {
            cout << "Invalid input, try again" << endl;
            cin >> input;
        }
        if (input == 'n') {
            run = false;
        }
    }

    return 0;
}