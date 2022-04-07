#pragma once
#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include "Publisher.hpp"

class SimplePublisher : public Publisher {
public:
	SimplePublisher() = default;

	virtual void subscribe(Averager*) override;
	virtual void subscribe(MovingAverager*) override;
	virtual void subscribe(PeriodicSampler*) override;

	virtual void unsubscribe(Averager*) override;
	virtual void unsubscribe(MovingAverager*) override;
	virtual void unsubscribe(PeriodicSampler*) override;

	virtual void signal(Message) override;
};