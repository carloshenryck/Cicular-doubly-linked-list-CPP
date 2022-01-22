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

        List *copy(); 

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
    if(lst.empty()) {
        head = nullptr;
        m_size = 0;
    }else{
        head = new Node(lst.head->item);
        head->next = head;
        head->prev = head;
        m_size = 1;
        Node *currente = lst.head->next;
        while(currente != lst.head) {
            push_back(currente->item);
            currente = currente->next;
        }
    }
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
    if(!empty()) {
        Node *current = head->next;
        Node *next;
        while(current != head) {
            next = current->next;
            delete current;
            current = next;
        }
        delete head;
        head = nullptr;
        m_size = 0;
    }
}

// Funcao com decisao de projeto
Item& List::front() {
    if(empty()) {
        throw std::out_of_range("List is empty");
    }
    return head->item;
}

Item& List::back() {
    if(empty()) {
        throw std::out_of_range("List is empty");
    }
    return head->prev->item;
}

void List::push_front(const Item &data) {
    if(empty()) {
        head = new Node(data);
        head->next = head;
        head->prev = head;
    }else{
        Node *last = head->prev;

        Node *newNode = new Node(data);
        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;

        head = newNode;
    }
    m_size++;
}

void List::push_back(const Item &data) {
    if(empty()) {
        head = new Node(data);
        head->next = head;
        head->prev = head;
    }else{
        Node *last = head->prev;

        Node *newNode = new Node(data);
        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }
    m_size++;
}

// 1 - Henryck
void List::pop_front() {
    if(empty()) {
        throw std::out_of_range("List is empty");
    }
    else if(m_size == 1) {
        head = nullptr;
        m_size = 0;
    } else {
        Node *last = head->prev;
    
        head = head->next;
        head->prev = last;
        last->next = head;
        m_size--;
    }
}

// 2 - Vitor
void List::pop_back() {
    if(empty()) {
        throw std::out_of_range("List is empty");
    }
    else if(m_size == 1) {
        head = nullptr;
        m_size = 0;
    }else{
        Node *last = head->prev;

        head->prev = last->prev;
        last->prev->next = head;

        delete last;
        m_size--;
    }
}

// 3 - Vitor
void List::insertAt(const Item &data, int index) {
    if(index < 0 || index > m_size) {
        throw std::out_of_range("Index out of range");
    }else if(index == 0) {
        push_front(data);
    }else{
        Node *newNode = new Node(data);
        Node *current = head;
        for(int i = 0; i < index-1; i++) {
            current = current->next;
        }
        current->next->prev = newNode;
        newNode->next = current->next;
        current->next = newNode;
        newNode->prev = current;
        m_size++;
    }
}

// 4 - Henryck
void List::removeAt(int index) {
    if(index >= 0 && index <= m_size - 1) {
        if(index == 0) {
            pop_front();
        } else if(index == m_size - 1) {
            pop_back();
        } else {
            Node *temp = head;
            while(index > 0) {
                temp = temp->next;
                index--;
            }

            Node *tempPrev = temp->prev;
            tempPrev->next = temp->next;
            temp->next->prev = tempPrev;
            delete temp;
            m_size--;
        }
    } else {
        throw std::out_of_range("Index out of range");
    }
}

// 5 - Vitor
void List::removeAll(const Item &data) {
    if(!empty()) {
        if(m_size == 1 && head->item == data) {
            head = nullptr;
            m_size = 0;
        }else{
            Node *current = head->next;
            Node *temp = nullptr;
            while(current != head){
                if(current->item == data) {
                    temp = current;
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    current = current->next;
                    delete temp;
                    m_size--;
                }else{
                    current = current->next;
                }
            }
            if(current->item == data) {
                temp = current;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                head = current->next;
                delete temp;
                m_size--;
            }
        }
    }
}

// 6 - Vitor
void List::swap(List &lst) {
    if(!empty() && !lst.empty()) {
        Node *temp = head;
        head = lst.head;
        lst.head = temp;
        int aux = m_size;
        m_size = lst.m_size;
        lst.m_size = aux;
    }
}

// 7 - Vitor
void List::concat(List &lst) {
    if(!lst.empty()) {
        push_back(lst.head->item);
        Node *current = lst.head->next;
        while(current != lst.head) {
            push_back(current->item);
            current = current->next;
        }
        lst.clear();
    }
}

// 8 - Henryck
List *List::copy() {
    List *copy = new List();

    if(empty()) {
        return copy;
    }

    copy->push_back(head->item);
    Node* current = head->next;

    while(current != head) {
        copy->push_back(current->item);
        current = current->next;
    }
    
    return copy;
}

// 9 - Vitor
void List::append(Item vec[], int n) {
    for(int i=0; i<n; i++) {
        push_back(vec[i]);
    }
}

// 10 - Henryck
bool List::equals(const List &lst) const {
    if(empty() && lst.empty()) {
        return true;
    } else if(m_size != lst.m_size) {
        return false;
    } else {
        if(head->item == lst.head->item) {
            Node *current = head->next;
            Node *lstCurrent = lst.head->next;
            while(current != head) {
                if(current->item != lstCurrent->item){
                    return false;
                }
                current = current->next;
                lstCurrent = lstCurrent->next;
            }
            return true;
        }
    }
    return false;
}

// 11 - Vitor
void List::reverse() {
    if(!empty() || m_size != 1){
        Node *current = head->next;
        Node *temp = nullptr;
        while(current != head) {
            temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = temp;
        }
        current->next = head->prev;
        current->prev = head->next;
        head = current->next;
    }
}


void List::merge(List &lst) {
    if(lst.empty()) {
        throw std::out_of_range("the list passed is empty");
    } else if(empty()) {
        *this = lst;
        lst.clear();
    } else {
        Node *current = lst.head;
        int count = 0;

        for(int i = 1; i < m_size; i+=2) {
            insertAt(current->item, i);
            current = current->next;
            count++;
        }

        if(count < lst.m_size) {
            for(int i = 0; i < lst.m_size-count; i++) {
                push_back(current->item);
                current = current->next;
            }
        }
        lst.clear();
    }
}

// 12 - Henryck
std::ostream &operator<<(std::ostream &out, const List &lst) {
    if(lst.empty()) {
        return out;
    }

    Node *current = lst.head->next;

    out << lst.head->item << " ";
    while(current != lst.head) {
        out << current->item << " ";
        current = current->next;
    }
    return out;
}

// 13 - Henryck
Item &List::operator[](int index) {
    if(empty() || index >= m_size || index < 0) {
        throw std::out_of_range("Index out of range");
    } else if(index == 0) {
        return front();
    } else if(index == m_size - 1) {
        return back();
    } else {
        Node* temp = head;
        while(index > 0) {
            temp = temp->next;
            index--;
        }

        return temp->item;
    }
}

// 14 - Henryck
List &List::operator=(const List &lst) {
    clear();
    if(lst.empty()) {
        return *this;
    }
    push_back(lst.head->item);

    Node* current = lst.head->next;
    while(current != lst.head) {
        push_back(current->item);
        current = current->next;
    }

    return *this;
}

#endif