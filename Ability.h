//
// Created by Christoph on 16.03.2023.
//

#ifndef FIGHTCLUB_ABILITY_H
#define FIGHTCLUB_ABILITY_H
#include <string>
#include <iostream>
#include "Character.h"
using namespace std;

class Ability {
public:
    Ability(string name);
    virtual ~Ability();
    virtual void useAbility(Character *user, Character *target);
private:
    string name;
    void useSmash(Character *target);
    void useStab(Character *target);
    void useGrab(Character *target);
    void useBlock(Character *user);
    void useDodge(Character *user);
    bool blockedOrDodged(Character *target);
};



#endif //FIGHTCLUB_ABILITY_H
