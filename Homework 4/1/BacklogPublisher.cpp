#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Averager* sub) {
	subscribers.push_back(sub);

	for (auto& x : data) {
		subscribers[subscribers.size() - 1]->signal(x);
	}
}

void BacklogPublisher::subscribe(MovingAverager* sub) {
	subscribers.push_back(sub);
	for (auto& x : data) {
		subscribers[subscribers.size() - 1]->signal(x);
	}

	for (size_t i = 0; i < subscribers.size() - 1; i++) {
		for (size_t j = 0; j < subscribers[i]->messages.size(); i++) {
			subscribers[subscribers.size() - 1]->signal(subscribers[i]->messages[j]);
		}
	}
}

void BacklogPublisher::subscribe(PeriodicSampler* sub) {
	subscribers.push_back(sub);
	for (auto& x : data) {
		subscribers[subscribers.size() - 1]->signal(x);
	}
	
	for (size_t i = 0; i < subscribers.size() - 1; i++) {
		for (size_t j = 0; j < subscribers[i]->messages.size(); i++) {
			subscribers[subscribers.size() - 1]->signal(subscribers[i]->messages[j]);
		}
	}
}

void BacklogPublisher::unsubscribe(Averager* subscriber) {
	for (size_t i = 0; i < subscribers.size(); i++) {
		if (subscriber->id == subscribers[i]->id) {
			subscribers.erase(subscribers.begin() + i);
		}
	}
}

void BacklogPublisher::unsubscribe(MovingAverager* subscriber) {
	for (size_t i = 0; i < subscribers.size(); i++) {
		if (subscriber->id == subscribers[i]->id) {
			subscribers.erase(subscribers.begin() + i);
		}
	}
}

void BacklogPublisher::unsubscribe(PeriodicSampler* subscriber) {
	for (size_t i = 0; i < subscribers.size(); i++) {
		if (subscriber->id == subscribers[i]->id) {
			subscribers.erase(subscribers.begin() + i);
		}
	}
}

void BacklogPublisher::signal(Message message) {
	data.push_back(message);
	for (size_t i = 0; i < subscribers.size(); i++) {
		subscribers[i]->signal(message);
	}
}