
#include "../h/stateBattle.h"

void StateBattle::loadInterface(Player* player, Monster* monster) {

    int maxY, maxX;
    getmaxyx(stdscr, maxY, maxX); // получает измерения окна

    for (int x = 0; x < maxX; x++) {
        mvaddch(0, x, ACS_HLINE); // чертит линию
    }

    for (int x = 0; x < maxX; x++) {
        mvaddch(maxY - 1, x, ACS_HLINE);
    }

    for (int y = 1; y < maxY - 1; y++) {
        mvaddch(y, 0, ACS_VLINE);
        mvaddch(y, maxX - 1, ACS_VLINE); 
    }

    for (int x = 1; x < maxX - 1; x++) {
        mvaddch(maxY - 15, x, ACS_HLINE);
    }
    for (int x = 1; x < maxX - 1; x++) {
        mvaddch(11, x, ACS_HLINE); 
    }

    mvprintw(2, 118, "%s", monster->getName().c_str()); // печатает полученныую строчку по данным координатам
    mvprintw(3, 111, "HP: %d/%d ATK: %d", monster->getHealthPoints(), monster->getHealthMax(), monster->getAttackPoints());
    mvprintw(6, 119, "YOU");
    mvprintw(7, 111, "HP: %d/%d ATK: %d", player->getHealthPoints(), player->getHealthMax(), player->getAttackPoints());
    mvprintw(8, 112, "REMAINING TIME: ");
    refresh(); 

}


void StateBattle::printSprite(Monster* monster) {

    std::string address = "../sprites/" + monster->getSpriteInd();
    std::ifstream file(address);

    std::string artLength; 
    getline(file, artLength);

    int artLengthNum = std::stoi(artLength);

    std::string sprite[artLengthNum];

    for (int i = artLengthNum; i > 0; i--) {
        getline(file, sprite[artLengthNum - i]); 
    }

    for (int i = 0; i < 26; i++) {
        mvprintw(15 + i, 90, "%s", sprite[i].c_str());
    }

}

bool StateBattle::readySetFight(Player* player, Monster* monster) {

    clear();
    
    loadInterface(player, monster);

    int ch;

    int textIndex = 0;
    int passedTime = 0;

    mvprintw(48, 115, "YOUR LINE:");
    refresh();

    timer.startTimestamp();

    while ((player->getHealthPoints() > 0) && (monster->getTime() - passedTime > 0) && (monster->getHealthPoints() > 0)) {

        if (textIndex == text.getTextLength()) {

            text.setRandomLine(monster);
            text.setTextLength(std::strlen(text.getLineToPrint().c_str()));
            textIndex = 0;
            
        }

        passedTime = timer.getPassedTime();

        mvprintw(8, 128,"%d\n", monster->getTime() - passedTime);
        refresh();

        bool mistake; 

        timeout(1000);

        ch = getch(); // хватаем введенный символ

        if (ch != ERR) { // проверка, если кнопка все же была нажата

            if (ch == 27) { // выход на ESC
                break;

            } else if (ch != text[textIndex]) {

                mistake = true;
                player->decreaseHealth(monster->getAttackPoints());

            } else {

                text += ch;
                textIndex++;
                monster->decreaseHealth(player->getAttackPoints());

            }
        }
        clear();


        if (monster->getRandomizeActive() && (passedTime % 5) == 0) {
            text.randomizeLine();
        }

        int maxX = getmaxx(stdscr);
        int centerX = maxX / 2;

        move(48, centerX - text.getTextLength() / 2); // передвигает курсор 

        attron(COLOR_PAIR(2)); // включение цветового паттерна

        printw("%s", text.getLineToPrint().substr(0,textIndex).c_str()); //печатает без передвижения курсора

        attroff(COLOR_PAIR(2)); // его выключение

        if (mistake) {

            attron(COLOR_PAIR(1)); 
            printw("%c", text[textIndex]);
            attroff(COLOR_PAIR(1));

            mistake = false; 

        } else {
            printw("%c", text[textIndex]);
        }

        if (textIndex != text.getTextLength()) {
            printw("%s\n", text.getLineToPrint().substr(textIndex + 1, text.getTextLength()).c_str()); 
        }

        printSprite(monster);

        loadInterface(player, monster); 

    }

    if (monster->getTime() - passedTime < 1 or player->getHealthPoints() < 1) { 
        return false; 
    } 
    
    return true;

}

