#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter(int max) : max(max), Counter() {
}

LimitedCounter::LimitedCounter(int max, int initial) : max(max), Counter(initial){
}

LimitedCounter::LimitedCounter(int max, int initial, unsigned step) : max(max), Counter(initial, step) {
}

void LimitedCounter::increment() {
	if (int(initial + step) <= max) {
		initial += step;
	}
}

int LimitedCounter::getMax() const {
	return max;
}
