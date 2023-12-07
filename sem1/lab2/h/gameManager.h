#ifndef GAMEMANAGER
#define GAMEMANAGER
 
#include "../h/map.h"
#include "../h/stateBattle.h"
#include "../h/chest.h"
#include "../h/items.h"

class GameManager {

protected:

    int loopCounter = 0;
    
    bool s_GameIsOver = false;

    Player* player;

    StateBattle* battle;

    Monster* monster;

    Boss* boss;

    Map* map;

public:

    GameManager();

    ~GameManager();

    void StateHandler();

    std::string getRandomLine();

    void loadInterface(Player* player, Monster* monster);

    void printSprite(Monster* monster);

    bool gameIsOver();

    void setGameOver();

    void printGameOver();

    void increaseLoopCount();

    void nextLoop();

    void stateInventory(Player* player);

    void recieveLoot(Player* player, Monster* monster);

    Monster* getRandomMonster(Player* player);

    void generateBoss(Player* player, int loopCounter);

    void windowInitializer();

    void generateMap();

};

#endif //GAMEMANAGER