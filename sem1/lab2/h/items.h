#ifndef POTIONS
#define POTIONS

#include "../h/player.h"

class PotionOfHealSmall;
class PotionOfHealMedium;
class HealthScroll;
class AttackScroll;

class Item {

protected:
    int itemInd;

public:

    static Item* createItem(int itemType);

    void decreaseItemCounter(Player* player);

    virtual void useItem(Player* player) = 0;

    virtual ~Item() = default; 

};

class Potion: public Item {

public:

    virtual void useItem(Player* player) = 0;

    virtual void displayPotionInfo() = 0;

    ~Potion() override = default;
};

class Scroll: public Item {

public:

    virtual void useItem(Player* player) = 0;

    virtual void displayScrollInfo() = 0;

    ~Scroll() override = default;

};


class PotionOfHealSmall: public Potion {

public:

    void useItem(Player* player) override;

    void displayPotionInfo() override;

    ~PotionOfHealSmall() override = default;
    
};

class PotionOfHealMedium: public Potion {

public:

    void useItem(Player* player) override;

    void displayPotionInfo() override;

    ~PotionOfHealMedium() override = default;
};

class AttackScroll: public Scroll {

public:

    void useItem(Player* player) override;

    void displayScrollInfo() override;

    ~AttackScroll() override = default;
};

class HealthScroll: public Scroll {

public:

    void useItem(Player* player) override;

    void displayScrollInfo() override;

    ~HealthScroll() override = default;
};



#endif //POTIONS