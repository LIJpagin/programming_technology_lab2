#include <iostream>
#include <windows.h>
#include <ctime>

#include "List.h"

int main() {
	List list;
	list.pushBack(1);
	list.pushBack(8);
	list.pushBack(4);
	list.pushBack(6);
	list.pushBack(3);
	std::cout << list.size() << std::endl;
	std::cout << list << std::endl;
}