//
// Created by Christoph on 14.03.2023.
//

#ifndef FIGHTCLUB_CHARACTER_H
#define FIGHTCLUB_CHARACTER_H
#include <string>
#include "Decision.h"
#include <iostream>
#include "Ability.h"
using namespace std;

//status effects: 0 = grabbed, 1 = bleeding, 2 = dodging, 3 = blocking

class Character {

public:
    Character(string name, int health, string ability1, string ability2);
    virtual ~Character();
    string getName() const;
    int getHealth();
    void setHealth(int health);
    Ability getAbility(int index);
    void setStatusEffect(int index, int value);
    int getStatusEffect(int index);
    int getWins();
    void setWins(int wins);
    int getLosses();
    void setLosses(int losses);

protected:
    string name;
    int health;
    Ability abilities[2];
    int statusEffects[4];
    int wins = 0;
    int losses = 0;


private:
    void setAbilities(string ability1, int index);



};


#endif //FIGHTCLUB_CHARACTER_H
