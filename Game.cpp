//
// Created by Christoph on 14.03.2023.
//

#include "Game.h"


Game::Game() {

    ::srand(time(NULL));
    Character *preCreatedCharacter1 = new Character("Joe", 100, "Dodge", "Stab" );
    Character *preCreatedCharacter2 = new Character("Bob", 100, "Smash", "Grab");
    characters.push_back(preCreatedCharacter1);
    characters.push_back(preCreatedCharacter2);
}

Game::~Game() {
    for (int i = 0; i < characters.size(); ++i) {
        delete characters[i];
    }
    cout << "Game destroyed" << endl;
}