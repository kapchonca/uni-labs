#ifndef CHEST
#define CHEST

#include <ncurses.h>

#include <fstream>
#include <ctime>
#include <vector>

class Chest{

private:

    std::vector<int> loot;

public:

    Chest();

    std::vector<int> returnLoot();

    void displayChest();

};

#endif //CHEST