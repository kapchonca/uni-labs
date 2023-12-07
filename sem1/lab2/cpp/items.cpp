#include "../h/items.h"


Item* Item::createItem(int itemType) {

    switch (itemType) {
        case 1:
            return new PotionOfHealSmall();
        case 2:
            return new PotionOfHealMedium();
        case 3:
            return new HealthScroll();
        default:
            return new AttackScroll();
    }

}


void PotionOfHealSmall::useItem(Player* player) {

    int effect = player->getHealthMax() / 4;
    player->increaseHealth(effect);
    
}

void PotionOfHealSmall::displayPotionInfo() {
    mvprintw(50, 100, "Restores 25%% of your full hp");
}

void PotionOfHealMedium::useItem(Player* player) {

    int effect = player->getHealthMax() / 2;
    player->increaseHealth(effect);
    
}

void PotionOfHealMedium::displayPotionInfo() {
    mvprintw(50, 100, "Restores 50%% of your full hp");
}

void AttackScroll::useItem(Player* player) {

    player->setAttackPoints(player->getAttackPoints() + 1);
        
}

void AttackScroll::displayScrollInfo() {
    mvprintw(50, 100, "Increases your attack by 1");
}

void HealthScroll::useItem(Player* player) {

    player->setHealthMax(player->getHealthMax() + 20);
        
}

void HealthScroll::displayScrollInfo() {
    mvprintw(50, 100, "Increases your health by 20");
}

void Item::decreaseItemCounter(Player* player) {
    player->getInventory()->reduceItemCount(itemInd);
}