#ifndef PROGEN
#define PROGEN

#include <ncurses.h>

#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
#include <chrono>

struct Point {

    int x, y;

    bool operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    };
};
struct Room {

    int x, y, w, h;
    bool intersect(const Room &r) const;

};


class ProceduralGeneration {

private:

    int m_width, m_height;

    std::vector<std::string> m_data;

    std::vector<std::string> m_dataFog;

    std::vector<Room> m_rooms;

    std::vector<Point> chests;

public:

    ProceduralGeneration(int width, int height);

    void generateMap(int roomsCount);

    void generatePassage(const Point &start, const Point &finish);

    int getHeight();

    std::vector<std::string> getMap();

    std::vector<std::string> getMapFog();

    std::vector<Point> getChestsCoords();

};



#endif //PROGEN