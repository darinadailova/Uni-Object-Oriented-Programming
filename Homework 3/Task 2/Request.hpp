#pragma once
#include <string>

class Request {
	std::string message;
	std::string sender;
	static int counter;
	int ID;
public:
	Request(const std::string& message, const std::string sender);

	std::string getMessage() const;
	std::string getSender() const;
	int getCount() const;
	int getID() const;

	void setMessage(const std::string& newMessage);
	void setSender(const std::string& newSender);
};