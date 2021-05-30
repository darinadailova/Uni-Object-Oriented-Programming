#pragma once
#include <string>
#include <vector>
#include <utility>
#include "ConcreteObserver.hpp"

class CentralBank {
	std::string name;
	std::vector<std::pair<std::string, double>> exchangeRates;
	std::vector<Observer*> observers;
public:
	CentralBank(const std::string& newName = "");
	CentralBank(const CentralBank& rhs);
	CentralBank& operator= (const CentralBank& rhs);
	~CentralBank();

	void addCurrency(std::pair<std::string, double> newExchange);
	void deleteCurrency(size_t index);
	void setRate(const std::string& currency, double newRate);

	void Register(ConcreteObserver* newObserver);
	void deleteObserver(size_t index);
	void notify(const std::string& currency, double rate) const;

	std::string getName() const;
};