//
// Created by Christoph on 16.03.2023.
//

#ifndef FIGHTCLUB_ABILITY_H
#define FIGHTCLUB_ABILITY_H


class Ability {
public:
    Ability();
    virtual ~Ability();
    virtual void useAbility();
};

class Smash : public Ability {
public:
    Smash();
    ~Smash();
    void useAbility() override;
};

#endif //FIGHTCLUB_ABILITY_H
