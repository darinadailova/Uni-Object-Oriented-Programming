#pragma once
#include "Counter.hpp"

class LimitedCounter : virtual public Counter {
	int max;
public:
	LimitedCounter(int max);
	LimitedCounter(int max, int initial);
	LimitedCounter(int max, int initial, unsigned step);
	void increment();
	int getMax() const;
};