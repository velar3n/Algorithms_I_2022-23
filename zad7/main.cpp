#include <iostream>
#include <vector>
#include <cassert> 

#include "rpn.h"

int test(){

	std::vector<std::string> input1 { "-6", "2", "/" };																// przykład z zajęć
	assert(rpn(input1) == -3);
	std::cout<<"Test 1 passed"<<std::endl;

	std::vector<std::string> input2 { "2", "3", "5", "-", "3", "*", "+" };											// własny przykład
	assert(rpn(input2) == -4);
	std::cout<<"Test 2 passed"<<std::endl;

	std::vector<std::string> input3 { "12", "2", "3", "4", "*", "10", "5", "/", "+", "*", "+" };					// przykład z Wikipedii
	assert(rpn(input3) == 40);
	std::cout<<"Test 3 passed"<<std::endl;


	return 0;

}

int main(){

	test();

	return 0;
}