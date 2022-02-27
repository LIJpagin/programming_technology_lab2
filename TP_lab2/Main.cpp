#include <locale>
#include "List.h"

int main() {
	setlocale(LC_ALL, "Rus");
	List list(5, 1, 3, 5, 7, 9);
	std::cout << list << std::endl;
	std::cout << list[4];

	return 0;
}