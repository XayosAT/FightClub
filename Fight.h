//
// Created by Christoph on 18.03.2023.
//

#ifndef FIGHTCLUB_FIGHT_H
#define FIGHTCLUB_FIGHT_H
#include "Character.h"
#include "Ability.h"

class Fight {

public:
    Fight(Character* character1, Character* character2);
    virtual ~Fight();
protected:
    Character* characters[2];
    void resolveRound();
    void resolvePlayerTurn(Character* player, Character* opponent);
    void resolveStatusEffects();
    void useAbility(string abilityName, Character* user, Character* target);
    void useSmash(Character* target);
    void useStab(Character* target);
    void useGrab(Character* target);
    void useBlock(Character* user);
    void useDodge(Character* user);
    bool blockedOrDodged(Character* target);
};

#endif //FIGHTCLUB_FIGHT_H
