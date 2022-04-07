#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(Averager* subscriber) {
	subscribers.push_back(subscriber);
}

void SimplePublisher::subscribe(MovingAverager* subscriber) {
	subscribers.push_back(subscriber);
}

void SimplePublisher::subscribe(PeriodicSampler* subscriber) {
	subscribers.push_back(subscriber);
}

void SimplePublisher::unsubscribe(Averager* subscriber) {
	for (size_t i = 0; i < subscribers.size(); i++) {
		if (subscriber->id == subscribers[i]->id) {
			subscribers.erase(subscribers.begin() + i);
		}
	}
}

void SimplePublisher::unsubscribe(MovingAverager* subscriber) {
	for (size_t i = 0; i < subscribers.size(); i++) {
		if (subscriber->id == subscribers[i]->id) {
			subscribers.erase(subscribers.begin() + i);
		}
	}
}

void SimplePublisher::unsubscribe(PeriodicSampler* subscriber) {
	for (size_t i = 0; i < subscribers.size(); i++) {
		if (subscriber->id == subscribers[i]->id) {
			subscribers.erase(subscribers.begin() + i);
		}
	}
}

void SimplePublisher::signal(Message message) {
	for (size_t i = 0; i < subscribers.size(); i++) {
		subscribers[i]->signal(message);
	}
}