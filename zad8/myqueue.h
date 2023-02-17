#include <iostream>

template <typename T>
class MyQueue {
    T* tab;
    int msize; // największa możliwa liczba elementów plus jeden
    int head; // pierwszy do pobrania
    int tail; // pierwsza wolna pozycja
public:
    MyQueue(int s=10) : msize(s+1), head(0), tail(0) {
        tab = new T[s+1];
        assert( tab != nullptr );
    } // default constructor
    ~MyQueue() { delete [] tab; }

    MyQueue(const MyQueue& other){
        tab = new T[other.msize];
        for (int i = 0; i < other.msize; i++){
            tab[i] = other.tab[i];
        }
        msize = other.msize;
        head = other.head;
        tail = other.tail;
    }; // copy constructor
    MyQueue& operator=(const MyQueue& other){
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
    }; // copy assignment operator, return *this

    MyQueue(MyQueue&& other) noexcept : tab(other.tab), msize(other.msize), head(other.head), tail(other.tail) {
        other.tab = nullptr;
        other.msize = 0;
        other.head = 0;
        other.tail = 0;
    }; // move constructor
    MyQueue& operator=(MyQueue&& other) noexcept {
        if(this == &other){
            return *this;
        }
        delete[] tab;
        tab = other.tab;
        msize = other.msize;
        head = other.head;
        tail = other.tail;
        tab = nullptr;
        other.msize = 0;
        other.head = 0;
        other.tail = 0;
        return *this;
    }; // move assignment operator, return *this

    bool empty() const { return head == tail; }
    bool full() const { return (head + msize -1) % msize == tail; }
    int size() const { return (tail - head + msize) % msize; }
    int max_size() const { return msize-1; }
    T& front() { return tab[head]; } // zwraca początek
    T& back() { return tab[(tail + msize -1) % msize]; } // zwraca koniec
    void push(const T& item); // dodanie na koniec
    void push(T&& item); // dodanie na koniec
    void display();

    void pop(); // usuwa początek
    void clear(); // czyszczenie listy z elementów
};

template <typename T>
void MyQueue<T>::push(const T& item) {
    tab[tail] = item;
    tail = (tail + 1) % msize;
}

template <typename T>
void MyQueue<T>::push(T&& item) {
    tab[tail] = std::move(item);
    tail = (tail + 1) % msize;
}

template <typename T>
void MyQueue<T>::display() {
    for (int i = head; i != tail; i=(i+1) % msize) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>                       //dodać zamazywanie starych elementow
void MyQueue<T>::pop(){
    if(empty()){
        return;
    }
    head = (head + msize +1) % msize;
}

template <typename T>                       //dodać zamazywanie starych elementów
void MyQueue<T>::clear(){
    if(empty()){
        return;
    }
    head = 0;
    tail = 0;
}
