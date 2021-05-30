#pragma once
#include "Observer.hpp"
#include <iostream>

class ConcreteObserver : public Observer {
	std::string name;
public:
	ConcreteObserver(const std::string& name = "");
	ConcreteObserver(const ConcreteObserver& rhs);

	virtual void update(const std::string& currency, double rate) override;
	virtual Observer* clone() const override;

	std::string getName() const;
};