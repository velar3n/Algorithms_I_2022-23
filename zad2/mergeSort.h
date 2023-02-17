#include <algorithm>
#include <iostream>
#include <iterator>

template <typename Iterator>														/* templatka i funkcja sortująca merge sort */
void mergeSort(Iterator first, Iterator last){
	if (last <= first + 1){ 
 		return;
 	}

    Iterator middle = first + (last - first) / 2;
    mergeSort(first, middle);
    mergeSort(middle, last);
    std::inplace_merge(first, middle, last);
}