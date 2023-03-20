//
// Created by Christoph on 14.03.2023.
//

#ifndef FIGHTCLUB_GAME_H
#define FIGHTCLUB_GAME_H
#include <vector>
#include "Decision.h"
#include <iostream>
#include "Ability.h"
#include <string>
#include "Character.h"
#include "Fight.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

class Game {

public:
    Game();
    virtual ~Game();
    void start();

private:
    vector<Character*> characters;
    bool validInputForAbility(string name);
    int getCharacterCount();
    void addCharacter();
    void printCharacters();
    Character* chosenCharacters[4];
    void chooseCharactersFor2v2();
    void chooseCharactersFor1v1();
    bool validInputForCharacter(string input);
    Character* chooseCharacter();
    void printWinsAndLosses();
};


#endif //FIGHTCLUB_GAME_H
