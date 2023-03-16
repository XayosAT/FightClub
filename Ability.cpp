//
// Created by Christoph on 16.03.2023.
//

#include "Ability.h"

virtual void Ability::useAbility() {
    std::cout << "Ability used" << std::endl;
}



void Smash::useAbility() {
    std::cout << "Smash used" << std::endl;
}