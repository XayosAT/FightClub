//
// Created by Christoph on 14.03.2023.
//

#include "Character.h"


Character::Character(string name, int health, string ability1, string ability2) {
    this->name = name;
    this->health = health;
    abilities[0] = Ability(ability1);
    abilities[1] = Ability(ability2);
    for (int i = 0; i < 4; i++) {
        statusEffects[i] = 0;
    }

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

Ability Character::getAbility(int index) {
    return abilities[index];
}

void Character::setStatusEffect(int index, int value) {
    statusEffects[index] = value;
}

int Character::getStatusEffect(int index) {
    return statusEffects[index];
}

int Character::getWins() {
    return wins;
}

void Character::setWins(int wins) {
    this->wins = wins;
}

int Character::getLosses() {
    return losses;
}

void Character::setLosses(int losses) {
    this->losses = losses;
}