#include "drink.hpp"
#include "VendingMachine.hpp"
#include <iostream>

int main() {

	Drink fanta("Fanta", 300, 0.5, 1.8);
	Drink drink1;
	drink1 = fanta;
	Drink drink2 = fanta;
	Drink drink3;
	drink2 = drink3;
	fanta.print();
	fanta.set_name("Fantaa");
	fanta.print();
	Drink CocaCola("Coca Cola", 400, 1, 2.5);

	VendingMachine v;
	v.add_drink(fanta);
	v.add_drink(fanta);
	v.print();
	std::cout << v.buy_drink("Fantaa", 1.8) << '\n';
	v.add_drink(CocaCola);
	v.print();
	std::cout << v.buy_drink("Coca Cola", 2) << '\n';
	std::cout << v.get_income() << '\n';
	v.print();
	VendingMachine v2(v);
	VendingMachine v3;
	v3 = v2;

	return 0;
}