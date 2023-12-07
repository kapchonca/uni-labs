#ifndef TIMER
#define TIMER

#include <chrono>

class Timer {
    
protected:

    std::chrono::steady_clock::time_point start;

public:

    void startTimestamp();

    int getPassedTime();

};


#endif //TIMER