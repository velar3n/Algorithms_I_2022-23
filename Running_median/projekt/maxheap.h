// implementacja sterty na bazie tablicy

#include <iostream>
#include <cassert>

class MaxHeap { 
    double* array; 							        // tablica na której bazuje sterta
    int max_size; 									// maksymalny rozmiar sterty = maksymalna liczba elementów
    int size;                                       // aktualny rozmiar sterty = aktualna liczba elemetów

public: 
    MaxHeap(int max_size) : max_size(max_size), size(0) {       // konstruktor parametrowy
        array = new double[max_size + 1];
    } 

    ~MaxHeap() {                                    // destruktor
        delete[] array;
    }

    int getParentIndex(int index) {                 // zwraca index rodzica
        return (index-1)/2;
    }

    int getLeftChildIndex(int index) {              // zwraca index lewego dziecka
        return 2*index + 1;
    }

    int getRightChildIndex(int index) {             // zwraca index prawego dziecka
        return 2*index + 2;
    }

    int getSize() {                                 // zwraca aktualny rozmiar tablicy
        return size;
    }

    double getTop() {                               // zwraca korzeń sterty
        return array[0];
    }

    bool full() const {                             // zwraca czy tablica, na podstawie której bazuje drzewo, jest pełna
        return (max_size == size);
    }

    double popTop() {                               // usuwa korzeń sterty i zwraca jego wartość
        if(size == 0) {
            return 0;
        } else if (size == 1) { 
            size--; 
            return array[0]; 
        } else {
            double root = array[0];
            array[0] = array[size - 1];
            size --;
            heapify(0);
            return root;
        }
    }

    void insert(const double item) {                // dodaje element "item" do sterty
        assert(!full());

        array[size] = item;
        size ++;

        int i = size - 1;
        while((i != 0) && (array[i] > array[getParentIndex(i)])) {
            std::swap(array[i], array[getParentIndex(i)]); 
            i = getParentIndex(i); 
        }
    }

    void heapify(int index) {                       // zamienia drzewo w postaci tablicy w stertę
        int leftIndex = getLeftChildIndex(index);
        int rightIndex = getRightChildIndex(index);
        int current_index = index;

        if((leftIndex < size) && (array[leftIndex] > array[index])) {
            current_index = leftIndex;
        }
        if((rightIndex < size) && (array[rightIndex] > array[current_index])) {
            current_index = rightIndex;
        }
        if (current_index != index) {
            std::swap(array[index], array[current_index]); 
            heapify(current_index);
        }
    }
}; 
