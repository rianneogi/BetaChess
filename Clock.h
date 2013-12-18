#pragma once

#include <chrono>

class Clock
{
public:
	std::chrono::high_resolution_clock::time_point begin;
    std::chrono::high_resolution_clock::time_point end;

	Clock(void);
	~Clock(void);
	void Start();
	void Stop();
	double ElapsedMilliseconds();
	double ElapsedSeconds();

};

