#pragma once

class Counter {
protected:
	int initial;
	unsigned step;
public:
	Counter();
	Counter(int initial);
	Counter(int initial, unsigned step);
	void increment();
	int getTotal() const;
	unsigned getStep() const;
};