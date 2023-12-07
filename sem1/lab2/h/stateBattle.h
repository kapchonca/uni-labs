#ifndef STATEBATTLE
#define STATEBATTLE

#include <cstring>

#include "../h/timer.h"
#include "../h/text.h"

class StateBattle {

private:

    Timer timer;
    Text text;

public:

    void loadInterface(Player* player, Monster* monster);

    void printSprite(Monster* monster);
    
    bool readySetFight(Player* player, Monster* monster);

    void displaySentence();
};


#endif //STATEBATTLE