#include "TestCase.hpp"

TestCase::TestCase(const std::string& name, const Error& error) {
	this->name = name;
	this->error = error;
}

std::string TestCase::getName() const { return name; }

bool TestCase::isPassing() const {
	ErrorType findError = error.getType();
	if (findError == ErrorType::None || findError == ErrorType::Warning) {
		return true;
	}
	else {
		return false;
	}
}

bool TestCase::hasError() const {
	ErrorType findError = error.getType();
	if (findError == ErrorType::None) {
		return false;
	}

	return true;
}

ErrorType TestCase::getErrorType() const {
	return error.getType();
}

std::string TestCase::getErrorMessage() const {
	if (hasError()) {
		return error.getMessage();
	}
	else {
		return "";
	}
}
