//
// Created by Christoph on 14.03.2023.
//

#include "Game.h"


Game::Game() {

    ::srand(time(NULL));
    Character *preCreatedCharacter1 = new Character("Joe", 100, "Dodge", "Stab" );
    Character *preCreatedCharacter2 = new Character("Bob", 100, "Smash","Grab");
    characters.push_back(preCreatedCharacter1);
    characters.push_back(preCreatedCharacter2);

}

Game::~Game() {
    for (int i = 0; i < characters.size(); ++i) {
        delete characters[i];
    }
    cout << "Game destroyed" << endl;
}

void Game::addCharacter() {
    string name;
    int health;
    string ability1;
    string ability2;
    cout << "Enter name: " << endl;
    cin >> name;
    cout << "Available abilities: 1:Smash, 2:Stab, 3:Grab, 4:Block, 5:Dodge" << endl;
    cout << "Enter ability 1: " << endl;
    cin >> ability1;
    while (!validInputForAbility(ability1)) {
        cout << "Invalid input, try again" << endl;
        cin >> ability1;
    }
    cout << "Enter ability 2: " << endl;
    cin >> ability2;
    while (!validInputForAbility(ability2)) {
        cout << "Invalid input, try again" << endl;
        cin >> ability2;
    }
    while (ability1 == ability2) {
        cout << "Abilities must be different, try again" << endl;
        cin >> ability2;
    }
    Character *character = new Character(name, 100, ability1, ability2);
    characters.push_back(character);
}

bool Game::validInputForAbility(string name) {
    if (name == "Smash" || name == "Stab" || name == "Grab" || name == "Block" || name == "Dodge") {
        return true;
    }
    return false;
}

void Game::printCharacters() {
    for (int i = 0; i < characters.size(); ++i) {
        cout << (i+1) << ": "<< characters[i]->getName() << endl;
    }
}

int Game::getCharacterCount() {
    return characters.size();
}

void Game::start() {
    cout << "How many players?" << endl;
    cout << "press 1 for 1v1, 2 for 2v2" << endl;
    int playerCount;
    cin >> playerCount;
    while (playerCount != 1 && playerCount != 2) {
        cout << "Invalid input, try again" << endl;
        cin >> playerCount;
    }
    if (playerCount == 2) {
        chooseCharactersFor2v2();

    } else {
        chooseCharactersFor1v1();
        Fight(chosenCharacters[0], chosenCharacters[1]);
    }
    cout << "Show wins and losses?" << endl;
    cout << "press 1 for yes, 2 for no" << endl;
    char input;
    cin >> input;
    while (input != '1' && input != '2') {
        cout << "Invalid input, try again" << endl;
        cin >> input;
    }
    if (input == '1') {
        printWinsAndLosses();
    }

}

void Game::chooseCharactersFor1v1() {


    cout << "Player 1, choose your character" << endl;
    chosenCharacters[0] = chooseCharacter();
    cout << "Player 2, choose your character" << endl;
    chosenCharacters[1] = chooseCharacter();

    while (chosenCharacters[0] == chosenCharacters[1]) {
        cout << "You can't choose the same character, try again" << endl;
        chosenCharacters[1] = chooseCharacter();
    }

}

void Game::chooseCharactersFor2v2() {
    cout << "Player 1, choose your character" << endl;
    chosenCharacters[0] = chooseCharacter();
    cout << "Player 2, choose your character" << endl;
    chosenCharacters[1] = chooseCharacter();
    while (chosenCharacters[0] == chosenCharacters[1]){
        cout << "You can't choose the same character, try again" << endl;
        chosenCharacters[1] = chooseCharacter();
    }
    cout << "Player 3, choose your character" << endl;
    chosenCharacters[2] = chooseCharacter();
    while (chosenCharacters[0] == chosenCharacters[2] || chosenCharacters[1] == chosenCharacters[2]){
        cout << "You can't choose the same character, try again" << endl;
        chosenCharacters[2] = chooseCharacter();
    }
    cout << "Player 4, choose your character" << endl;
    chosenCharacters[3] = chooseCharacter();
    while (chosenCharacters[0] == chosenCharacters[3] || chosenCharacters[1] == chosenCharacters[3] || chosenCharacters[2] == chosenCharacters[3]){
        cout << "You can't choose the same character, try again" << endl;
        chosenCharacters[3] = chooseCharacter();
    }

}

Character* Game::chooseCharacter() {
    printCharacters();
    cout << "Enter number of character or 0 if you want to create a new one" << endl;
    string input;
    cin >> input;
    while (!validInputForCharacter(input)) {
        cout << "Invalid input, try again" << endl;
        cin >> input;
    }
    if (input == "0") {
        addCharacter();
        return characters[characters.size()-1];
    } else {
        return characters[stoi(input)-1];
    }
}

bool Game::validInputForCharacter(string input) {
    if (input == "0") {
        return true;
    }
    if (stoi(input) > 0 && stoi(input) <= characters.size()) {
        return true;
    }
    return false;
}

void Game::printWinsAndLosses() {
    for (int i = 0; i < characters.size(); ++i) {
        cout << characters[i]->getName() << " has " << characters[i]->getWins() << " wins and " << characters[i]->getLosses() << " losses" << endl;
    }
}