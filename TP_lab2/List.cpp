#include "List.h"

List::List(int value, ...) {
    va_list vl;
    va_start(vl, value);
    for (auto i = 0; i < value; i++)
        pushBack(va_arg(vl, int));
    va_end(vl);
}
List::List(const List& that) {
    if (that.isEmpty()) {
        this->head_ = this->tail_ = nullptr;
        return;
    }
    Item* temp = that.head_;
    do this->pushBack(temp->data), temp = temp->next;
    while (temp != that.head_);
}

void List::random(int size = 10, int min = -100, int max = 100) {
    clear();
    srand(time(NULL));
    size = rand() * (size + 1);
    for (auto i = 0; i < size; i++)
        pushBack(rand() * (max - min + 1) + min);
}
int  List::size() const {
    if (isEmpty()) return 0;
    Item* temp = head_;
    int size = 0;
    do size++, temp = temp->next;
    while (temp != head_);
    return size;
}
bool List::isEmpty() const {
	return !((bool)head_);
}
void List::pushFront(int value) {
    try {
        Item* temp = new Item;
        temp->data = value, temp->next = nullptr;
        if (!head_) head_ = temp, tail_ = temp;
        else temp->next = head_, head_ = temp, tail_->next = temp;
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
void List::pushBack(int value) {
    try {
        Item* temp = new Item;
        temp->data = value, temp->next = nullptr;
        if (!head_) head_ = temp, tail_ = temp;
        else tail_->next = temp, tail_ = temp, temp->next = head_;
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
int  List::popFront() {
    if (isEmpty()) throw new std::exception("Error: The list is empty!");
    Item* temp = head_;
    int data = temp->data;
    head_ = temp->next, tail_->next = head_;
    delete temp;
    return data;
}
int  List::popBack() {
    if (isEmpty()) throw new std::exception("Error: The list is empty!");
    Item* temp = tail_;
    int data = temp->data;
    temp = head_;
    while (temp->next != tail_)
        temp = temp->next;
    tail_ = temp, temp = temp->next;
    delete temp;
    tail_->next = head_;
    return data;
}
int  List::front() const {
    if (isEmpty()) throw new std::exception("Error: The list is empty!");
    return head_->data;
}
int  List::back() const {
    if (isEmpty()) throw new std::exception("Error: The list is empty!");
    return tail_->data;
}
int* List::getArray() const {
    int* array = nullptr;
    if (isEmpty()) return array;
    try {
        array = new int[size()];
        Item* temp = head_;
        auto counter = 0;
        do array[counter++] = temp->data, temp = temp->next;
        while (temp != head_);
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return array;
}
void List::clear() {
    while (head_ != tail_) {
        Item* temp = head_;
        head_ = temp->next;
        delete temp;
    }
    head_ = nullptr, tail_ = nullptr;
}

std::ostream& operator<< (std::ostream& out, const List& list) {
    int* array = list.getArray();
    for (int i = 0; i < list.size(); i++)
        out << array[i] << " ";
    return out;
}

List& List::operator++() {
    pushFront(0);
    return *this;
}
List& List::operator--() {
    popFront();
    return *this;
}
List& List::operator++(int) {
    pushBack(0);
    return *this;
}
List& List::operator--(int) {
    popBack();
    return *this;
}

List& List::operator= (const List& that) {
    this->clear();
    if (that.isEmpty()) {
        this->head_ = this->tail_ = nullptr;
        return *this;
    }
    Item* temp = that.head_;
    do this->pushBack(temp->data), temp = temp->next;
    while (temp != that.head_);
    return *this;
}
//List operator+ (const List& l1, const List& l2) {
//    if (l1.isEmpty()) return l2;
//    if (l2.isEmpty()) return l1;
//    List list;
//    Item* temp1 = l1.head_, * temp2 = l2.head_;
//    do {
//        list.pushBack(temp1->data + temp2->data);
//        temp1 = temp1->next, temp2 = temp2->next;
//    }
//    while (temp1 != l1.head_ || temp2 != l2.head_);
//    return list;
//}
//List operator- (const List& l1, const List& l2) {
//
//}
//List operator* (const List& l1, const List& l2) {
//
//}
//List operator/ (const List& l1, const List& l2) {
//
//}