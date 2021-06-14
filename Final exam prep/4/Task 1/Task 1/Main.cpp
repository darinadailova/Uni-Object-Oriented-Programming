#include "Product.hpp"
#include "Summ.hpp"
#include "Var.hpp"
#include "Const.hpp"

int main() {
	char arr[] = "x";
	Var v(arr, 4);
	Const c = 3;
	Summ s(&c, &v);
	s.print();
	Product p(&c, &v);
	p.print();
	
	return 0;
}