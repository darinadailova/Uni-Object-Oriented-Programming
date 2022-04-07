#include "Subscriber.hpp"

Subscriber::Subscriber(std::string id) : id(id) {
}

Subscriber::Subscriber(const Subscriber& rhs) {
	this->id = rhs.id;
	this->messages = rhs.messages;
}

Subscriber::~Subscriber() {
}