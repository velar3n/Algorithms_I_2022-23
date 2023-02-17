#include <iostream>
#include <cassert>

#include "singlelist.h"

int test(){		
	SingleList<int> singlelist;
	assert(singlelist.empty());
	std::cout<<"Test 1 passed"<<std::endl;

	singlelist.push_front(1);
	singlelist.push_front(2);
	singlelist.push_front(3);
	singlelist.push_front(4);
	singlelist.push_front(5);
	singlelist.push_front(6);
	assert(singlelist.front() == 6);
	assert(singlelist.back() == 1);
	std::cout<<"Test 2 passed"<<std::endl;

	singlelist.push_back(9);
	assert(singlelist.back() == 9);
	std::cout<<"Test 3 passed"<<std::endl;

	singlelist.pop_front();
	assert(singlelist.front() == 5);
	std::cout<<"Test 4 passed"<<std::endl;

	singlelist.pop_back();
	assert(singlelist.back() == 1);
	std::cout<<"Test 5 passed"<<std::endl;

	SingleList<int> singlelist2(singlelist);
	singlelist2.display();
	singlelist.display();
	std::cout<<"Test 6 passed"<<std::endl;

	singlelist.reverse();
	assert(singlelist.front() == 1);
	std::cout<<"Test 7 passed"<<std::endl;

	singlelist.clear();
	assert(singlelist.empty());
	std::cout<<"Test 8 passed"<<std::endl;


	return 0;
}

int main(){

	test();

	return 0;
}