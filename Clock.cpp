#include "Clock.h"


Clock::Clock(void)
{
}

Clock::~Clock(void)
{
}

void Clock::Start()
{
    begin = std::chrono::high_resolution_clock::now();
}

void Clock::Stop()
{
    end = std::chrono::high_resolution_clock::now();
}

double Clock::ElapsedMilliseconds()
{
    return std::chrono::duration_cast<std::chrono::duration<int,std::milli>>(end - begin).count();
}

double Clock::ElapsedSeconds()
{
    return std::chrono::duration_cast<std::chrono::duration<int,std::milli>>(end - begin).count() / (double)1000;

}