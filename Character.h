//
// Created by Christoph on 14.03.2023.
//

#ifndef FIGHTCLUB_CHARACTER_H
#define FIGHTCLUB_CHARACTER_H


class Character {

public:
    Character(string name, int health);
    virtual ~Character();
    string getName() const;
    int getHealth();
    void setHealth(int health);
    setAbility(Ability ability, int index);
    Ability getAbility(int index);

protected:
    string name;
    int health;
    Ability[2] abilities;

private:



};


#endif //FIGHTCLUB_CHARACTER_H
