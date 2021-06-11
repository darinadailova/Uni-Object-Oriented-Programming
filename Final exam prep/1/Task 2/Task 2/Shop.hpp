#pragma once
#include "Fruit.hpp"
#include "Vegetable.hpp"
#include <vector>

class Shop {
	std::vector<StoreItem*> items;

	void copy(const Shop& rhs);
	void deleteIteams();
public:
	Shop() = default;
	Shop(const Shop& rhs);
	Shop& operator=(const Shop& rhs);
	~Shop();

	void addItem(StoreItem* newItem);
	void removeItem(size_t index);
	void changePrice(size_t index, double newPrice);
	void changeName(size_t index, const std::string& newName);

	void info() const;
	Fruit* fruitWithMostCalories() const;
};