#include <iostream>

template <typename T>
class MyDeque {
    T* tab;
    int msize; // największa możliwa liczba elementów plus jeden
    int head; // pierwszy do pobrania
    int tail; // pierwsza wolna pozycja
public:
    MyDeque(int s=10) : msize(s+1), head(0), tail(0) {
        tab = new T[s+1];
        assert( tab != nullptr );
    } // default constructor
    ~MyDeque() { delete [] tab; }

    MyDeque(const MyDeque& other) {
        tab = new T[other.msize];
        for (int i = 0; i < other.msize; i++){
            tab[i] = other.tab[i];
        }
        msize = other.msize;
        head = other.head;
        tail = other.tail;
    } // copy constructor

    MyDeque& operator=(const MyDeque& other){
        if(this == &other){
            return *this;
        }
        delete[] tab;
        tab = new T[other.msize];
        for (int i = 0; i < other.msize; i++){
            tab[i] = other.tab[i];
        }
        msize = other.msize;
        head = other.head;
        tail = other.tail;
        return *this;
    } // copy assignment operator, return *this

    bool empty() const { return head == tail; }
    bool full() const { return (tail + 1) % msize == head; }
    int size() const { return (tail - head + msize) % msize; }
    int max_size() const { return msize-1; }
    T& front() { return tab[head]; }
    T& back() { return tab[(tail + msize -1) % msize]; }

    void push_front(const T& item);
    void push_back(const T& item);
    void display();
    void pop_front(); // usuwa początek kolejki O(1)
    void pop_back(); // usuwa koniec kolejki O(1)
    void clear(); // czyszczenie listy z elementow

    // Operacje z indeksami. NIEOBOWIĄZKOWE
    T& operator[](int pos); // podstawienie L[pos]=item, odczyt L[pos]
    const T& operator[](int pos) const; // dostęp do obiektu const
    void erase(int pos);
    int index(const T& item); // jaki index na liście (-1 gdy nie ma)
    void insert(int pos, const T& item); // inserts item before pos
    void insert(int pos, T&& item); // inserts item before pos
};

template <typename T>
void MyDeque<T>::push_front(const T& item) {
    head = (head + msize -1) % msize;
    tab[head] = item;
}

template <typename T>
void MyDeque<T>::push_back(const T& item) {
    tab[tail] = item;
    tail = (tail + 1) % msize;
}

template <typename T>
void MyDeque<T>::display() {
    for (int i = head; i != tail; i=(i+1) % msize) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void MyDeque<T>::pop_front(){
    if(empty()){
        return;
    }
    head = (head + msize +1) % msize;
}

template <typename T>
void MyDeque<T>::pop_back(){
    if(empty()){
        return;
    }
    tail = (tail - 1) % msize;
}

template <typename T>
void MyDeque<T>::clear(){
    if(empty()){
        return;
    }
    head = 0;
    tail = 0;
}