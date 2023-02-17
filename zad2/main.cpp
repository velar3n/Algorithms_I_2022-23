#include <algorithm>
#include <iostream>
#include <iterator>
#include <cassert>
#include <vector>
#include <array>

#include "bubbleSort.h"
#include "mergeSort.h"

int main() {
  
    std::vector<int> vB = { 9,4,7,3,6,8,2,1,5,0 };                  /*tablice i wektory ze strony */
    std::array<int, 10> vB2 = { { 9,4,7,3,6,8,2,1,5,0 } };
    int vB3[] = { 9,4,7,3,6,8,2,1,5,0 };
    std::vector<int> vM = { 9,4,7,3,6,8,2,1,5,0 };
    std::array<int, 10> vM2 = { { 9,4,7,3,6,8,2,1,5,0 } };
    int vM3[] = { 9,4,7,3,6,8,2,1,5,0 };
    
    bubbleSort(std::begin(vB), std::end(vB));                   /* wykonanie sortowań */
    bubbleSort(std::begin(vB2), std::end(vB2));
    bubbleSort(std::begin(vB3), std::end(vB3));
    mergeSort(std::begin(vM), std::end(vM));
    mergeSort(std::begin(vM2), std::end(vM2));
    mergeSort(std::begin(vM3), std::end(vM3));

    assert( std::is_sorted(std::begin(vB2), std::end(vB2)) );   // zwykła tablica                 /* testy */
    assert( std::is_sorted(vB.begin(), vB.end()) );   // vector, array      
    assert( std::is_sorted(vB3, vB3 + (sizeof(vB3) / sizeof(*vB3))) );   // zwykła tablica
    assert( std::is_sorted(std::begin(vM2), std::end(vM2)) );   // zwykła tablica
    assert( std::is_sorted(vM.begin(), vM.end()) );   // vector, array
    assert( std::is_sorted(vM3, vM3 + (sizeof(vM3) / sizeof(*vM3))) );   // zwykła tablica

    printf("All tests correct (6)\n\n");
  
    return 0;
}