#include "Semaphore.hpp"

Semaphore::Semaphore() {
	initial = 0;
}

Semaphore::Semaphore(bool flag) {
	if (flag) initial = 1;
	else initial = 0;
}

bool Semaphore::isAvailable() {
	if (initial > 0) return true;
	return false;
}

void Semaphore::wait() {
	if (int(initial - STEP) >= MIN) {
		initial -= STEP;
	}
}

void Semaphore::signal() {
	if (int(initial + STEP) <= MAX) {
		initial += STEP;
	}
}