#include "VendingMachine.hpp"
#include "Functions.hpp"

VendingMachine::VendingMachine() : availableDrinks(nullptr), income(0), drinksCount(0) {
}

VendingMachine::VendingMachine(const VendingMachine& from) {
	this->income = from.income;
	this->drinksCount = from.drinksCount;
	
	if (from.availableDrinks != nullptr) {
		this->availableDrinks = new Drink[this->drinksCount];
		for (int i = 0; i < this->drinksCount; i++) {
			this->availableDrinks[i] = from.availableDrinks[i];
		}
	}
	else {
		this->availableDrinks = nullptr;
	}
}

VendingMachine& VendingMachine::operator=(const VendingMachine& from) {
	if (this != &from) {
		delete[] availableDrinks;
		this->income = from.income;
		this->drinksCount = from.drinksCount;

		if (from.availableDrinks != nullptr) {
			this->availableDrinks = new Drink[this->drinksCount];
			for (int i = 0; i < this->drinksCount; i++) {
				this->availableDrinks[i] = from.availableDrinks[i];
			}
		}
		else {
			this->availableDrinks = nullptr;
		}
	}
	
	return *this;
}

VendingMachine::~VendingMachine() {
	delete[] availableDrinks;
}

bool VendingMachine::add_drink(const Drink& to_add) {
	for (int i = 0; i < drinksCount; i++) {
		if (stringcmp(to_add.get_name(), availableDrinks[i].get_name())) {
			return false;
		}
	}
	
	Drink* temp = new Drink[this->drinksCount + 1];
	for (int i = 0; i < drinksCount; i++) {
		temp[i] = availableDrinks[i];
	}

	temp[drinksCount] = to_add;
	delete[] availableDrinks;
	drinksCount++;
	availableDrinks = new Drink[drinksCount];

	for (int i = 0; i < drinksCount; i++) {
		availableDrinks[i] = temp[i];
	}
	delete[] temp;

	return true;
}

int VendingMachine::buy_drink(const char* drink_name, const double money) {
	for (int i = 0; i < drinksCount; i++) {
		if (stringcmp(drink_name, availableDrinks[i].get_name())) {
			if (money >= availableDrinks[i].get_price()) {
				income += money;
				removeDrink(i);
				return 0;
			}
			else {
				income += money;
				return 1;
			}
		}
	}

	return 2;
}

double VendingMachine::get_income() const { return income; }

int VendingMachine::get_drinksCount() const { return drinksCount; }

void VendingMachine::removeDrink(int index) {
	Drink* temp = new Drink[drinksCount - 1];
	for (int i = 0, j = 0; i < drinksCount; i++) {
		if (i != index) {
			temp[j] = availableDrinks[i];
			j++;
		}
	}

	delete[] availableDrinks;
	drinksCount--;
	availableDrinks = new Drink[drinksCount];
	for (int i = 0; i < drinksCount; i++) {
		availableDrinks[i] = temp[i];
	}
	
	delete[] temp;
}

void VendingMachine::print() const {
	std::cout << "Available drinks: \n";
	for (int i = 0; i < drinksCount; i++) {
		availableDrinks[i].print();
	}
}
