#include "Error.hpp"

Error::Error(const std::string& message) : error_message(message) {
}

Error::Error(const Error& rhs) {
	this->error_message = rhs.error_message;
}

Error& Error::operator=(const Error& rhs) {
	if (this != &rhs) {
		this->error_message = rhs.error_message;
	}

	return *this;
}

std::string Error::get_message() const { return error_message; }

void Error::set_message(const std::string& new_message) {
	error_message = new_message;
}