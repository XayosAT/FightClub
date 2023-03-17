//
// Created by Christoph on 14.03.2023.
//

#ifndef FIGHTCLUB_CHARACTER_H
#define FIGHTCLUB_CHARACTER_H
#include "Ability.h"
#include <string>
#include "Decision.h"
#include <iostream>
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

protected:
    string name;
    int health;
    Ability abilities[2];
    bool statusEffects[4];


private:
    void setAbilities(string ability1, int index);



};


#endif //FIGHTCLUB_CHARACTER_H
