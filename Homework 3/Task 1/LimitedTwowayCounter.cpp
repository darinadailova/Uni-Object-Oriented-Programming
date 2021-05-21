#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max) 
	: min(min), Counter(), LimitedCounter(max), TwowayCounter() {
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial) 
	: min(min), Counter(initial), TwowayCounter(initial), LimitedCounter(max, initial) {
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial, unsigned step) 
	: min(min), Counter(initial, step), TwowayCounter(initial, step), LimitedCounter(max, initial, step) {
}

void LimitedTwowayCounter::increment() {
	LimitedCounter::increment();
}

void LimitedTwowayCounter::decrement() {
	if (int(initial - step) >= min) {
		initial -= step;
	}
}

int LimitedTwowayCounter::getMin() const {
	return min;
}
