#include "../h/chest.h"

Chest::Chest() {

    srand(time(0));
    
    loot.push_back(rand() % 4 + 1);
    
}

std::vector<int> Chest::returnLoot() {
    return loot;
}

void Chest::displayChest() {

    mvprintw(10, 120, "YOU FOUND A CHEST");

    
    std::string address = "../sprites/chest";
    std::ifstream file(address);

    std::string sprite[18];

    for (int i = 18; i > 0; i--) {
        getline(file, sprite[18 - i]);
    }

    for (int i = 20; i < 38; i++) {
        mvprintw(i, 90, "%s", sprite[i-20].c_str());
    }
}