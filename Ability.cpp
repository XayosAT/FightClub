//
// Created by Christoph on 16.03.2023.
//

//possible Abilities: Smash, Stab, Grab, Block, Dodge

#include "Ability.h"
Ability::Ability() {
}

Ability::Ability(string name) {
    this->name = name;
}

string Ability::getName() {
    return name;
}

Ability::~Ability() {

}

/*
void Ability::useAbility(Character *user, Character *target) {
    if (name == "Smash") {
        useSmash(target);
    } else if (name == "Stab") {
        useStab(target);
    } else if (name == "Grab") {
        useGrab(target);
    } else if (name == "Block") {
        useBlock(user);
    } else if (name == "Dodge") {
        useDodge(user);
    }
    cout << "Ability used" << endl;
}

Ability::Ability(string name) {
    cout << "Ability created" << endl;
    this->name = name;
}

Ability::~Ability() {
    cout << "Ability destroyed" << endl;
}

void Ability::useSmash(Character *target) {
    cout << "Smash used" << endl;
    if (blockedOrDodged(target)) {
        return;
    }
    if (target->getStatusEffect(0) == 1) {
        target->setHealth(target->getHealth() - 20);
        return;
    }
    target->setHealth(target->getHealth() - 10);

}

void Ability::useStab(Character *target) {
    cout << "Stab used" << endl;
    if (blockedOrDodged(target)) {
        return;
    }
    if (target->getStatusEffect(0) == 1) {
        target->setHealth(target->getHealth() - 6);
    } else{
        target->setHealth(target->getHealth() - 3);
    }
    target->setStatusEffect(1, 3);
}

void Ability::useGrab(Character *target) {
    cout << "Grab used" << endl;
    if (blockedOrDodged(target)) {
        return;
    }
    target->setStatusEffect(0, 1);
}

void Ability::useBlock(Character *user) {
    cout << "Block used" << endl;
    user->setStatusEffect(3, 1);
}

void Ability::useDodge(Character *user) {
    cout << "Dodge used" << endl;
    user->setStatusEffect(2, 1);
}

bool Ability::blockedOrDodged(Character *target) {
    if(target->getStatusEffect(3) == 1) {
        cout << "Blocked" << endl;
        return true;
    }
    if(target->getStatusEffect(2) == 1) {
        int r = rand() % 2;
        if(r == 0) {
            cout << "Dodge successful" << endl;
            return true;
        }
    }
    return false;
}
*/