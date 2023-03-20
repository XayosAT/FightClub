//
// Created by Christoph on 18.03.2023.
//

#include "Fight.h"

Fight::Fight(Character* character1, Character* character2) {
    characters[0] = character1;
    characters[1] = character2;
    resolveRound();
}

void Fight::resolveRound() {
    while (characters[0]->getHealth() > 0 && characters[1]->getHealth() > 0) {
        resolvePlayerTurn(characters[0], characters[1]);
        cout << endl;
        resolvePlayerTurn(characters[1], characters[0]);
        cout << endl;
        resolveStatusEffects();
        cout << characters[0]->getName() << " has " << characters[0]->getHealth() << " health left" << endl;
        cout << characters[1]->getName() << " has " << characters[1]->getHealth() << " health left" << endl << endl;
//        cout << characters[0]->getName() << " has " << characters[0]->getStatusEffect(0) << " status effect 0" << endl;
//        cout << characters[0]->getName() << " has " << characters[0]->getStatusEffect(1) << " status effect 1" << endl;
//        cout << characters[0]->getName() << " has " << characters[0]->getStatusEffect(2) << " status effect 2" << endl;
//        cout << characters[0]->getName() << " has " << characters[0]->getStatusEffect(3) << " status effect 3" << endl;
//        cout << characters[1]->getName() << " has " << characters[1]->getStatusEffect(0) << " status effect 0" << endl;
//        cout << characters[1]->getName() << " has " << characters[1]->getStatusEffect(1) << " status effect 1" << endl;
//        cout << characters[1]->getName() << " has " << characters[1]->getStatusEffect(2) << " status effect 2" << endl;
//        cout << characters[1]->getName() << " has " << characters[1]->getStatusEffect(3) << " status effect 3" << endl;

    }
    if (characters[0]->getHealth() > 0) {
        cout << characters[0]->getName() << " wins!" << endl;
        characters[0]->setWins(characters[0]->getWins() + 1);
        characters[1]->setLosses(characters[1]->getLosses() + 1);
    } else {
        cout << characters[1]->getName() << " wins!" << endl;
        characters[1]->setWins(characters[1]->getWins() + 1);
        characters[0]->setLosses(characters[0]->getLosses() + 1);
    }
}

void Fight::resolvePlayerTurn(Character *player, Character *opponent) {
    cout << player->getName() << " is your turn" << endl;
    cout << "Choose an ability" << endl;
    cout << "1: " << player->getAbility(0).getName() << endl;
    cout << "2: " << player->getAbility(1).getName() << endl;
    int input;
    cin >> input;
    while (input != 1 && input != 2) {
        cout << "Invalid input, try again" << endl;
        cin >> input;
    }
    if (input == 1) {
        useAbility(player->getAbility(0).getName(), player, opponent);
    } else {
        useAbility(player->getAbility(1).getName(), player, opponent);
    }
}

void Fight::useAbility(string abilityName, Character *user, Character *target) {
    if (abilityName == "Smash") {
        useSmash(target);
    } else if (abilityName == "Stab") {
        useStab(target);
    } else if (abilityName == "Grab") {
        useGrab(target);
    } else if (abilityName == "Block") {
        useBlock(user);
    } else if (abilityName == "Dodge") {
        useDodge(user);
    }
}

void Fight::useSmash(Character *target) {
    cout << "Smash used" << endl;
    if (blockedOrDodged(target)) {
        return;
    }
    if (target->getStatusEffect(0) == 1) {
        target->setHealth(target->getHealth() - 20);
        cout << target->getName() << " suffered 20 damage" << endl;
        target->setStatusEffect(0, 0);
        return;
    }
    target->setHealth(target->getHealth() - 10);
    cout << target->getName() << " suffered 10 damage" << endl;

}

void Fight::useStab(Character *target) {
    cout << "Stab used" << endl;
    if (blockedOrDodged(target)) {
        return;
    }
    if (target->getStatusEffect(0) == 1) {
        target->setHealth(target->getHealth() - 6);
        cout << target->getName() << " suffered 6 damage" << endl;
        target->setStatusEffect(0, 0);
    } else{
        target->setHealth(target->getHealth() - 3);
        cout << target->getName() << " suffered 3 damage" << endl;
    }
    target->setStatusEffect(1, 3);
}

void Fight::useGrab(Character *target) {
    cout << "Grab used" << endl;
    if (blockedOrDodged(target)) {
        return;
    }
    target->setStatusEffect(0, 1);
}

void Fight::useBlock(Character *user) {
    cout << "Block used" << endl;
    user->setStatusEffect(3, 1);
}

void Fight::useDodge(Character *user) {
    cout << "Dodge used" << endl;
    user->setStatusEffect(2, 1);
}

bool Fight::blockedOrDodged(Character *target) {
    if(target->getStatusEffect(3) == 1) {
        cout << "Blocked" << endl;
        target->setStatusEffect(3, 0);
        return true;
    }
    if(target->getStatusEffect(2) == 1) {
        int r = rand() % 2;
        if(r == 0) {
            cout << "Dodge successful" << endl;
            target->setStatusEffect(2, 0);
            return true;
        }
        target->setStatusEffect(2, 0);
    }
    return false;
}

void Fight::resolveStatusEffects() {

    for (int i = 0; i < 2; ++i) {
        if (characters[i]->getStatusEffect(1) > 0) {
            characters[i]->setHealth(characters[i]->getHealth() - 3);
            cout << characters[i]->getName() << " suffered a 3 bleeding damage" << endl;
            characters[i]->setStatusEffect(1, characters[i]->getStatusEffect(1) - 1);

        }
    }
}




Fight::~Fight() {
    cout << "Fight destroyed" << endl;
}