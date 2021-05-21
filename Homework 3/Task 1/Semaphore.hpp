#pragma once

class Semaphore {
	const int MIN = 0;
	const int MAX = 1;
	const unsigned STEP = 1;
	int initial;
public:
	Semaphore();
	Semaphore(bool flag);
	bool isAvailable();
	void wait();
	void signal();
};