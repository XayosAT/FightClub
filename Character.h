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

protected:
    string name;
    int health;

private:



};


#endif //FIGHTCLUB_CHARACTER_H
