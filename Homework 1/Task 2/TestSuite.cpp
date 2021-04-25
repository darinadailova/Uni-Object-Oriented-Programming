#include "TestSuite.hpp"

TestSuite::TestSuite(std::string name) {
	this->name = name;
}

void TestSuite::add(const TestCase& newCase) {
	cases.push_back(newCase);
}

std::vector<TestCase> TestSuite::filterPassing() const {
	std::vector<TestCase>passedCases;
	int size = cases.size();
	for (int i = 0; i < size; i++) {
		if (cases[i].isPassing()) {
			passedCases.push_back(cases[i]);
		}
	}

	return passedCases;
}

std::vector<TestCase> TestSuite::filterFailing() const {
	std::vector<TestCase>failingCases;
	int size = cases.size();
	for (int i = 0; i < size; i++) {
		if (!cases[i].isPassing()) {
			failingCases.push_back(cases[i]);
		}
	}

	return failingCases;
}

std::vector<TestCase> TestSuite::filterByErrorType(ErrorType searchedType) const {
	std::vector<TestCase>filteredCases;
	int size = cases.size();
	for (int i = 0; i < size; i++) {
		if (cases[i].getErrorType() == searchedType) {
			filteredCases.push_back(cases[i]);
		}
	}

	return filteredCases;
}

void TestSuite::removeByErrorType(ErrorType searchedType) {
	for (int i = 0; i < cases.size(); i++) {
		if (cases[i].getErrorType() == searchedType) {
			cases.erase(cases.begin() + i);
		}
	}
}

std::string TestSuite::getName() const { return name; }

void TestSuite::setName(const std::string& newName) {
	name = newName;
}
