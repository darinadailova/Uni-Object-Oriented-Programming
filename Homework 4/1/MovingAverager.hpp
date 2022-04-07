#pragma once
#include "Subscriber.hpp"

class MovingAverager : public Subscriber {
public:
	MovingAverager(std::string id = "", size_t windowSize = 0);
	MovingAverager(const MovingAverager& rhs);
	
	size_t windowSize;

	virtual void signal(Message) override;
	virtual int read() const override;
	virtual Subscriber* clone() const override;
};