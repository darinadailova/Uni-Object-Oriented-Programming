#pragma once
#include <vector>
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"

class Publisher {
protected:
	std::vector<Subscriber*> subscribers;
public:
	Publisher() = default;
	virtual ~Publisher();

	virtual void subscribe(Averager*) = 0;
	virtual void subscribe(MovingAverager*) = 0;
	virtual void subscribe(PeriodicSampler*) = 0;

	virtual void unsubscribe(Averager*) = 0;
	virtual void unsubscribe(MovingAverager*) = 0;
	virtual void unsubscribe(PeriodicSampler*) = 0;

	virtual void signal(Message) = 0;
};