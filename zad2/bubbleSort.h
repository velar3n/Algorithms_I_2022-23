#include <algorithm>
#include <iostream>
#include <iterator>

template <typename Iterator>														/* templatka i funkcja sortująca bubble sort */
void bubbleSort(Iterator first, Iterator last){
    for (Iterator i = first; i != last; i++){
    	for (Iterator j = first; j < i; j++){
        	if (*i < *j){
            	std::iter_swap(i, j);
        	}
    	}
    }
}
