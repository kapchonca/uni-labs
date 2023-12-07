#ifndef MONSTER
#define MONSTER

#include <ctime>

#include "../h/player.h"


class Monster {

protected:

    int monsterTime;

    int healthMax;
    int healthPoints;

    int attackPoints;

    std::string name;
    std::string spriteInd;

    float baseModifier;

    bool randomizeLineActive = false;

    int datasetOffset;

public:

    Monster(Player* player);

    int getTime();

    int getHealthMax();

    int getHealthPoints();

    int getAttackPoints();

    int getDatasetOffset();

    bool getRandomizeActive();

    std::string getName();

    std::string getSpriteInd();

    void decreaseHealth(int attack);

    void setHealthPoints(int healthPoints);
    
};

class Boss : public Monster {

public:

    Boss(Player* player, int loopNumber);
};

class Dragon : public Monster {

public:

    Dragon(Player* player);

};

class Skeleton : public Monster {

public:

    Skeleton(Player* player);

};

class Vampire : public Monster {

public:

    Vampire(Player* player);
};

#endif // MONSTER
