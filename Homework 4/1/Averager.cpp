#include "Averager.hpp"

Averager::Averager(std::string id) : Subscriber(id) {
}

Averager::Averager(const Averager& rhs) {
	this->id = rhs.id;
	this->messages = rhs.messages;
}

void Averager::signal(Message message) {
	messages.push_back(message);
}

int Averager::read() const {
	if (messages.size() == 0) {
		return 0;
	}
	
	int average = 0;
	for (size_t i = 0; i < messages.size(); i++) {
		average += messages[i].data;
	}

	return (average / messages.size());
}

Subscriber* Averager::clone() const {
	return new Averager(*this);
}