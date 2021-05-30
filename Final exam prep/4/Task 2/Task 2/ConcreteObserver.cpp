#include "ConcreteObserver.hpp"

ConcreteObserver::ConcreteObserver(const std::string& name) : Observer(), name(name) {}

ConcreteObserver::ConcreteObserver(const ConcreteObserver& rhs) {
	this->name = rhs.name;
}

void ConcreteObserver::update(const std::string& currency, double rate) {
	std::cout << "Update<" << name << ">:<" << currency << "><" << rate << ">" << '\n';
}

Observer* ConcreteObserver::clone() const {
	return new ConcreteObserver(*this);
}

std::string ConcreteObserver::getName() const {
	return name;
}
