#include "Shop.hpp"

int main() {
	Shop shop;
	Fruit t1;
	t1.setName("Melon");
	t1.setColor("Yellow");
	t1.setCalories(30);
	t1.setPrice(1.50);
	Vegetable t2;
	t2.setName("Potato");
	t2.setSort("Fresh");
	t2.setCalories(100);
	t2.setPrice(0.80);
	shop.addItem(&t1);
	shop.addItem(&t2);
	shop.changePrice(1, 1);
}