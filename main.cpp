/*
 * main.cpp
 *
 *  Created on: Aug 9, 2018
 *      Author: trdnguyen
 */
#include "linked_list.h"
#include <iostream>
//template class LinkedList<unsigned int>;
//template class LinkedList<int>;
//template class Node<unsigned int>;
//template class Node<int>;

int main()
{
	LinkedList<unsigned int> list_a(10);
	unsigned int obj1 = 10;
	list_a.AddFirst(obj1);
	std::cout << "Count: " << list_a.GetCount() << std::endl;
	getchar();
	return 0;
}


