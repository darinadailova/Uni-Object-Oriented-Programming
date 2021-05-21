#include "Counter.hpp"

Counter::Counter() : initial(0), step(1) {
}

Counter::Counter(int initial) : initial(initial), step(1) {
}

Counter::Counter(int initial, unsigned step) : initial(initial), step(step) {
}

void Counter::increment() {
	initial += step;
}

int Counter::getTotal() const {
	return initial;
}

unsigned Counter::getStep() const {
	return step;
}
