/*
 * main.cpp
 *
 *  Created on: Aug 9, 2018
 *      Author: trdnguyen
 */

#include <iostream>
#include "Linked_List.h"
#include "dbg.h"

int main()
{
	ListNode<unsigned int> *n1 = new ListNode<unsigned int>(1);
	ListNode<unsigned int> *n2 = new ListNode<unsigned int>(2);
	ListNode<unsigned int> *n3 = new ListNode<unsigned int>(3);
	ListNode<unsigned int> *n4 = new ListNode<unsigned int>(4);

	LinkedList<unsigned int> a(10);
	a.AddLast(*n1);
	a.AddLast(*n2);
	a.AddLast(99);
	a.AddFirst(*n4);
	a.AddFirst(*n3);
	a.AddFirst(100);

	a.TraverseList();
	a.RemoveByIdx(1);
	a.RemoveByIdx(1);
	a.RemoveByIdx(1);
	a.RemoveByIdx(1);
	a.RemoveByIdx(1);
	a.RemoveByIdx(1);
	a.RemoveByIdx(1);
	a.RemoveByIdx(1);
	a.TraverseList();

	LinkedList<unsigned int> *b = new LinkedList<unsigned int>(a, 20);
	b->TraverseList();
	//delete a;
	delete b;

	getchar();

	delete n1;
	delete n2;
	delete n3;
	delete n4;
	return 0;
}

