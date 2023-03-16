//
// Created by Christoph on 14.03.2023.
//

#ifndef FIGHTCLUB_GAME_H
#define FIGHTCLUB_GAME_H
#include "Character.h"
#include <vector>
#include "Decision.h"
#include <iostream>
using namespace std;

class Game {

public:
    Game();
    virtual ~Game();
private:
    vector<Character> characters;
};


#endif //FIGHTCLUB_GAME_H
