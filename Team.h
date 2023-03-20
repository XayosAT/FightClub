//
// Created by Christoph on 20.03.2023.
//

#ifndef FIGHTCLUB_TEAM_H
#define FIGHTCLUB_TEAM_H
#include "Character.h"
#include <vector>

class Team {

    public:
        Team(Character* character1, Character* character2);
        virtual ~Team();
        Character* getCharacter(int index);
    private:
        Character* team[2];


};


#endif //FIGHTCLUB_TEAM_H
