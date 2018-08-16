/*
 * main.cpp
 *
 *  Created on: Aug 9, 2018
 *      Author: trdnguyen
 */

#include <iostream>
#include "Linked_List.h"
#include "LinkedList_Debug.h"
#include <assert.h>
#define ASSERT_ISTRUE(x) { if(!x) while (1);}

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
		E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
		eErr = uiList_1.Append(i);
		assert(eErr == eLIST_NO_ERR);
	}
	uiList_1.TraverseList();

	//create new list with capacity 5
	unsigned int uiListSize = 5;
	LinkedList<unsigned int> uiList_2(uiListSize);
	for (unsigned int i = 0; i<10; ++i)
	{
		E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
		eErr = uiList_2.Append(i);
		if (i < 5)
		{
			assert(eErr == eLIST_NO_ERR);
		}
		else
		{
			assert(eErr == eLIST_OVER_CAPACITY);
		}
	}
	uiList_2.TraverseList();
}

static void TestGetIndex(void)
{
	//Test for GetIndex function:
	std::cout<< "Testing GetIndex...................................................................  \n";
	LinkedList<unsigned int> uiList_1;
	printf("Creating uiList with 0 node\r\n");
	printf("Add 10 elements to list\r\n");
	for (unsigned int i = 0; i < 10; i++)
	{
		E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
		eErr = uiList_1.AddFirst(2*i);
		assert(eErr == eLIST_NO_ERR);
	}
	uiList_1.TraverseList();
	unsigned int uiTmp = 0;
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	printf("index of 2: ");
	eErr = uiList_1.GetIndex(2,&uiTmp);
	if (eErr != eLIST_NO_ERR)
	{
		printf("Error %d\r\n", eErr);
	}
	else
	{
		printf("%d\r\n", uiTmp);
	}

	printf("index of 6: ");
	eErr = uiList_1.GetIndex(6,&uiTmp);
	if (eErr != eLIST_NO_ERR)
	{
		printf("Error %d\r\n", eErr);
	}
	else
	{
		printf("%d\r\n", uiTmp);
	}

	printf("index of 17: ");
	eErr = uiList_1.GetIndex(17,&uiTmp);
	if (eErr != eLIST_NO_ERR)
	{
		printf("Error %d\r\n", eErr);
	}
	else
	{
		printf("%d\r\n", uiTmp);
	}
}

static void TestGetNodeByIdx(void)
{
	//Test for GetNodeByIdx function:
	std::cout<< "Testing GetNodeByIdx................................................................... \n";
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
	std::cout<< "Testing Remove................................................................... \n";
	LinkedList<unsigned int> uiList_1;
	printf("Creating uiList with 0 node\r\n");
	printf("Remove 3 from empty list\r\n");
	E_LIST_ERROR_TYPE eErr = uiList_1.Remove(3);
	assert(eErr == eLIST_EMPTY_LIST);

	printf("Add 10 elements to list\r\n");
	for (unsigned int i = 0; i < 10; i++)
	{
		E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
		eErr = uiList_1.AddFirst(2*i);
		assert(eErr == eLIST_NO_ERR);
	}
	assert(uiList_1.GetCount() == 10);
	uiList_1.TraverseList();

	printf("Remove 10 from list\r\n");
	eErr = eLIST_NO_ERR;
	eErr = uiList_1.Remove(10);
	assert(eErr == eLIST_NO_ERR);
	assert(uiList_1.GetCount() == 10 - 1);
	
	printf("Remove not found node (13) \r\n");
	eErr = uiList_1.Remove(13);
	assert(eErr == eLIST_NODE_NOT_FOUND);
	assert(uiList_1.GetCount() == 10 - 1);

	uiList_1.TraverseList();
}

static void TestRemoveFirst(void)
{
	//Test for RemoveFirst function
	std::cout<< "Testing RemoveFirst................................................................... \n";

	LinkedList<unsigned int> uiList_1;
	printf("Creating uiList with 0 node\r\n");
	printf("Test RemoveFirst from empty list\r\n");
	E_LIST_ERROR_TYPE eErr = uiList_1.RemoveFirst();
	assert(eErr == eLIST_EMPTY_LIST);

	printf("Add 10 elements to list\r\n");
	for (unsigned int i = 0; i < 10; i++)
	{
		E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
		eErr = uiList_1.AddFirst(2*i);
		assert(eErr == eLIST_NO_ERR);
	}
	uiList_1.TraverseList();
	printf("Remove first node\r\n");
	eErr = uiList_1.RemoveFirst();
	assert(eErr == eLIST_NO_ERR);
	uiList_1.TraverseList();
}

static void TestRemoveLast(void)
{
	//Test for RemoveLast function
	std::cout<< "Testing RemoveLast................................................................... \n";
	LinkedList<unsigned int> uiList_1;
	printf("Creating uiList with 0 node\r\n");
	printf("Test RemoveLast from empty list\r\n");
	E_LIST_ERROR_TYPE eErr = uiList_1.RemoveFirst();
	assert(eErr == eLIST_EMPTY_LIST);

	printf("Add 10 elements to list\r\n");
	for (unsigned int i = 0; i < 10; i++)
	{
		E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
		eErr = uiList_1.AddFirst(2*i);
		assert(eErr == eLIST_NO_ERR);
	}
	uiList_1.TraverseList();
	printf("Remove last node\r\n");
	eErr = uiList_1.RemoveLast();
	assert(eErr == eLIST_NO_ERR);
	uiList_1.TraverseList();
}

static void TestRemoveByIdx(void)
{
	//Test for RemoveByIdx function
	std::cout<< "Testing RemoveByIdx................................................................... \n";
	LinkedList<unsigned int> uiList_1;
	printf("Creating uiList with 0 node\r\n");
	printf("Test Remove from empty list\r\n");
	E_LIST_ERROR_TYPE eErr = uiList_1.RemoveByIdx(10);
	assert(eErr == eLIST_EMPTY_LIST);

	printf("Add 10 elements to list\r\n");
	for (unsigned int i = 0; i < 10; i++)
	{
		E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
		eErr = uiList_1.AddFirst(2*i);
		assert(eErr == eLIST_NO_ERR);
	}
	uiList_1.TraverseList();
	printf("Remove node with idx 7\r\n");
	eErr = uiList_1.RemoveByIdx(7);
	assert(eErr == eLIST_NO_ERR);
	uiList_1.TraverseList();
	printf("Remove node with invalid idx 14\r\n");
	eErr = uiList_1.RemoveByIdx(14);
	assert(eErr == eLIST_INVALID_INDEX);
	uiList_1.TraverseList();
}
static void TestGetValByIdx(void)
{
	//Test for GetValByIdx function
	std::cout<< "Testing GetValByIdx................................................................... \n";
}
static void TestInsert(void)
{
	//Test for Insert function
	std::cout<< "Testing Insert................................................................... \n";

	LinkedList<unsigned int> uiList_1(0);
	printf("Creating uiList with 0 node\r\n");
	printf("Insert 2 to empty list, idx 0\r\n");
	uiList_1.Insert(2, 0);
	uiList_1.TraverseList();
	printf("Add 10 elements to list\r\n");
	for (unsigned int i = 0; i < 10; i++)
	{
		uiList_1.AddFirst(1);
	}
	uiList_1.TraverseList();
	printf("Insert 5 at idx 7\r\n");
	uiList_1.Insert(5, 7);
	uiList_1.TraverseList();
	printf("Insert 10 at invalid idx 11\r\n");
	uiList_1.Insert(10, 11);
	uiList_1.TraverseList();
}
static void TestClear(void)
{
	//Test for Clear function
	std::cout<< "Testing Clear................................................................... \n";
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

	TestInsert();

	TestGetIndex();

	TestRemove();

	TestRemoveFirst();

	TestRemoveLast();

	TestRemoveByIdx();

	TestGetValByIdx();

	TestClear();

	TestAll();

	TestGetNodeByIdx();

	getchar();

	return 0;
}

