#pragma once
#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include "Publisher.hpp"

class BacklogPublisher : public Publisher {
	std::vector<Message> data;
public:
	BacklogPublisher() = default;

	void subscribe(Averager*);
	void subscribe(MovingAverager*);
	void subscribe(PeriodicSampler*);

	void unsubscribe(Averager*);
	void unsubscribe(MovingAverager*);
	void unsubscribe(PeriodicSampler*);

	void signal(Message);
};