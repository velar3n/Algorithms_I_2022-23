#include <iostream>

double heapMedian(double item, double median, MaxHeap &maxHeap, MinHeap &minHeap) {

    // Sterty są równej wielkośći
	if(maxHeap.getSize() == minHeap.getSize()) {
        if (item < median) {                                    // element powinien się znajdować w maxHeap
            maxHeap.insert(item);
            median = maxHeap.getTop();
        }
        else {                                                  // element powinien się znajdować w minHeap
            minHeap.insert(item);
            median = minHeap.getTop();
        }
    // Więcej elementów w maxHeap
	} else if(maxHeap.getSize() > minHeap.getSize()) {
		if (item < median) {                                    // element powinien się znajdować w maxHeap
            minHeap.insert(maxHeap.popTop());                   // usuwamy top element z maxHeap i dodajemy go do minHeap
            maxHeap.insert(item);                               // element powinien się znajdować w maxHeap
        } else {
            minHeap.insert(item);                               // element powinien się znajdować w minHeap
        }
        median = (maxHeap.getTop() + minHeap.getTop()) / 2;

    // Więcej elementów w minHeap
	} else {
		if (item < median){                                     // element powinien się znajdować w maxHeap
            maxHeap.insert(item);
        }
        else {                                                  // usuwamy top element z minHeap i dodajemy go do maxHeap
            maxHeap.insert(minHeap.popTop());
            minHeap.insert(item);
        }
        median = (maxHeap.getTop() + minHeap.getTop()) / 2; 
	}

    return median;
}
