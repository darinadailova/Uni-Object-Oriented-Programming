#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(std::string id, size_t period) : Subscriber(id), period(period) {
}

PeriodicSampler::PeriodicSampler(const PeriodicSampler& rhs) {
	this->id = rhs.id;
	this->messages = rhs.messages;
	this->period = rhs.period;
}

void PeriodicSampler::signal(Message message) {
	messages.push_back(message);
}

int PeriodicSampler::read() const {
	if (messages.size() == 0) {
		return 0;
	}

	for (size_t i = messages.size() - 1; i >= 0; i--) {
		if (i % period == 0 || i == 0) {
			return messages[i].data;
		}
	}
}

Subscriber* PeriodicSampler::clone() const {
	return new PeriodicSampler(*this);
}