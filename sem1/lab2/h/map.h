
#ifndef MAP
#define MAP

#include "../h/monster.h"
#include "../h/progen.h"

class Map {

protected:

    int mapHeight = 0;

    std::vector<std::string> mapLayout; 
    std::vector<std::string> mapFogLayout; 

    std::vector<Point> chestCoords;
    ProceduralGeneration* new_generation;

public:

    Map(int width, int height, int roomsCount);

    void displayMap();

    int movePlayer();

    void removeChest(int chestInd);

    void fieldOfView(int y, int x);

};

#endif //MAP