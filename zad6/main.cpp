#include <iostream>
#include <cassert> 
#include "mydeque.h"

int test(){

	MyDeque<int> mydeque;
	assert(mydeque.empty());
	std::cout<<"Test 1 passed"<<std::endl;

	mydeque.push_front(1);
	mydeque.push_front(2);
	mydeque.push_front(3);
	mydeque.push_front(4);
	assert(mydeque.front() == 4);
	assert(mydeque.back() == 1);
	std::cout<<"Test 2 passed"<<std::endl;

	mydeque.push_back(7);
	mydeque.push_back(8);
	mydeque.push_back(9);
	mydeque.push_back(10);
	assert(mydeque.front() == 4);
	assert(mydeque.back() == 10);
	std::cout<<"Test 3 passed"<<std::endl;

	mydeque.pop_front();
	assert(mydeque.front() == 3);
	assert(mydeque.back() == 10);
	std::cout<<"Test 4 passed"<<std::endl;

	mydeque.pop_back();
	assert(mydeque.front() == 3);
	assert(mydeque.back() == 9);
	std::cout<<"Test 5 passed"<<std::endl;	

	MyDeque<int> mydeque2(mydeque);
	mydeque.display();
	mydeque2.display();
	std::cout<<"Test 6 passed"<<std::endl;
	std::cout<<"Test 7 passed"<<std::endl;

	mydeque.clear();
	assert(mydeque.empty());
	std::cout<<"Test 8 passed"<<std::endl;

	return 0;
}

int main(){

	test();

	return 0;
}