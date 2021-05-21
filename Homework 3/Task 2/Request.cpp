#include "Request.hpp"

int Request::counter = 0;

Request::Request(const std::string& message, const std::string sender) : message(message), sender(sender) {
	counter++;
	ID = counter;
}

std::string Request::getMessage() const {
	return message;
}

std::string Request::getSender() const {
	return sender;
}

int Request::getCount() const {
	return counter;
}

int Request::getID() const {
	return ID;
}

void Request::setMessage(const std::string& newMessage) {
	message = newMessage;
}

void Request::setSender(const std::string& newSender) {
	sender = newSender;
}
