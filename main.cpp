/*
 * main.cpp
 *
 *  Created on: Aug 9, 2018
 *      Author: trdnguyen
 */

#include <iostream>
#include "Linked_List.h"
#include "LinkedList_Debug.h"

static void TestAddFirst(void)
{
	//Test for AddFirst function:
	std::cout<< "Testing AddFirst................................................................... \n";
	//create new list with unlimited capacity
	LinkedList<unsigned int> uiList_1;
	for (unsigned int i = 0; i<10; ++i)
	{
		uiList_1.AddFirst(i);
	}
	uiList_1.TraverseList();

	//create new list with capacity 5
	unsigned int uiListSize = 5;
	LinkedList<unsigned int> uiList_2(uiListSize);
	for (unsigned int i = 0; i<10; ++i)
	{
		uiList_2.AddFirst(i);
	}
	uiList_2.TraverseList();
}

static void TestAppend(void)
{
	//Test for Append function:
	std::cout<< "Testing AddLast................................................................... \n";
	//create new list with unlimited capacity
	LinkedList<unsigned int> uiList_1;
	for (unsigned int i = 0; i<10; ++i)
	{
		uiList_1.Append(i);
	}
	uiList_1.TraverseList();

	//create new list with capacity 5
	unsigned int uiListSize = 5;
	LinkedList<unsigned int> uiList_2(uiListSize);
	for (unsigned int i = 0; i<10; ++i)
	{
		uiList_2.Append(i);
	}
	uiList_2.TraverseList();
}

static void TestGetIndex(void)
{
	//Test for GetIndex function:
	std::cout<< "Testing GetIndex.......... \n";
	LinkedList<unsigned int> iList();

}

static void TestGetNodeByIdx(void)
{
	//Test for GetNodeByIdx function:
	std::cout<< "Testing GetNodeByIdx................................ \n";
	LinkedList<unsigned int> iList;
	ListNode<unsigned int> *lNode;
	for (unsigned int i = 0; i<3; ++i)
	{
		iList.Append(i);
	}
	lNode = iList.GetNodeByIdx(2);
	std::cout<< lNode->GetVal() << std::endl;
}

static void TestRemove(void)
{
	//Test for Remove function
	std::cout<< "Testing Remove.......... \n";
}

static void TestRemoveFirst(void)
{
	//Test for RemoveFirst function
	std::cout<< "Testing RemoveFirst.......... \n";
}

static void TestRemoveLast(void)
{
	//Test for RemoveLast function
	std::cout<< "Testing RemoveLast.......... \n";
}

static void TestRemoveByIdx(void)
{
	//Test for RemoveByIdx function
	std::cout<< "Testing RemoveByIdx.......... \n";
}
static void TestGetValByIdx(void)
{
	//Test for GetValByIdx function
	std::cout<< "Testing GetValByIdx.......... \n";
}
static void TestInsert(void)
{
	//Test for Insert function
	std::cout<< "Testing Insert.......... \n";

}
static void TestClear(void)
{
	//Test for Clear function
	std::cout<< "Testing Clear.......... \n";
}
static void TestAll(void)
{
	//Test all
	std::cout<< "Testing all function.......... \n";
}

int main(void)
{
	TestAddFirst();
	TestAppend();
	TestGetIndex();
	TestRemove();
	TestRemoveFirst();
	TestRemoveLast();
	TestRemoveByIdx();
	TestGetValByIdx();
	TestInsert();
	TestClear();
	TestAll();
	TestGetNodeByIdx();
	return 0;
}

