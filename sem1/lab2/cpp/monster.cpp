#include "../h/monster.h"

Monster::Monster(Player* player) {

    srand(time(0));

    baseModifier = 1 + (rand() % 5) / 10.;

    healthMax = player->getAttackPoints() * 70 * baseModifier + rand() % 100;
    healthPoints = healthMax;

    attackPoints = player->getHealthMax() / 20 * baseModifier + rand() % 4;

    monsterTime = 40 * baseModifier;

    datasetOffset = 0;

}

int Monster::getTime() {
    return monsterTime;
}

int Monster::getHealthMax() {
    return healthMax;
}

int Monster::getHealthPoints() {
    return healthPoints;
}

int Monster::getAttackPoints() {
    return attackPoints;
}

int Monster::getDatasetOffset() {
    return datasetOffset;
}

bool Monster::getRandomizeActive() {
    return randomizeLineActive;
}

std::string Monster::getName() {
    return name;
}

std::string Monster::getSpriteInd() {
    return spriteInd;
}

void Monster::decreaseHealth(int attack) {
    healthPoints-=attack;
}

void Monster::setHealthPoints(int healthPoints) {
    this->healthPoints = healthPoints;
}

Boss::Boss(Player* player, int loopNumber) : Monster(player) {

    name = "LAB 2";
    spriteInd = "4";

    healthMax = 500 + loopNumber * loopNumber * 200;
    healthPoints = healthMax;

    attackPoints = 10 + loopNumber * loopNumber * 4;
    
    monsterTime = 60;

    randomizeLineActive = true;
    
    datasetOffset = 0;

}

Dragon::Dragon(Player* player) : Monster(player) {

    datasetOffset = 50;
    name = "DRAGON";
    spriteInd = "1";

}

Skeleton::Skeleton(Player* player) : Monster(player) {

    datasetOffset = 150;
    name = "SKELETON";
    spriteInd = "2";

}

Vampire::Vampire(Player* player) : Monster(player) {

    datasetOffset = 100;
    name = "VAMPIRE";
    spriteInd = "3";

}