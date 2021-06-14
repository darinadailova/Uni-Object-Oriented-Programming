#include "CentralBank.hpp"

CentralBank::CentralBank(const std::string& newName) : name(newName) {}

CentralBank::CentralBank(const CentralBank& rhs) {
	this->name = rhs.name;
	for (auto& item : rhs.exchangeRates) {
		this->exchangeRates.push_back(item);
	}

	for (auto observer : rhs.observers) {
		this->observers.push_back(observer->clone());
	}
}

CentralBank& CentralBank::operator=(const CentralBank& rhs) {
	if(this != &rhs) {
		this->name = rhs.name;
		this->exchangeRates.clear();
		for (auto& item : rhs.exchangeRates) {
			this->exchangeRates.push_back(item);
		}
	
		for (auto x : this->observers) {
			delete x;
		}

		observers.clear();

		for (auto observer : rhs.observers) {
			this->observers.push_back(observer->clone());
		}
	}

	return *this;
}

CentralBank::~CentralBank() {
	for (auto x : this->observers) {
		delete x;
	}

	observers.clear();
}

void CentralBank::addCurrency(std::pair<std::string, double> newExchange) {
	exchangeRates.push_back(newExchange);
}

void CentralBank::deleteCurrency(size_t index) {
	exchangeRates.erase(exchangeRates.begin() + index);
}

void CentralBank::setRate(const std::string& currency, double newRate) {
	for (auto& x : exchangeRates) {
		if (x.first == currency) {
			x.second = newRate;
			notify(currency, newRate);
		}
	}
}

void CentralBank::Register(ConcreteObserver* newObserver) {
	observers.push_back(newObserver->clone());
}

void CentralBank::deleteObserver(size_t index) {
	if (index < observers.size()) {
		delete observers[index];
		observers.erase(observers.begin() + index);
	}
}

void CentralBank::notify(const std::string& currency, double rate) const {
	for (auto& x : observers) {
		x->update(currency, rate);
	}
}

std::string CentralBank::getName() const {
	return name;
}