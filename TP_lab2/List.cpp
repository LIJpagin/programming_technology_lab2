#include "List.h"

int  List::size() const {
    Item* temp = head_;
    int size = 0;
    while (temp != tail_)
        size++, temp = temp->next;
    return ++size;
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
    try {
        array = new int[size()];
        Item* temp = head_;
        auto counter = 0;
        while (temp != tail_)
            array[counter++] = temp->data, temp = temp->next;
        array[counter++] = temp->data;
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
}

std::ostream& operator<< (std::ostream& out, const List& list) {
    int* array = list.getArray();
    for (int i = 0; i < list.size(); i++)
        out << array[i] << " ";
    return out;
}