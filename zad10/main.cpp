#include <iostream>
#include <cassert> 
#include "binary_tree.h"

int test(){

	RandomBinaryTree<int> tree;

	assert(tree.empty());
	std::cout<<"Test 1 passed"<<std::endl;

	tree.insert(1);
	tree.insert(2);
	tree.insert(5);
	tree.insert(12);
	tree.insert(4);
	tree.insert(4);
	std::cout<<"Test 2 passed"<<std::endl;

	assert(tree.calc_nodes() == 6);
	std::cout<<"Test 3 passed"<<std::endl;

	assert(tree.iter_calc_nodes() == 6);
	std::cout<<"Test 4 passed"<<std::endl;	

	tree.clear();
	assert(tree.empty());
	std::cout<<"Test 5 passed"<<std::endl;

	return 0;
}

int main(){

	test();

	return 0;
}