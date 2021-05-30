#include "CentralBank.hpp"

int main() {
	CentralBank bank;
	std::pair<std::string, double> currency;
	currency.first = "euro";
	currency.second = 1.96;
	bank.addCurrency(currency);
	ConcreteObserver observer1("observer 1");
	ConcreteObserver observer2("observer 2");
	ConcreteObserver observer3("observer 3");
	bank.Register(&observer1);
	bank.Register(&observer2);
	bank.Register(&observer3);
	bank.setRate("euro", 1.95);
	bank.deleteObserver(1);

	return 0;
}