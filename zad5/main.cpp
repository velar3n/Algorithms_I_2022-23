#include <iostream>
#include "doublelist.h"

int test(){

	int size = 0;

	DoubleList<int> doublelist;
	assert(doublelist.empty());
	std::cout<<"Test 1 passed"<<std::endl;

	doublelist.push_front(1);
	doublelist.push_front(2);
	doublelist.push_front(3);
	doublelist.push_front(4);
	assert(doublelist.front() == 4);
	assert(doublelist.back() == 1);
	std::cout<<"Test 2 passed"<<std::endl;

	doublelist.display_reversed();
	std::cout<<"Test 3 passed"<<std::endl;

	doublelist.display();
	std::cout<<"Test 4 passed"<<std::endl;


	doublelist.push_back(7);
	doublelist.push_back(8);
	doublelist.push_back(9);
	doublelist.push_back(10);
	assert(doublelist.front() == 4);
	assert(doublelist.back() == 10);
	std::cout<<"Test 5 passed"<<std::endl;

	size = doublelist.size();
	assert(size == 8);
	std::cout<<"Test 6 passed"<<std::endl;

	doublelist.pop_front();
	assert(doublelist.front() == 3);
	assert(doublelist.back() == 10);
	assert(doublelist.size() == 7);
	std::cout<<"Test 7 passed"<<std::endl;

	doublelist.pop_back();
	assert(doublelist.front() == 3);
	assert(doublelist.back() == 9);
	assert(doublelist.size() == 6);
	std::cout<<"Test 8 passed"<<std::endl;

	DoubleList<int> doublelist2(doublelist);
	doublelist.display();
	doublelist2.display();
	std::cout<<"Test 9 passed"<<std::endl;

	
	doublelist.clear();
	assert(doublelist.empty());
	std::cout<<"Test 10 passed"<<std::endl;
	return 0;
}

int main(){

	test();

	return 0;
}