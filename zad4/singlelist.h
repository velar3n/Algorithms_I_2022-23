#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>
#include <cassert>

template <typename T>
struct SingleNode {
    T value;
    SingleNode *next;

    SingleNode() : value(T()), next(nullptr) {}
    SingleNode(const T& item, SingleNode *ptr=nullptr) : value(item), next(ptr) {}
    ~SingleNode() {}
};

template <typename T>
class SingleList {
    SingleNode<T> *head, *tail;
public:
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList();
    SingleList(const SingleList& other){
        if(other.head == nullptr){
            head = nullptr;
        } else{
            SingleNode<T> *newNode = new SingleNode<T>;
            newNode->value = other.head->value;
            newNode->next = nullptr;
            head = newNode;
            SingleNode<T> *otherNode = other.head->next;
            SingleNode<T> *node = head;
            while(otherNode != nullptr){
                node->next = new SingleNode<T>;
                node->next->value = otherNode->value;
                node->next->next = nullptr;
                node = node->next;
                otherNode = otherNode->next;
            }
        }
    }

    SingleList& operator=(const SingleList& other){
        if(this == &other){
            return *this;
        }
        SingleList<T> singlelist(other);
        std::swap(singlelist.head, head);
        std::swap(singlelist.tail, tail);
        return *this;
    }

    bool empty() const{ return head == nullptr; }
    int size() const { return tail; };
    T& front() const { return head->value; }
    T& back() const { return tail->value; }

    void push_front(const T& item);
    void push_back(const T& item);
    void pop_front();
    void pop_back();
    void display();
    void clear();
    void reverse();


    T& operator[](int pos); // podstawienie L[pos]=item, odczyt L[pos]
    const T& operator[](int pos) const; // dostep do obiektu const
    void erase(int pos);
    int index(const T& item); // jaki index na liscie (-1 gdy nie ma) O(n)
    void insert(int pos, const T& item); // inserts item before pos
    // Jezeli pos=0, to wstawiamy na poczatek.
    // Jezeli pos=size(), to wstawiamy na koniec.
};

template <typename T>
SingleList<T>::~SingleList() {
    for (SingleNode<T> *node; !empty(); ) {
        node = head->next; // zapamietujemy
        delete head;
        head = node; // kopiowanie wskaznika
    }
}

template <typename T>
void SingleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new SingleNode<T>(item, head);
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::push_back(const T& item) {
    if (!empty()) {
        tail->next = new SingleNode<T>(item);
        tail = tail->next;
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::display() {
    SingleNode<T> *node = head;
    while (node != nullptr){
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void SingleList<T>::pop_front() {
    assert(!empty());
    SingleNode<T> *node = head; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        head = head->next;
    }
    delete node;
}

template <typename T>
void SingleList<T>::pop_back() {
    assert(!empty());
    SingleNode<T> *node = tail; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        // Szukamy poprzednika ogona.
        SingleNode<T> *before=head;
        while (before->next != tail) {
            before = before->next;
        }
        tail = before;
        tail->next = nullptr;
    }
    delete node;
}

template <typename T>
void SingleList<T>::clear() {
    if(empty()){
        return;
    }
    SingleNode<T> *node = head;
    while(!empty()){
        head = head->next;
        delete node;
        node = head;
    }
    return;
}

template <typename T>
void SingleList<T>::reverse() {
    if(empty()){
        return;
    }
    SingleNode<T> *node = head;
    SingleNode<T> *prev = nullptr;
    SingleNode<T> *nxt = nullptr;
    while (node != nullptr) {
      nxt = node->next;
      node->next = prev;
      prev = node;
      node = nxt;
    }
    head = prev;
}


#endif