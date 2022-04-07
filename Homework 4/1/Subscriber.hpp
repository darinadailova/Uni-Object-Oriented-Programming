#pragma once
#include <string>
#include "Message.hpp"
#include <vector>

class Subscriber {
public:
	std::vector<Message> messages;
	std::string id;

	Subscriber(std::string id = "");
	Subscriber(const Subscriber& rhs);
	virtual ~Subscriber();

	virtual void signal(Message) = 0;
	virtual int read() const = 0;
	virtual Subscriber* clone() const = 0;
};