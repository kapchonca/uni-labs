#include "../h/player.h"

Player::Player() {
    playerInventory = new Inventory;
}

void Player::decreaseHealth(int attackPoints) {
    healthPoints -= attackPoints;
}

void Player::increaseHealth(int healPoints) {
    healthPoints += healPoints;
    if (healthPoints > healthMax) {
        healthPoints = healthMax;
    }
}

int Player::getHealthPoints() {
    return healthPoints;
}

int Player::getHealthMax() {
    return healthMax;
}

int Player::getAttackPoints() {
    return attackPoints;
}

int Player::getXpLimit() {
    return xpLimit;
}

int Player::getLevel() {
    return level;
}

int Player::getXp() {
    return xp;
}

Inventory* Player::getInventory() {
    return playerInventory;
}

void Player::setHealthPoints(int healthPoints) {
    this->healthPoints = healthPoints;
}

void Player::addExp(int xp) {
    this->xp += xp;
}

void Player::levelUp() {

    if (xp > xpLimit - 1) {

        xp-=xpLimit;
        xpLimit*=1.4;
        level+=1;

        healthMax*=1.2;
        attackPoints*=1.2;
    }

}

void Player::setHealthMax(int newHealth) {
    this->healthMax = newHealth;
}

void Player::setAttackPoints(int attackPoints) {
    this->attackPoints = attackPoints;
}


Inventory::Inventory() {
    loot = {
        {1, 0},
        {2, 0},
        {3, 0}, 
        {4, 0}
    };
}

void Inventory::showInventory(Player* player) {

    clear();

    mvprintw(12, 100, "Health: %d/%d", player->getHealthPoints(), player->getHealthMax());
    mvprintw(13, 100, "Attack: %d", player->getAttackPoints());
    mvprintw(14, 100, "Level: %d", player->getLevel());
    mvprintw(15, 100, "Xp: %d/%d", player->getXp(), player->getXpLimit());

    for (int i = 1; i < 5; i++) {

        switch (i) {

            case 1:
                mvprintw(15 + i, 100, "Small potions of heal: %d", loot[1]);
                break;

            case 2:
                mvprintw(15 + i, 100, "Medium potions of heal: %d", loot[2]);
                break;

            case 3:
                mvprintw(15 + i, 100, "Health increase potions: %d", loot[3]);
                break;

            case 4:
                mvprintw(15 + i, 100, "Attack increase potions: %d", loot[4]);
                break;

        }
    }

    refresh();

}

void Inventory::reduceItemCount(int item) {
    loot[item]--;
}

void Inventory::addItem(int item) {
    loot[item]++;
}

std::unordered_map<int, int> Inventory::getLoot() {
    return loot;
}