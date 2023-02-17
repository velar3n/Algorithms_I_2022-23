#include <iostream>
#include <cassert> 
#include "myqueue.h"

int test(){

	MyQueue<int> myqueue;
	assert(myqueue.empty());
	std::cout<<"Test 1 passed"<<std::endl;

	myqueue.push(1);
	myqueue.push(2);
	myqueue.push(3);
	myqueue.push(4);
	assert(myqueue.front() == 1);
	assert(myqueue.back() == 4);
	std::cout<<"Test 2 passed"<<std::endl;

	myqueue.pop();
	assert(myqueue.front() == 2);
	assert(myqueue.back() == 4);
	std::cout<<"Test 3 passed"<<std::endl;

	MyQueue<int> myqueue2(myqueue);
	myqueue.display();
	myqueue2.display();
	std::cout<<"Test 4 passed"<<std::endl;
	std::cout<<"Test 5 passed"<<std::endl;

	MyQueue<int> myqueue3 = std::move(myqueue);
	myqueue.display();
	myqueue3.display();
	std::cout<<"Test 6 passed"<<std::endl;
	std::cout<<"Test 7 passed"<<std::endl;

	myqueue.clear();
	assert(myqueue.empty());
	std::cout<<"Test 8 passed"<<std::endl;


	return 0;
}

int main(){

	test();

	return 0;
}