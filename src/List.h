#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

// Implment Circular Doubly Linked List

typedef int Item;

struct Node {
    Item item;
    Node *next;
    Node *prev;

    Node(const Item &i, Node *nextnode = nullptr, Node *prevnode = nullptr){
        item = i;
        next = nextnode;
        prev = prevnode;
    }
};

class List {
    private:
        Node *head;
        int m_size;
        
    public:
        List(); 

        List(const List &lst); 

        ~List(); 

        bool empty() const; 

        size_t size() const; 

        void clear(); 

        Item &front(); 

        Item &back(); 

        void push_front(const Item &data); 

        void push_back(const Item &data); 

        void pop_front(); 

        void pop_back(); 

        void insertAt(const Item &data, int index); 

        void removeAt(int index); 

        void removeAll(const Item &data); 

        void swap(List &lst); 

        void concat(List &lst); 

        void *copy(); 

        void append(Item vec[], int n); 

        bool equals(const List &lst) const; 

        void reverse(); 

        void merge(List &lst); 

        friend std::ostream &operator<<(std::ostream &out, const List &lst); 

        Item &operator[](int index); 

        List &operator=(const List &lst);
};

List::List() {
    head = nullptr;
    m_size = 0;
}

List::List(const List &lst) {
    
}

List::~List() {
    clear();
}

bool List::empty() const {
    return head == nullptr;
}

size_t List::size() const {
    return m_size;
}

void List::clear() {

}

Item& List::front() {
    return head->item;
}

Item& List::back() {
    if(empty()) {
        throw std::out_of_range("List is empty");
    }
    return head->prev->item;
}

void List::push_front(const Item &data) {

}

void List::push_back(const Item &data) {

}

void List::pop_front() {

}

void List::pop_back() {

}

void List::insertAt(const Item &data, int index) {

}

void List::removeAt(int index) {

}

void List::removeAll(const Item &data) {

}

void List::swap(List &lst) {

}

void List::concat(List &lst) {

}

void *List::copy() {

}

void List::append(Item vec[], int n) {

}

bool List::equals(const List &lst) const {

}

void List::reverse() {

}

void List::merge(List &lst) {

}

std::ostream &operator<<(std::ostream &out, const List &lst) {

}

Item &List::operator[](int index) {

}

List &List::operator=(const List &lst) {

}

#endif