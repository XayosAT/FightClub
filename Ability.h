//
// Created by Christoph on 16.03.2023.
//

#ifndef FIGHTCLUB_ABILITY_H
#define FIGHTCLUB_ABILITY_H
#include <string>
#include <iostream>
using namespace std;

class Ability {
public:
    Ability();
    Ability(string name);
    virtual ~Ability();
    string getName();
private:
    string name;

};





#endif //FIGHTCLUB_ABILITY_H
