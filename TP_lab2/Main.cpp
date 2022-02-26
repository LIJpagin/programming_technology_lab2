#include <locale>
#include "List.h"

int main() {
	setlocale(LC_ALL, "Rus");

	List list;

	list.pushBack(1);
	list.pushBack(8);
	list.pushBack(4);
	list.pushFront(6);
	list.pushFront(3);

	std::cout << list.size() << std::endl;
	std::cout << list << std::endl;

	List list1(list);
	std::cout << list1 + list << std::endl;

	return 0;
}