#include "Error.hpp"
#include "Functions.hpp"

Error::Error() {
	message = nullptr;
	type = ErrorType::None;
}

Error::Error(ErrorType newType, const char* newMessage) {
	type = newType;
	if (newMessage != nullptr) {
		int newMessageSize = strLength(newMessage);
		message = new char[newMessageSize + 1];
		for (int i = 0; i < newMessageSize; i++) {
			message[i] = newMessage[i];
		}

		message[newMessageSize] = '\0';
	}
	else {
		message = nullptr;
	}
}

Error::Error(const Error& rhs) {
	this->type = rhs.type;
	int rhsMessageSize = strLength(rhs.message);
	message = new char[rhsMessageSize + 1];
	for (int i = 0; i < rhsMessageSize; i++) {
		message[i] = rhs.message[i];
	}

	message[rhsMessageSize] = '\0';
}

Error Error::operator=(const Error& rhs) {
	if (this != &rhs) {
		delete[] message;
		this->type = rhs.type;
		int size = strLength(rhs.message);
		message = new char[size + 1];
		
		for (int i = 0; i < size; i++) {
			message[i] = rhs.message[i];
		}

		message[size] = '\0';
	}

	return *this;
}

Error::~Error() {
	delete[] message;
}

bool Error::hasMessage() const {
	if (strLength(message) != 0) {
		return true;
	}

	return false;
}

const char* Error::getMessage() const {
	if (hasMessage()) {
		return message;
	}
	else {
		return nullptr;
	}
}

ErrorType Error::getType() const { return type; }

Error Error::newNone() {
	ErrorType newType = ErrorType::None;
	char* newMessage = nullptr;
	Error obj = Error::Error(newType, newMessage);
	return obj;
}

Error Error::newBuildFailed(const char* message) {
	ErrorType newType = ErrorType::BuildFailed;
	Error obj = Error::Error(newType, message);
	return obj;
}

Error Error::newWarning(const char* message) {
	ErrorType newType = ErrorType::Warning;
	Error obj = Error::Error(newType, message);
	return obj;
}

Error Error::newFailedAssertion(const char* message) {
	ErrorType newType = ErrorType::FailedAssertion;
	Error obj = Error::Error(newType, message);
	return obj;
}