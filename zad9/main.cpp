#include <iostream>
#include <cassert> 
#include "priority_queue.h"

int test(){

	MyPriorityQueue<int> mypriorityqueue;
	assert(mypriorityqueue.empty());
	std::cout<<"Test 1 passed"<<std::endl;

	mypriorityqueue.push(1);
	mypriorityqueue.push(2);
	mypriorityqueue.push(5);
	mypriorityqueue.push(3);
	assert(mypriorityqueue.size() == 4);
	assert(mypriorityqueue.top() == 5);
	std::cout<<"Test 2 passed"<<std::endl;

	mypriorityqueue.pop();
	assert(mypriorityqueue.size() == 3);
	assert(mypriorityqueue.top() == 3);
	std::cout<<"Test 3 passed"<<std::endl;

	MyPriorityQueue<int> mypriorityqueue2(mypriorityqueue);
	mypriorityqueue.display();
	mypriorityqueue2.display();
	std::cout<<"Test 4 passed"<<std::endl;
	std::cout<<"Test 5 passed"<<std::endl;

	MyPriorityQueue<int> mypriorityqueue3 = std::move(mypriorityqueue);
	mypriorityqueue.display();
	mypriorityqueue3.display();
	std::cout<<"Test 6 passed"<<std::endl;
	std::cout<<"Test 7 passed"<<std::endl;

	mypriorityqueue.clear();
	assert(mypriorityqueue.empty());
	std::cout<<"Test 8 passed"<<std::endl;


	return 0;
}

int main(){

	test();

	return 0;
}