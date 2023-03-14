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

