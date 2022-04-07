#pragma once
#include "Subscriber.hpp"

class PeriodicSampler : public Subscriber {
	size_t period;
	int receivedMessages;
public:
	PeriodicSampler(std::string id, size_t period);
	PeriodicSampler(const PeriodicSampler& rhs);

	virtual void signal(Message) override;
	virtual int read() const override;
	virtual Subscriber* clone() const override;
};