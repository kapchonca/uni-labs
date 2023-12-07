
#include "../h/gameManager.h"

GameManager::GameManager() {
    loopCounter = 0;

    player = new Player();

    boss = nullptr;
    monster = nullptr;
    map = nullptr;

    battle = new StateBattle();
}

GameManager::~GameManager() {
    delete player; 
    player = nullptr; 

    delete monster; 
    monster = nullptr; 

    delete boss; 
    boss = nullptr; 

    delete battle; 
    battle = nullptr;

    delete map;
    map = nullptr;
}

bool GameManager::gameIsOver() {

    if (s_GameIsOver) {

        return true;

    } else {

        return false;

    }
}

void GameManager::setGameOver() {
    s_GameIsOver = true;
}

void GameManager::printGameOver() {

    clear();
    mvprintw(27, 113, "GAME OVER");
    mvprintw(28, 108, "Press any key to quit");

    timeout(-1);
    getch();
}

void GameManager::nextLoop() {

    generateMap();

    increaseLoopCount();

    clear();
    mvprintw(28, 100, "Stages completed: %d", loopCounter);
    timeout(-1);
    getch();
}

Monster* GameManager::getRandomMonster(Player* player) {

    if (monster != nullptr) {
        delete monster;
    }

    if (rand() % 3 == 0) {
        monster = new Skeleton(player);

    } else if (rand() % 3 == 1) {
        monster = new Vampire(player);

    } else {
        monster = new Dragon(player);
    }

    return monster;
    
}

void GameManager::generateBoss(Player* player, int loopCount) {

    if (boss != nullptr) {
        delete boss;
    }
    boss = new Boss(player, loopCount);

}

void GameManager::generateMap() {

    if (map != nullptr) {
        delete map;
    }
    map = new Map(238, 59, 10);

}

void GameManager::stateInventory(Player* player) {

    int ch;

    Inventory* inv = player->getInventory();

    while (true) {

        inv->showInventory(player);
        ch = getch();

        if (ch == 'f') {
            break;
        }

        if (player->getInventory()->getLoot()[(static_cast<int>(ch) - 48)] != 0) { 
            // -48 - это приведение символа к инту по ascii таблице
            clear();
            Item* item = Item::createItem((static_cast<int>(ch) - 48));

            inv->reduceItemCount(static_cast<int>(ch) - 48);

            item->useItem(player);

            delete item;
            item = nullptr;

        }
        
    }

}

void GameManager::windowInitializer() {

    initscr(); // инициализирует библиотеку ncurses и подготавливает терминал к работе
    start_color(); // подключает поддержку цветов
    curs_set(0); // прячет курсор
    init_pair(1, COLOR_WHITE, 160); // инициализация цветовой палитры
    init_pair(2, 242, COLOR_BLACK);

}

void GameManager::StateHandler() {

    windowInitializer();

    generateMap();

    while (!gameIsOver()) {

        int interactionNum = map->movePlayer();

        if (interactionNum == 0) {

            setGameOver();

        } else if (interactionNum == 2) {

                clear();
                Chest chest;    
                
                player->getInventory()->addItem(chest.returnLoot()[0]);

                chest.displayChest();
                getch(); // функция, хватающая нажатый символ

        } else if (interactionNum == 1) {

                monster = getRandomMonster(player);

                if(battle->readySetFight(player, monster)) {

                    recieveLoot(player, monster);
                    clear();

                } else {

                    printGameOver();
                    setGameOver();

                }

        } else if (interactionNum == 3) {

            stateInventory(player);

        } else if (interactionNum == 4) {

                generateBoss(player, loopCounter);

                if (battle->readySetFight(player, boss)) {

                    recieveLoot(player, boss);

                    nextLoop();

                } else {

                    setGameOver();

                }

        }
    }

    endwin(); // закрытие окошка
}

void GameManager::recieveLoot(Player* player, Monster* monster) {

    int xpToGet = player->getXpLimit() / 10 + rand() % player->getXpLimit() / 10;

    player->addExp(xpToGet);
    player->levelUp();

    bool specialLoot = (rand() % 4) == 0;

    if (specialLoot && monster->getSpriteInd() == "1") {

        player->getInventory()->addItem(1);

    }
}

void GameManager::increaseLoopCount() {

    loopCounter+=1;

}