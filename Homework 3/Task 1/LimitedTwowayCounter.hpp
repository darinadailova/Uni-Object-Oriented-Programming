#pragma once
#include "LimitedCounter.hpp"
#include "TwowayCounter.hpp"

class LimitedTwowayCounter : public TwowayCounter, public LimitedCounter {
	int min;
public:
	LimitedTwowayCounter(int min, int max);
	LimitedTwowayCounter(int min, int max, int initial);
	LimitedTwowayCounter(int min, int max, int initial, unsigned step);
	void increment();
	void decrement();
	int getMin() const;
};