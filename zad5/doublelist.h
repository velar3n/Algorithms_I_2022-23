#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <cassert> 

template <typename T>
struct DoubleNode {
    T value;
    DoubleNode *next, *prev;
    DoubleNode() : value(T()), next(nullptr), prev(nullptr) {}
    DoubleNode(const T& item, DoubleNode *nptr=nullptr, DoubleNode *pptr=nullptr): value(item), next(nptr), prev(pptr) {}
    ~DoubleNode() {}
};


template <typename T>
class DoubleList {
    DoubleNode<T> *head, *tail;
public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList(){
        DoubleNode<T> *node = head;
        while(node  != nullptr){
            DoubleNode<T> *next = node->next;
            delete node;
            node = next;
        }
        head = 0;
    }

    DoubleList(const DoubleList& other){
        if(other.head == nullptr){
            head = nullptr;
        } else{
            DoubleNode<T> *node = other.head;
            head = tail = new DoubleNode<T>;
            head->prev = nullptr;
            head->value = node->value;
            node = node->next;
            if(node->next == nullptr){
                head->next = nullptr;
            } else{
                DoubleNode<T> *otherNode = head;
                while(node != nullptr){
                    otherNode->next = new DoubleNode<T>;
                    otherNode->next->prev = otherNode;
                    otherNode = otherNode->next;
                    otherNode->value = node->value;
                    node = node->next;
                }
                otherNode->next = nullptr;
                tail = otherNode;
            }
        }
    } // copy constructor

    DoubleList& operator=(const DoubleList& other){
        if(this == &other){
            return *this;
        }
        DoubleList<T> doublelist(other);
        std::swap(doublelist.head, head);
        std::swap(doublelist.tail, tail);
        return *this;
    } // copy assignment operator, return *this


    bool empty() const { return head == nullptr; }
    T& front() const { return head->value; }
    T& back() const { return tail->value; }
    int size() const; 
    void push_front(const T& item);
    void push_front(T&& item);
    void push_back(const T& item);
    void push_back(T&& item);
    void pop_front(); // usuwa poczatek O(1)
    void pop_back(); // usuwa koniec O(n)
    void clear(); // czyszczenie listy z elementow O(n)
    void display();
    void display_reversed();
};

template <typename T>
int DoubleList<T>::size() const{
    DoubleNode<T> *node = head;
    int size = 0;
    while (node != nullptr){
        size++;
        node = node->next;
    }
    return size;

}

template <typename T>
void DoubleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new DoubleNode<T>(item, head);
        head->next->prev = head;
    } else {
        head = tail = new DoubleNode<T>(item);
    }
}

template <typename T>
void DoubleList<T>::push_front(T&& item) {
    if (!empty()) {
        head = new DoubleNode<T>(std::move(item), head);
        head->next->prev = head;
    } else {
        head = tail = new DoubleNode<T>(std::move(item));
    }
}

template <typename T>
void DoubleList<T>::push_back(const T& item){
    if (!empty()) {
        DoubleNode<T> *node = new DoubleNode<T>(item, nullptr, tail);
        tail->next = node;
        tail = node;
    } else {
        head = tail = new DoubleNode<T>(item);
    }
}

template <typename T>
void DoubleList<T>::push_back(T&& item){
    if (!empty()) {
        DoubleNode<T> *node = new DoubleNode<T>(std::move(item), nullptr, tail);
        tail->next = node;
        tail = node;
    } else {
        head = tail = new DoubleNode<T>(std::move(item));
    }
}

template <typename T>
void DoubleList<T>::pop_front(){
    if(empty()){
        return;
    }
    DoubleNode<T> *node = head;
    head = node->next;
    delete node;
}

template <typename T>
void DoubleList<T>::pop_back(){
    if(empty()){
        return;
    }
    DoubleNode<T> *node = tail;
    tail = node->prev;
    tail->next = nullptr;
    delete node;
}

template <typename T>
void DoubleList<T>::clear(){
    if(empty()){
        return;
    }
    DoubleNode<T> *node = head;
    while(head != nullptr){
        node = head;
        head = head->next;
        free(node);
    }
}

template <typename T>
void DoubleList<T>::display(){
    if(empty()){
        return;
    }
    DoubleNode<T> *node = head;
    while(node != nullptr){
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DoubleList<T>::display_reversed(){
    if(empty()){
        return;
    }
    DoubleNode<T> *node = tail;
    while(node != nullptr){
        std::cout << node->value << " ";
        node = node->prev;
    }
    std::cout << std::endl;
}

#endif