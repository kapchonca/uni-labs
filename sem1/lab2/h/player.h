#ifndef PLAYER
#define PLAYER

#include <ncurses.h>

#include <string>
#include <unordered_map>

class Player;

class Inventory {

private:

    std::unordered_map<int, int> loot;

public:

    void showInventory(Player* player);
    
    void addItem(int item);

    void reduceItemCount(int item);

    std::unordered_map<int, int> getLoot();

    Inventory();
};


class Player {

protected:

    int healthMax = 100;
    int healthPoints = 100;

    int attackPoints = 10;

    int level = 1;
    int xp = 0;
    int xpLimit = 50;

    Inventory* playerInventory;

public:

    Player();

    ~Player() {delete playerInventory;};

    void levelUp();

    void addExp(int xp);

    void decreaseHealth(int attackPoints);

    void increaseHealth(int healPoints);

    int getHealthPoints();

    int getHealthMax();

    int getAttackPoints();

    int getXpLimit();

    int getLevel();

    int getXp();

    Inventory* getInventory();

    void setHealthPoints(int healthPoints);

    void setHealthMax(int newHealth);

    void setAttackPoints(int attackPoints);
    
};



#endif //PLAYER
