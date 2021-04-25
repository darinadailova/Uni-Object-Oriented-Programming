#include "drink.hpp"
#include "Functions.hpp"

Drink::Drink() : name(nullptr), quantity(0), calories(0), price(0) {
}

Drink::Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price) {
	int initNameSize = strlength(init_name);
	name = new char[initNameSize + 1];
	for (int i = 0; i < initNameSize; i++) {
		name[i] = init_name[i];
	}
	name[initNameSize] = '\0';
	
	calories = init_calories;
	quantity = init_quantity;
	price = init_price;
}

Drink::Drink(const Drink& rhs) { // rhs = right hand side
	this->calories = rhs.calories;
	this->quantity = rhs.quantity;
	this->price = rhs.price;
	int newSize = strlength(rhs.name);
	this->name = new char[newSize + 1];
	for (int i = 0; i < newSize; i++) {
		this->name[i] = rhs.name[i];
	}
	name[newSize] = '\0';
}

Drink& Drink::operator=(const Drink& rhs) {
	if (this != &rhs) {
		this->calories = rhs.calories;
		this->quantity = rhs.quantity;
		this->price = rhs.price;
		set_name(rhs.name);
	}
	
	return *this;
}

Drink::~Drink() {
	delete[] name;
}

const char* Drink::get_name() const { return name; }

int Drink::get_calories() const { return calories; }

double Drink::get_quantity() const { return quantity; }

double Drink::get_price() const { return price; }

void Drink::set_name(const char* new_name) {
	delete[] name;
	if (new_name != nullptr) {
		int newSize = strlength(new_name);
		name = new char[newSize + 1];

		for (int i = 0; i < newSize; i++) {
			name[i] = new_name[i];
		}
		name[newSize] = '\0';
	}
	else {
		name = nullptr;
	}
}

void Drink::set_calories(const int new_calories) { calories = new_calories; }

void Drink::set_quantity(const double new_quantity) { quantity = new_quantity; }

void Drink::set_price(const double new_price) { price = new_price; }

void Drink::print() const {
	std::cout << "Name: " << name << '\n';
	std::cout << "Calories: " << calories << '\n';
	std::cout << "Quantity: " << quantity << '\n';
	std::cout << "Price: " << price << '\n';
}