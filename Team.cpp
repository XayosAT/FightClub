//
// Created by Christoph on 20.03.2023.
//

#include "Team.h"

Team::Team(Character* character1, Character* character2) {
    team[0] = character1;
    team[1] = character2;
}

Character* Team::getCharacter(int index) {
    return team[index];
}

Team::~Team() {
    cout << "Team destroyed" << endl;
}