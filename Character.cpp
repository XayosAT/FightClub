//
// Created by Christoph on 14.03.2023.
//

#include "Character.h"
#include "Decision.h"
#include <iostream>

Character::Character(string name, int health){
    this->name = name;
    this->health = health;
}

string Character::getName() const {
    return name;
}

Character::~Character() {
    cout << "Character " << name << " destroyed" << endl;
}

int Character::getHealth() {
    return health;
}

void Character::setHealth(int health) {
    this->health = health;
}

void Character::setAbility(Ability ability, int index) {
    abilities[index] = ability;
}

Ability Character::getAbility(int index) {
    return abilities[index];
}

