#include <locale>
#include <string>
#include "List.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	List list1, list2, list3;
	string in;
	bool active = false;

	while (true) {
		while (in.empty()) {
			system("cls");
			cout << "Класс \"Однонаправленный циклический список\"\n";
			cout << "Выберите список, над которым будут произведены действия\n";
			cout << " 1 – list1\n";
			cout << " 2 – list2\n";
			cout << "\n > ";
			cin >> in;
			if (in[0] == '1') active = true;
			else if (in[0] == '2') active = false;
			else {
				cout << "\n Что-то не то . . .\n Попробуйте еще раз\n ";
				system("pause");
				in.clear();
			}
		}
		in.clear();

		while (in.empty()) {
			system("cls");
			cout << "Класс \"Однонаправленный циклический список\"\n";
			cout << " 1 – Заполнить очередь случайным образом\n";
			cout << " 2 – Добавление элемента в начало списка\n";
			cout << " 3 – Добавление элемента в конец списка\n";
			cout << " 4 – Удаление элемента из начала списка\n";
			cout << " 5 – Удаление элемента из конца списка\n";
			cout << " 6 – Сделать копию списка\n";
			cout << " 7 - Сравнить первую и вторую очереди\n";
			cout << " 8 – Получить элемент списка\n";
			cout << " 9 – Получить подсписок\n";
			cout << " + – Сложить списки поэлементно\n";
			cout << " - – Вычесть списки поэлементно\n";
			cout << " * – Умножить списки поэлементно\n";
			cout << " / – Разделить списки поэлементно\n";
			cout << " a – Вывести список на экран\n";
			cout << " b – Получить первый элемент списка\n";
			cout << " c – Получить последний элемент списка\n";
			cout << " d – Очистить список\n";
			cout << " e – Выйти из программы\n";
			cout << "\n > ";
			cin >> in;
			switch (in[0]) {
			default:
				cout << " Что-то не то . . .\n Попробуйте еще раз\n ";
				in.clear();
				break;
			// Заполнить очередь случайным образом
			case '1': {
				system("cls");
				cout << "Действие: " << (active ? "list1" : "list2") << ".random()" << endl;
				cout << (active ? "list1: " : "list2: ") << (active ? list1 : list2) << endl;
				active ? list1.random() : list2.random();
				cout << "Результат: " << (active ? list1 : list2) << endl;
				} break;
			// Добавление элемента в начало списка
			case '2': {
				system("cls");
				cout << "Действие: ++" << (active ? "list1" : "list2") << endl;
				cout << (active ? "list1: " : "list2 : ") << (active ? list1 : list2) << endl;
				active ? ++list1 : ++list2;
				cout << "Результат: " << (active ? list1 : list2) << endl;
				} break;
			// Добавление элемента в конец списка
			case '3': {
				cout << "Действие: " << (active ? "list1" : "list2") << "++" << endl;
				cout << (active ? "list1: " : "list2 : ") << (active ? list1 : list2) << endl;
				active ? list1++ : list2++;
				cout << "Результат: " << (active ? list1 : list2) << endl;
				} break;
			// Удаление элемента из начала списка
			case '4': {
				cout << "Действие: --" << (active ? "list1" : "list2") << endl;
				cout << (active ? "list1: " : "list2 : ") << (active ? list1 : list2) << endl;
				active ? --list1 : --list2;
				cout << "Результат: " << (active ? list1 : list2) << endl;
				} break;
			// Удаление элемента из конца списка
			case '5': {
				cout << "Действие: " << (active ? "list1" : "list2") << "--" << endl;
				cout << (active ? "list1: " : "list2 : ") << (active ? list1 : list2) << endl;
				active ? list1-- : list2--;
				cout << "Результат: " << (active ? list1 : list2) << endl;
				} break;
			// Сделать копию списка
			case '6': {
				cout << "Действие: list3 = " << (active ? "list1" : "list2") << endl;
				cout << (active ? "list1: " : "list2 : ") << (active ? list1 : list2) << endl;
				active ? list3 = list1 : list3 = list2;
				cout << "Результат:\nlist3: " << list3 << endl;
				list3.clear();
				} break;
			// Сравнить первую и вторую очереди
			case '7': {
				system("cls");
				cout << "list1: " << list1 << "list2: " << list2 << endl;
				cout << "Результат" << endl;
				cout << "list1 == list2 " << (list1 == list2) << endl;
				cout << "list1 != list2 " << (list1 != list2) << endl;
				cout << "list1 >= list2 " << (list1 >= list2) << endl;
				cout << "list1 <= list2 " << (list1 <= list2) << endl;
				cout << "list1 > list2 " << (list1 > list2) << endl;
				cout << "list1 < list2 " << (list1 < list2) << endl;
				} break;
			// Получить элемент списка
			case '8': {
				cout << "Действие: " << (active ? "list1" : "list2") << "[ ]" << endl;
				cout << (active ? "list1: " : "list2: ") << (active ? list1 : list2) << endl;
				cout << "Введите индекс в списке: ";
				int index;
				cin >> index;
				cout << "Результат: " << (active ? "list1[" : "list2[") << index << "] = "
					 << (active ? list1[index] : list2[index]) << endl;
				} break;
			// Получить подсписок
			case '9': {
				cout << "Действие: list3 = " << (active ? "list1" : "list2") << "( , )" << endl;
				cout << (active ? "list1: " : "list2: ") << (active ? list1 : list2) << endl;
				int index1, index2;
				cout << "Введите левый индекс в списке: ", cin >> index1;
				cout << "Введите правый индекс в списке: ", cin >> index2;
				active ? list3 = list1(index1, index2) : list3 = list2(index1, index2);
				cout << "Результат:\nlist3: " << list3 << endl;
				} break;
			// Сложить списки поэлементно
			case '+': {
				cout << "Действие: list3 = list1 + list2" << endl;
				cout << "list1: " << list1 << endl << "list2: " << list2 << endl;
				list3 = list1 + list2;
				cout << "Рузльтат:\nlist3: " << list3 << endl;
				list3.clear();
				} break;
			// Вычесть списки поэлементно
			case '-': {
				cout << "Действие: list3 = " << (active ? "list1 - " : "list2 - ") << (active ? "list2" : "list1") << endl;
				cout << "list1: " << list1 << endl << "list2: " << list2 << endl;
				active ? list3 = list1 - list2 : list3 = list2 - list1;
				cout << "Результат:\nlist3: " << list3 << endl;
				list3.clear();
				} break;
			// Умножить списки поэлементно
			case '*': {
				cout << "Действие: list3 = list1 * list2" << endl;
				cout << "list1: " << list1 << endl << "list2: " << list2 << endl;
				list3 = list1 * list2;
				cout << "Рузльтат:\nlist3: " << list3 << endl;
				list3.clear();
				} break;
			// Разделить списки поэлементно
			case '/': {
				cout << "Действие: list3 = " << (active ? "list1 / " : "list2 / ") << (active ? "list2" : "list1") << endl;
				cout << "list1: " << list1 << endl << "list2: " << list2 << endl;
				active ? list3 = list1 / list2 : list3 = list2 / list1;
				cout << "Рузльтат:\nlist3: " << list3 << endl;
				list3.clear();
				} break;
			// Вывести список на экран
			case 'a': {
				cout << (active ? "list1: " : "list2: ") << (active ? list1 : list2) << endl;
				} break;
			// Получить первый элемент списка
			case 'b': {
				cout << "Действие: " << (active ? "list1" : "list2") << ".front()" << endl;
				cout << (active ? "list1: " : "list2: ") << (active ? list1 : list2) << endl;
				cout << "Результат: " << (active ? list1.front() : list2.front()) << endl;
				} break;
			// Получить последний элемент списка
			case 'c': {
				cout << "Действие: " << (active ? "list1" : "list2") << ".back()" << endl;
				cout << (active ? "list1: " : "list2: ") << (active ? list1 : list2) << endl;
				cout << "Результат: " << (active ? list1.back() : list2.back()) << endl;
				} break;
			// Очистить список
			case 'd': {
				system("cls");
				cout << "Действие: " << (active ? "list1" : "list2") << ".clear()" << endl;
				active ? list1.clear() : list2.clear();
				} break;
			// Выйти из программы
			case 'e': {
				return 0;
				} break;
			}
			system("pause");
		}
		in.clear();
	}
}