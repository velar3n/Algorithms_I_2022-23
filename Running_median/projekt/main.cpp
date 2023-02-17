#include <iostream>
#include <cassert>

#include "maxheap.h"
#include "minheap.h"
#include "median.h"

int main(){

    std::cout<<"Przykład użycia 1: "<<std::endl;

    double A[] = {5, 2, 1, 3, 2, 8, 7, 9, 2, 6, 2, 4};
    double assert1[] = {5, 3.5, 2, 2.5, 2, 2.5, 3, 4 ,3 ,4, 3, 3.5};
    int size = sizeof(A)/sizeof(A[0]);

    MaxHeap maxHeapA = MaxHeap(size);        //Max Heap
    MinHeap minHeapA = MinHeap(size);        //Min Heap
    double median = 0;

    std::cout<<"\nMediana krocząca: \n\n";
    for(int i = 0; i < size; i++) {
        median = heapMedian(A[i], median, maxHeapA, minHeapA);
        assert(median == assert1[i]);
        std::cout<<"Przyjęty element "<<A[i]<<" --> mediana = "<<median<<std::endl;
    }

    std::cout<<std::endl;


    std::cout<<"Przykład użycia 2: "<<std::endl;
    double B[] = {5.12, 0.334, 12.3, 55.0, 1.11, 89.09, 16.0, 7.0001, 21.0, 26.98, 2.0};
    double assert2[] = {5.12, 2.727, 5.12, 8.71, 5.12, 8.71, 12.3, 9.65005, 12.3, 14.15, 12.3};
    size = sizeof(B)/sizeof(B[0]);

    MaxHeap maxHeapB = MaxHeap(size);        //Max Heap
    MinHeap minHeapB = MinHeap(size);        //Min Heap

    std::cout<<"\nMediana krocząca: \n\n";
    for(int i = 0; i < size; i++) {
        double median = heapMedian(B[i], median, maxHeapB, minHeapB);
        assert(median == assert2[i]);
        std::cout<<"Przyjęty element "<<B[i]<<" --> mediana = "<<median<<std::endl;
    }

    std::cout<<std::endl;

    return 0;
}