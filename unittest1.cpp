#include "stdafx.h"
#include "CppUnitTest.h"
#include "./linked_list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListUnitTest
{
	TEST_CLASS(Test_AddFirst)
	{
		/*
		*	E_LIST_ERROR_TYPE LinkedList<T>::AddFirst(T NewHeadVal);
		*/
	public:
		/*
		*	Test Description: Test for normal case of AddFirst, add nodes to empty list, unlimit list size
		*	Input: new head value
		*	Expected output: NA
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_AddFirst_1_1)
		{
			LinkedList<unsigned int> uiList;
			unsigned int uiNodeVal = 10;
			Assert::IsTrue(eLIST_NO_ERR == uiList.AddFirst(uiNodeVal));
			Assert::IsTrue(1 == uiList.GetCount());
			//Assert::IsTrue(uiList.m_pFirst == uiList.m_pLast);
			Assert::IsTrue(eLIST_NO_ERR == uiList.AddFirst(uiNodeVal));
			//Assert::IsTrue(uiList.m_pFirst != uiList.m_pLast);
		}
		/*
		*	Test Description: Test for normal case of AddFirst, add 1 node to empty list, limited list size
		*	Input: new head value
		*	Expected output: NA
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_AddFirst_1_2)
		{
			LinkedList<unsigned int> uiList(5);
			unsigned int uiNodeVal = 10;
			Assert::IsTrue(eLIST_NO_ERR == uiList.AddFirst(uiNodeVal));
			Assert::IsTrue(1 == uiList.GetCount());
			Assert::IsTrue(eLIST_NO_ERR == uiList.AddFirst(uiNodeVal));
		}
		/*
		*	Test Description: Test for abnormal case of AddFirst: List over capacity
		*	Input: new head value
		*	Expected output: NA
		*	Return: eLIST_OVER_CAPACITY
		*/
		TEST_METHOD(Test_AddFirst_1_3)
		{
			LinkedList<unsigned int> uiList(3);
			unsigned int uiNodeVal = 5;
			for (int i = 0; i < 3; ++i)
			{
				Assert::IsTrue(eLIST_NO_ERR == uiList.AddFirst(i));
			}
			Assert::IsTrue(3 == uiList.GetCount());
			Assert::IsTrue(eLIST_OVER_CAPACITY == uiList.AddFirst(uiNodeVal));
			Assert::IsTrue(3 == uiList.GetCount());
		}
	};

	TEST_CLASS(Test_Append)
	{
		/*
		*	E_LIST_ERROR_TYPE Append (T NewLastVal);
		*/
	public:
		/*
		*	Test Description: Test for normal case of Append, add nodes to empty list, unlimit list size
		*	Input: new last value
		*	Expected output: NA
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_Append_1_1)
		{
			LinkedList<unsigned int> uiList;
			unsigned int uiNodeVal = 10;
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(uiNodeVal));
			Assert::IsTrue(1 == uiList.GetCount());
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(uiNodeVal));
			Assert::IsTrue(2 == uiList.GetCount());
		}
		/*
		*	Test Description: Test for normal case of AddFirst, add 1 node to empty list, limited list size
		*	Input: new last value
		*	Expected output: NA
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_Append_1_2)
		{
			LinkedList<unsigned int> uiList(5);
			unsigned int uiNodeVal = 10;
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(uiNodeVal));
			Assert::IsTrue(1 == uiList.GetCount());
			//Assert::IsTrue(uiList.m_pFirst == uiList.m_pLast);
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(uiNodeVal));
		}
		/*
		*	Test Description: Test for abnormal case of AddFirst: List over capacity
		*	Input: new last value
		*	Expected output: NA
		*	Return: eLIST_OVER_CAPACITY
		*/
		TEST_METHOD(Test_Append_1_3)
		{
			LinkedList<unsigned int> uiList(3);
			unsigned int uiNodeVal = 5;
			for (int i = 0; i < 3; ++i)
			{
				Assert::IsTrue(eLIST_NO_ERR == uiList.Append(i));
			}
			Assert::IsTrue(3 == uiList.GetCount());
			Assert::IsTrue(eLIST_OVER_CAPACITY == uiList.Append(uiNodeVal));
			Assert::IsTrue(3 == uiList.GetCount());
		}
	};
	TEST_CLASS(Test_GetIndex)
	{
		/*
		*	E_LIST_ERROR_TYPE GetIndex(T val, unsigned int &ruiIdxRet);
		*/
	public:
		/*
		*	Test Description: Test for normal case of GetIndex, correct Node value
		*	Input: Value of node
		*	Expected output: index of node
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_GetIndex_1_1)
		{
			LinkedList<unsigned int> uiList;
			unsigned int uiIdx;
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(0));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(1));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(2));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(3));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(4));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(5));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(5));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(5));

			Assert::IsTrue(eLIST_NO_ERR == uiList.GetIndex(0, uiIdx));
			Assert::IsTrue(uiIdx == 0);
			Assert::IsTrue(eLIST_NO_ERR == uiList.GetIndex(1, uiIdx));
			Assert::IsTrue(uiIdx == 1);
			Assert::IsTrue(eLIST_NO_ERR == uiList.GetIndex(5, uiIdx));
			Assert::IsTrue(uiIdx == 5);
		}
		/*
		*	Test Description: Test for abnormal case of GetIndex, incorrect Node value
		*	Input: Value of node
		*	Expected output: NA
		*	Return: eLIST_NODE_NOT_FOUND
		*/
		TEST_METHOD(Test_GetIndex_1_2)
		{
			LinkedList<unsigned int> uiList;
			unsigned int uiIdx = 0;
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(0));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(1));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(2));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(3));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(4));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(5));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(5));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(5));

			Assert::IsTrue(eLIST_NODE_NOT_FOUND == uiList.GetIndex(10, uiIdx));
			Assert::IsTrue(uiIdx == 0); //the uiIdx is not modified
		}
		/*
		*	Test Description: Test for abnormal case of GetIndex, List is empty
		*	Input: Value of node
		*	Expected output: NA
		*	Return: eLIST_EMPTY_LIST
		*/
		TEST_METHOD(Test_GetIndex_1_3)
		{
			LinkedList<unsigned int> uiList;
			unsigned int uiIdx = 0;
			Assert::IsTrue(eLIST_EMPTY_LIST == uiList.GetIndex(10, uiIdx));
			Assert::IsTrue(uiIdx == 0); //the uiIdx is not modified
		}
	};

	TEST_CLASS(Test_Insert)
	{
		/*
		*	E_LIST_ERROR_TYPE Insert (T NodeVal, unsigned int uiIdx);
		*/
	public:
		/*
		*	Test Description: Test for normal case of Insert, Insert new node to head
		*	Input: Value of node, index value
		*	Expected output: NA
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_Insert_1_1)
		{
			LinkedList<unsigned int> uiList;
			Assert::IsTrue(eLIST_NO_ERR == uiList.Insert(1, 0));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Insert(3, 0));
			Assert::IsTrue(2 == uiList.GetCount());
		}
		/*
		*	Test Description: Test for normal case of Insert, Insert new node to random position
		*	Input: Value of node, index value
		*	Expected output: NA
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_Insert_1_2)
		{
			LinkedList<unsigned int> uiList(15);
			unsigned int uiNodeVal;
			unsigned int uiIdx;
			for (int i = 0; i < 10; ++i)
			{
				Assert::IsTrue(eLIST_NO_ERR == uiList.Append(i));
			}
			uiIdx = 5;
			Assert::IsTrue(eLIST_NO_ERR == uiList.Insert(4, uiIdx));
			Assert::IsTrue(11 == uiList.GetCount());
			Assert::IsTrue(eLIST_NO_ERR == uiList.GetValByIdx(uiNodeVal, uiIdx));
			Assert::IsTrue(4 == uiNodeVal);
			uiIdx = 2;
			Assert::IsTrue(eLIST_NO_ERR == uiList.Insert(3, uiIdx));
			Assert::IsTrue(12 == uiList.GetCount());
			Assert::IsTrue(eLIST_NO_ERR == uiList.GetValByIdx(uiNodeVal, uiIdx));
			Assert::IsTrue(3 == uiNodeVal);
		}

		/*
		*	Test Description: Test for abnormal case of Insert, Insert with index > list count
		*	Input: Value of node, index value
		*	Expected output: NA
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_Insert_1_3)
		{
			LinkedList<unsigned int> uiList(15);
			unsigned int uiNodeVal;
			for (int i = 0; i < 10; ++i)
			{
				Assert::IsTrue(eLIST_NO_ERR == uiList.Append(i));
			}
			Assert::IsTrue(eLIST_NO_ERR == uiList.Insert(4, 11));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Insert(4, 12));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Insert(4, 13));
			Assert::IsTrue(13 == uiList.GetCount());
		}
		/*
		*	Test Description: Test for abnormal case of Insert, Insert with invalid index
		*	Input: Value of node, index value
		*	Expected output: NA
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_Insert_1_4)
		{
			LinkedList<unsigned int> uiList(10);
			unsigned int uiNodeVal;
			for (int i = 0; i < 10; ++i)
			{
				Assert::IsTrue(eLIST_NO_ERR == uiList.Append(i));
			}
			Assert::IsTrue(eLIST_OVER_CAPACITY == uiList.Insert(4, 5));
			Assert::IsTrue(eLIST_OVER_CAPACITY == uiList.Insert(4, 6));
			Assert::IsTrue(eLIST_OVER_CAPACITY == uiList.Insert(4, 7));
			Assert::IsTrue(10 == uiList.GetCount());
		}
	};

	TEST_CLASS(Test_Remove)
	{
		/*
		*	E_LIST_ERROR_TYPE Remove (T val);
		*/
	public:
		TEST_METHOD(Test_Remove_0_1)
		{
			LinkedList<unsigned int> uiList(10);
			unsigned int uiNodeVal;

			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(10));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Remove(10));
			//Assert::IsTrue(uiList.m_pFirst == uiList.m_pLast);
			//Assert::IsTrue(uiList.m_pFirst == NULL);

			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(10));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(20));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Remove(10));
			//Assert::IsTrue(uiList.m_pFirst == uiList.m_pLast);
			//Assert::IsTrue(uiList.m_pLast != NULL);
		}
		/*
		*	Test Description: Test for normal case of remove, remove first node
		*	Input: Value of node
		*	Expected output: NA
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_Remove_1_1)
		{
			LinkedList<unsigned int> uiList(10);
			unsigned int uiNodeVal;
			for (int i = 0; i < 10; ++i)
			{
				Assert::IsTrue(eLIST_NO_ERR == uiList.Append(i));
			}
			Assert::IsTrue(eLIST_NO_ERR == uiList.Remove(0));
			Assert::IsTrue(9 == uiList.GetCount());
			Assert::IsTrue(eLIST_NO_ERR == uiList.GetValByIdx(uiNodeVal, 0));
			Assert::IsTrue(1 == uiNodeVal);
		}
		/*
		*	Test Description: Test for normal case of Remove, remove random node with value T
		*	Input: Value of node
		*	Expected output: NA
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_Remove_1_2)
		{
			LinkedList<unsigned int> uiList(10);
			unsigned int uiNodeVal;
			for (int i = 0; i < 10; ++i)
			{
				Assert::IsTrue(eLIST_NO_ERR == uiList.Append(i));
			}
			Assert::IsTrue(eLIST_NO_ERR == uiList.Remove(3));
			Assert::IsTrue(9 == uiList.GetCount());
			Assert::IsTrue(eLIST_NO_ERR == uiList.GetValByIdx(uiNodeVal, 3));
			Assert::IsTrue(4 == uiNodeVal);
			Assert::IsTrue(eLIST_NO_ERR == uiList.Remove(5));
			Assert::IsTrue(8 == uiList.GetCount());
			Assert::IsTrue(eLIST_NO_ERR == uiList.GetValByIdx(uiNodeVal, 4));
			Assert::IsTrue(6 == uiNodeVal);
		}

		/*
		*	Test Description: Test for abnormal case of Remove, empty list
		*	Input: Value of node
		*	Expected output: NA
		*	Return: eLIST_EMPTY_LIST
		*/
		TEST_METHOD(Test_Remove_1_3)
		{
			LinkedList<unsigned int> uiList(10);
			Assert::IsTrue(eLIST_EMPTY_LIST == uiList.Remove(3));
			LinkedList<unsigned int> uiList2;
			Assert::IsTrue(eLIST_EMPTY_LIST == uiList2.Remove(3));
		}
		/*
		*	Test Description: Test for abnormal case of Remove, remove with wrong T value
		*	Input: Value of node
		*	Expected output: NA
		*	Return: eLIST_NODE_NOT_FOUND
		*/
		TEST_METHOD(Test_Remove_1_4)
		{
			LinkedList<unsigned int> uiList;
			unsigned int uiNodeVal;
			for (int i = 0; i < 10; ++i)
			{
				Assert::IsTrue(eLIST_NO_ERR == uiList.Append(i));
			}
			Assert::IsTrue(eLIST_NODE_NOT_FOUND == uiList.Remove(20));
			Assert::IsTrue(eLIST_NODE_NOT_FOUND == uiList.Remove(30));
			Assert::IsTrue(10 == uiList.GetCount());
		}
	};

	TEST_CLASS(Test_RemoveFirst)
	{
		/*
		*	E_LIST_ERROR_TYPE RemoveFirst(void);
		*/
	public:
		/*
		*	Test Description: Test for normal case of RemoveFirst
		*	Input: Value of node
		*	Expected output: NA
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_RemoveFirst_1_1)
		{
			LinkedList<unsigned int> uiList(10);
			unsigned int uiNodeVal;

			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(10));
			Assert::IsTrue(eLIST_NO_ERR == uiList.RemoveFirst());
			Assert::IsTrue(uiList.m_pFirst == uiList.m_pLast);
			Assert::IsTrue(uiList.m_pFirst == NULL);

			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(10));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(10));
			Assert::IsTrue(eLIST_NO_ERR == uiList.RemoveFirst());
			Assert::IsTrue(uiList.m_pFirst == uiList.m_pLast);
			Assert::IsTrue(uiList.m_pFirst != NULL);
		}
		/*
		*	Test Description: Test for abnormal case of RemoveFirst, Empty list
		*	Input: Value of node
		*	Expected output: NA
		*	Return: eLIST_EMPTY_LIST
		*/
		TEST_METHOD(Test_RemoveFirst_1_2)
		{
			LinkedList<unsigned int> uiList(10);
			unsigned int uiNodeVal;
			for (int i = 0; i < 10; ++i)
			{
				Assert::IsTrue(eLIST_NO_ERR == uiList.Append(i));
			}
			Assert::IsTrue(eLIST_NO_ERR == uiList.Remove(3));
			Assert::IsTrue(9 == uiList.GetCount());
			Assert::IsTrue(eLIST_NO_ERR == uiList.GetValByIdx(uiNodeVal, 3));
			Assert::IsTrue(4 == uiNodeVal);
			Assert::IsTrue(eLIST_NO_ERR == uiList.Remove(5));
			Assert::IsTrue(8 == uiList.GetCount());
			Assert::IsTrue(eLIST_NO_ERR == uiList.GetValByIdx(uiNodeVal, 4));
			Assert::IsTrue(6 == uiNodeVal);
		}
	};

	TEST_CLASS(Test_GetValByIdx)
	{
		/*
		*	E_LIST_ERROR_TYPE LinkedList<T>::GetValByIdx(T& RetVal, unsigned int uiIdx)
		*/
	public:
		/*
		*	Test Description: Test for normal case of GetValByIdx
		*	Input: valid value of uiIdx
		*	Expected output: RetVal of given index
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_GetValByIdx_1_1)
		{
			LinkedList<unsigned int> uiList;
			unsigned int uiNodeVal;
			for (unsigned int i = 0; i <= 10; ++i)
			{
				Assert::IsTrue(eLIST_NO_ERR == uiList.AddFirst(i));
			}
			Assert::IsTrue(eLIST_NO_ERR == uiList.GetValByIdx(uiNodeVal, (unsigned int)0));
			Assert::IsTrue(uiNodeVal == 10);
			Assert::IsTrue(eLIST_NO_ERR == uiList.GetValByIdx(uiNodeVal, (unsigned int)2));
			Assert::IsTrue(uiNodeVal == 8);
			Assert::IsTrue(eLIST_NO_ERR == uiList.GetValByIdx(uiNodeVal, (unsigned int)10));
			Assert::IsTrue(uiNodeVal == 0);
		}
		/*
		*	Test Description: Test for abnormal case of GetValByIdx, Invalid index
		*	Input: invalid value of uiIdx
		*	Expected output: NA
		*	Return: eLIST_INVALID_INDEX
		*/
		TEST_METHOD(Test_GetValByIdx_1_2)
		{
			LinkedList<unsigned int> uiList;
			unsigned int uiNodeVal = 5;
			for (int i = 0; i <= 10; ++i)
			{
				Assert::IsTrue(eLIST_NO_ERR == uiList.AddFirst(i));
			}
			Assert::IsTrue(eLIST_INVALID_INDEX == uiList.GetValByIdx(uiNodeVal, 13));
			Assert::IsTrue(uiNodeVal == 5);
		}
	};
	TEST_CLASS(Test_Operator)
	{
		/*
		*	T& LinkedList<T>::operator[](const unsigned int uiIdx)
		*/
	public:
		/*
		*	Test Description: Test for normal case of Operator[], get the correct index value
		*	Input: valid index value
		*	Expected output: NA
		*	Return: T value
		*/
		TEST_METHOD(Test_Operator_1_1)
		{
			LinkedList<unsigned int> uiList;
			for (unsigned int i = 0; i <= 10; ++i)
			{
				Assert::IsTrue(eLIST_NO_ERR == uiList.Append(i));
			}
			Assert::IsTrue(0 == uiList[0]);
			Assert::IsTrue(9 == uiList[9]);
		}
		/*
		*	Test Description: Test for normal case of Operator[],success to set the value of
		*					node with valid index
		*	Input: valid index value
		*	Expected output: NA
		*	Return: T value
		*/
		TEST_METHOD(Test_Operator_1_2)
		{
			LinkedList<unsigned int> uiList;
			for (int i = 0; i <= 10; ++i)
			{
				Assert::IsTrue(eLIST_NO_ERR == uiList.Append(i));
			}
			uiList[0] = 5;
			uiList[9] = 10;
			Assert::IsTrue(5 == uiList[0]);
			Assert::IsTrue(10 == uiList[9]);
		}
		/*
		*	Test Description: Test for abnormal case of Operator[],the index out of range
		*	Input: invalid index value
		*	Expected output: NA (enter infinite loop)
		*	Return: NA
		*/
		TEST_METHOD(Test_Operator_1_3)
		{
			LinkedList<unsigned int> uiList;
			for (unsigned int i = 0; i <= 10; ++i)
			{
				Assert::IsTrue(eLIST_NO_ERR == uiList.Append(i));
			}
			//uiList[11] = 3;
		}

	};
	// E_LIST_ERROR_TYPE InsertList (LinkedList<T>& InList, unsigned int uiIdx);
	TEST_CLASS(Test_InsertList)
	{
	public:
		/*
		 * Test_InsertList_1
		 * Input: InList empty, idx = 0
		 * Expected output: eErr = eLIST_EMPTY_LIST;
		 */
		TEST_METHOD(Test_InsertList_1)
		{
			LinkedList<unsigned int> List1(5);
			LinkedList<unsigned int> List2(10);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = List1.Insert(List2, 0);
			Assert::IsTrue(eErr == eLIST_EMPTY_LIST);
		}

		/*
		 * Test_InsertList_2
		 * Input: InList with 10 elements, List with capacity 5, idx = 0
		 * Expected output: eErr = eLIST_OVER_CAPACITY;
		 */
		TEST_METHOD(Test_InsertList_2)
		{
			LinkedList<unsigned int> List1(5);
			LinkedList<unsigned int> List2(10);
			for (unsigned int i = 0; i < 10; i++)
			{
				List2.Append(i);
			}
			Assert::IsTrue(List2.GetCount() == 10);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = List1.Insert(List2, 0);
			Assert::IsTrue(eErr == eLIST_OVER_CAPACITY);
		}

		/*
		 * Test_InsertList_3
		 * Input: InList with 10 elements, List with capacity 15, idx = invalid
		 * Expected output: eErr = eLIST_INVALID_INDEX;
		 */
		TEST_METHOD(Test_InsertList_3)
		{
			LinkedList<unsigned int> List1(15);
			LinkedList<unsigned int> List2(10);
			for (unsigned int i = 0; i < 10; i++)
			{
				List2.Append(i);
			}
			Assert::IsTrue(List2.GetCount() == 10);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = List1.Insert(List2, 1);
			Assert::IsTrue(eErr == eLIST_INVALID_INDEX);
		}

		/*
		 * Test_InsertList_4
		 * Input: InList with 10 elements, List with unlimited capacity,
				  idx = first
				  idx = middle
				  idx = last
		 * Expected output: eErr = eLIST_NO_ERR;
							list inserted
		 */
		TEST_METHOD(Test_InsertList_4)
		{

			LinkedList<unsigned int> List1(0);
			LinkedList<unsigned int> List2(10);
			for (unsigned int i = 0; i < 10; i++)
			{
				List2.Append(i);
			}
			Assert::IsTrue(List2.GetCount() == 10);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

			eErr = List1.Insert(List2, 0);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(List1.GetCount() == 10);
			Assert::IsTrue(List1[5] == 5);

			eErr = List1.Insert(List2, 5);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(List1.GetCount() == 20);
			Assert::IsTrue(List1[5] == 0);

			eErr = List1.Insert(List2, List1.GetCount() - 1);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(List1.GetCount() == 30);
			Assert::IsTrue(List1[List1.GetCount() - 1] == 9);
		}

	};
	// E_LIST_ERROR_TYPE Insert (Node<T>& NewNode, unsigned int uiIdx);
	TEST_CLASS(Test_Insert_1)
	{
	public:
		/*
		 * Test_Insert_1_1
		 * Input: Empty list, NewNode, index = 0;
		 * Output eErr = eLIST_NO_ERR
				  NewNode inserted as first node
		 */
		TEST_METHOD(Test_Insert_1_1)
		{
			LinkedList<unsigned int> _List(0);
			Assert::IsTrue(_List.GetCount() == 0);
			unsigned int idx = 0;
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			Node<unsigned int> _Node(10);
			eErr = _List.Insert(_Node, idx);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(_List.GetCount() == 1);
			Assert::IsTrue(_List[0] == _Node.GetVal());
		}

		/*
		 * Test_Insert_1_2
		 * Input: Empty list, NewNode, index = last index, 1;
		 * Output eErr = eLIST_NO_ERR
				  NewNodes inserted
		 */
		TEST_METHOD(Test_Insert_1_2)
		{
			LinkedList<unsigned int> _List(0);
			Assert::IsTrue(_List.GetCount() == 0);
			unsigned int idx = 0;
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			Node<unsigned int> _Node(10);
			eErr = _List.Insert(_Node, idx);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(_List.GetCount() == 1);
			Assert::IsTrue(_List[0] == _Node.GetVal());

			eErr = _List.Insert(_Node, _List.GetCount() - 1);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(_List.GetCount() == 2);
			Assert::IsTrue(_List[1] == _Node.GetVal());

			eErr = _List.Insert(_Node, 1);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(_List.GetCount() == 3);
			Assert::IsTrue(_List[1] == _Node.GetVal());
		}

		/*
		 * Test_Insert_1_3
		 * Input: Empty list, NewNode, index = > Count
		 * Output eErr = eLIST_INVALID_INDEX
		 */
		TEST_METHOD(Test_Insert_1_3)
		{
			LinkedList<unsigned int> _List(0);
			Assert::IsTrue(_List.GetCount() == 0);
			unsigned int idx = 5;
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			Node<unsigned int> _Node(10);
			eErr = _List.Insert(_Node, idx);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(_List.GetCount() == 1);
		}

		/*
		 * Test_Insert_1_4
		 * Input: list {0,1,2,3} with capacity = 4 , NewNode, index = 0
		 * Output eErr = eLIST_OVER_CAPACITY
		 *				 no node inserted
		 */
		TEST_METHOD(Test_Insert_1_4)
		{
			LinkedList<unsigned int> _List(4);
			Assert::IsTrue(_List.GetCount() == 0);
			for (unsigned int i = 0; i < 4; i++)
			{
				_List.Insert(i, 0);
			}
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			Node<unsigned int> _Node(10);
			eErr = _List.Insert(_Node, 0);

			Assert::IsTrue(eErr == eLIST_OVER_CAPACITY);
			Assert::IsTrue(_List.GetCount() == 4);
		}
	};
	// E_LIST_ERROR_TYPE RemoveLast(void);
	TEST_CLASS(Test_RemoveLast)
	{
	public:
		/*
		 *	Test_RemoveLast_1
		 *  Input: empty list
		 *  Expected output: eErr = eLIST_EMPTY_LIST
		 */
		TEST_METHOD(Test_RemoveLast_1)
		{
			LinkedList<unsigned int> _List(0);
			Assert::IsTrue(_List.GetCount() == 0);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = _List.RemoveLast();

			Assert::IsTrue(eErr == eLIST_EMPTY_LIST);
		}
		/*
		 *	Test_RemoveLast_2
		 *  Input: list {0,1,2,3,4,5}
		 *  Expected output: eErr = eLIST_NO_ERR
		 *					 last node removed
		 */
		TEST_METHOD(Test_RemoveLast_2)
		{
			LinkedList<unsigned int> _List(0);
			Assert::IsTrue(_List.GetCount() == 0);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			for (unsigned int i = 0; i < 6; i++)
			{
				_List.Append(i);
			}
			Assert::IsTrue(_List.GetCount() == 6);
			Assert::IsTrue(_List[_List.GetCount() - 1] == 5);
			eErr = _List.RemoveLast();

			Assert::IsTrue(_List.GetCount() == 5);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(_List[_List.GetCount() - 1] == 4);
		}
	};
	// E_LIST_ERROR_TYPE RemoveByIdx (unsigned int uiIndex);
	TEST_CLASS(Test_RemoveByIdx)
	{
	public:
		/*
		 * Test_RemoveByIdx_1
		 * Input: Empty list
		 * Expected Output: eErr = eLIST_EMPTY_LIST
		 */
		TEST_METHOD(Test_RemoveByIdx_1)
		{
			LinkedList<unsigned int> _List(0);
			Assert::IsTrue(_List.GetCount() == 0);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = _List.RemoveByIdx(10);
			Assert::IsTrue(eErr == eLIST_INVALID_INDEX);
		}
		/*
		 * Test_RemoveByIdx_2
		 * Input: list { 0, 1, 2, 3, 4, 5 }, remove idx 7
		 * Expected Output: eErr = eLIST_INVALID_INDEX
		 */
		TEST_METHOD(Test_RemoveByIdx_2)
		{
			LinkedList<unsigned int> _List(0);
			Assert::IsTrue(_List.GetCount() == 0);
			for (unsigned int i = 0; i < 6; i++)
			{
				_List.Append(i);
			}
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = _List.RemoveByIdx(7);
			Assert::IsTrue(eErr == eLIST_INVALID_INDEX);
		}

		/*
		 * Test_RemoveByIdx_3
		 * Input: list { 0, 1, 2, 3, 4, 5 }, remove idx 5, 3, 0
		 * Expected Output: eErr = eLIST_NO_ERR
							index 5,3,0 removed
		 */
		TEST_METHOD(Test_RemoveByIdx_3)
		{
			LinkedList<unsigned int> _List(0);
			Assert::IsTrue(_List.GetCount() == 0);
			for (unsigned int i = 0; i < 6; i++)
			{
				_List.Append(i);
			}
			Assert::IsTrue(_List.GetCount() == (6 - 0));

			// Last index
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = _List.RemoveByIdx(5);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(_List.GetCount() == (6 - 1));

			// Random index
			eErr = _List.RemoveByIdx(3);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(_List[3] == 4);
			Assert::IsTrue(_List.GetCount() == (6 - 2));

			// First index
			eErr = _List.RemoveByIdx(0);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(_List[0] == 1);
			Assert::IsTrue(_List.GetCount() == (6 - 3));
		}
	};
	// E_LIST_ERROR_TYPE Clear(void);
	TEST_CLASS(Test_Clear)
	{
	public:
		/* Test_Clear_1
		 * Input : Empty List
		 * Expected Output: eErr = eLIST_EMPTY_LIST
		 */
		TEST_METHOD(Test_Clear_1)
		{
			LinkedList<unsigned int> _List(2);
			Assert::IsTrue(_List.Clear() == eLIST_EMPTY_LIST);
		}
		/* Test_Clear_2
		 * Input : List { 1, 1, 1, 1, 1, 1, 1, 1 }
		 * Expected Output: eErr = eLIST_EMPTY_LIST
							List cleared
		 */
		TEST_METHOD(Test_Clear_2)
		{
			LinkedList<unsigned int> _List(10);
			for (unsigned int i = 0; i < 10; i++)
			{
				_List.Append(1);
			}
			Assert::IsTrue(_List.GetCount() == 10);
			Assert::IsTrue(_List.Clear() == eLIST_EMPTY_LIST);
			Assert::IsTrue(_List.GetCount() == 0);
		}
	};
	// E_LIST_ERROR_TYPE GetIndexList(T val, LinkedList<unsigned int>& idxList);
	TEST_CLASS(Test_GetIndexList)
	{
	public:
		/* Test_GetIndexList_1_1
		 * Input : Empty List
		 * Expected Output: eErr = eLIST_EMPTY_LIST
		 */
		TEST_METHOD(Test_GetIndexList_1_1)
		{
			LinkedList<unsigned int> _List(13);
			Assert::IsTrue(_List.GetCount() == 0);

			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			LinkedList<unsigned int> uiIdxList(0);

			eErr = _List.GetIndexList(1, uiIdxList);
			Assert::IsTrue(eErr == eLIST_EMPTY_LIST);
		}
		/* Test_GetIndexList_1_2
		 * Input : List { 0, 1 , 2, 3, 4, 1 }, find value "1"
		 * Expected Output: eErr = eLIST_NO_ERR
							correct list of indices of value "1"
		 */
		TEST_METHOD(Test_GetIndexList_1_2)
		{
			LinkedList<unsigned int> _List(13);
			Assert::IsTrue(_List.GetCount() == 0);
			_List.Append(0); _List.Append(1); _List.Append(2);
			_List.Append(3); _List.Append(4); _List.Append(1);

			LinkedList<unsigned int> uiIdxList(0);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = _List.GetIndexList(1, uiIdxList);

			Assert::IsTrue(uiIdxList.GetCount() == 2);
			Assert::IsTrue((uiIdxList[0] == 1) && (uiIdxList[1] == 5));
		}

		/* Test_GetIndexList_1_3
		 * Input : List { 0, 1 , 2, 3, 4, 1 }, find value "10"
		 * Expected Output: eErr = eLIST_NO_ERR
							correct list of indices of value "1"
		 */
		TEST_METHOD(Test_GetIndexList_1_3)
		{
			LinkedList<unsigned int> _List(13);
			Assert::IsTrue(_List.GetCount() == 0);
			_List.Append(0); _List.Append(1); _List.Append(2);
			_List.Append(3); _List.Append(4); _List.Append(1);

			LinkedList<unsigned int> uiIdxList(0);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = _List.GetIndexList(10, uiIdxList);

			Assert::IsTrue(eErr == eLIST_NODE_NOT_FOUND);
			Assert::IsTrue(uiIdxList.GetCount() == 0);
		}

	};
	// Node<T>* GetNodeByIdx(unsigned int uiIdx);
	TEST_CLASS(Test_GetNodeByIdx)
	{
	public:
		/*
		 * Test_GetNodeByIdx_1_1
		 * Input: Invalid index, List { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }
		 * Expected output: NULL
		 */
		TEST_METHOD(Test_GetNodeByIdx_1_1)
		{
			// Step 1: Create a list with 10 elements
			LinkedList<unsigned int> _List(10);
			for (unsigned int i = 0; i < 10; i++)
			{
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				Node<unsigned int> _Node(i);
				eErr = _List.Append(_Node);
				Assert::IsTrue(eErr == eLIST_NO_ERR);
			}
			// Step 2: Get node by index
			Assert::IsTrue(_List.GetNodeByIdx(12) == NULL);
		}
		/*
		 * Test_GetNodeByIdx_1_2
		 * Input: valid index, List { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }
		 * Expected output: node with right value
		 */
		TEST_METHOD(Test_GetNodeByIdx_1_2)
		{
			// Step 1: Create a list with 10 elements
			LinkedList<unsigned int> _List(10);
			for (unsigned int i = 0; i < 10; i++)
			{
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				Node<unsigned int> _Node(i);
				eErr = _List.Append(_Node);
				Assert::IsTrue(eErr == eLIST_NO_ERR);
			}
			// Step 2: Get node by index
			Assert::IsTrue(_List.GetNodeByIdx(12) == NULL);
			Assert::IsTrue(_List.GetNodeByIdx(0)->GetVal() == 0);
		}
	};
	// E_LIST_ERROR_TYPE AddFirst (Node<T>& NewLast);
	TEST_CLASS(Test_AddFirst_1)
	{
	public:
		/*
		 *  Test_AddFirst_1_1
		 *	Input: Node, empty list
		 *  Expected output: eErr = eLIST_NO_ERR,
							 m_pFirst == m_pLast,
							 m_pFist->Val == Node.val
							 list.m_uiNodeCount increases
		 */
		TEST_METHOD(Test_AddFirst_1_1)
		{
			LinkedList<unsigned int> _List(1);
			Assert::IsTrue(_List.GetCount() == 0);
			Node<unsigned int> node1(10);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = _List.AddFirst(node1);
			Assert::IsTrue(eLIST_NO_ERR == eErr);

			Assert::IsTrue(_List.m_pFirst == _List.m_pLast);
			Assert::IsTrue(_List[0] == node1.GetVal());
			Assert::IsTrue(_List.GetCount() == 1);
		}

		/*
		 *  Test_AddFirst_1_2
		 *	Input: Node, over capacity list
		 *  Expected output: eErr = eLIST_OVER_CAPACITY
							 list stays the same
		 */
		TEST_METHOD(Test_AddFirst_1_2)
		{
			LinkedList<unsigned int> _List(1);
			Assert::IsTrue(_List.GetCount() == 0);
			Node<unsigned int> node1(10);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = _List.AddFirst(node1);
			Assert::IsTrue(eLIST_NO_ERR == eErr);

			Node<unsigned int> node2(20);
			eErr = _List.AddFirst(node2);
			Assert::IsTrue(eLIST_OVER_CAPACITY == eErr);
			Assert::IsTrue(_List.GetCount() == 1);
		}

		/*
		 *  Test_AddFirst_1_3
		 *	Input: Nodes, unlimited size list
		 *  Expected output: eErr = eLIST_NO_ERR
							 list changes as Adding First
		 */
		TEST_METHOD(Test_AddFirst_1_3)
		{
			LinkedList<unsigned int> _List(0);
			Assert::IsTrue(_List.GetCount() == 0);
			Node<unsigned int> node1(10);
			Node<unsigned int> node2(20);
			for (int i = 0; i < 30; i++)
			{
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				eErr = _List.AddFirst((i % 2) ? node1 : node2);
				Assert::IsTrue(eLIST_NO_ERR == eErr);
			}

			Assert::IsTrue(_List.GetCount() == 30);
			Assert::IsTrue(_List[0] == 10);
			Assert::IsTrue(_List[29] == 20);
		}

	};
	// E_LIST_ERROR_TYPE Append (Node<T>& NewLast);
	TEST_CLASS(Test_Append_1)
	{
	public:
		/*
		 *  Test_Append_1_1
		 *	Input: Node, empty list
		 *  Expected output: eErr = eLIST_NO_ERR,
							 m_pFirst == m_pLast,
							 m_pFist->Val == Node.val
							 list.m_uiNodeCount increases
		 */
		TEST_METHOD(Test_Append_1_1)
		{
			LinkedList<unsigned int> _List(1);
			Assert::IsTrue(_List.GetCount() == 0);
			Node<unsigned int> node1(10);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = _List.Append(node1);
			Assert::IsTrue(eLIST_NO_ERR == eErr);

			Assert::IsTrue(_List.m_pFirst == _List.m_pLast);
			Assert::IsTrue(_List[0] == node1.GetVal());
			Assert::IsTrue(_List.GetCount() == 1);
		}

		/*
		 *  Test_Append_1_2
		 *	Input: Node, over capacity list
		 *  Expected output: eErr = eLIST_OVER_CAPACITY
							 list stays the same
		 */
		TEST_METHOD(Test_Append_1_2)
		{
			LinkedList<unsigned int> _List(1);
			Assert::IsTrue(_List.GetCount() == 0);
			Node<unsigned int> node1(10);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = _List.Append(node1);
			Assert::IsTrue(eLIST_NO_ERR == eErr);

			Node<unsigned int> node2(20);
			eErr = _List.Append(node2);
			Assert::IsTrue(eLIST_OVER_CAPACITY == eErr);
			Assert::IsTrue(_List.GetCount() == 1);
		}

		/*
		 *  Test_Append_1_3
		 *	Input: Nodes, unlimited size list
		 *  Expected output: eErr = eLIST_NO_ERR
							 list changes as appending
		 */
		TEST_METHOD(Test_Append_1_3)
		{
			LinkedList<unsigned int> _List(0);
			Assert::IsTrue(_List.GetCount() == 0);
			Node<unsigned int> node1(10);
			Node<unsigned int> node2(20);
			for (int i = 0; i < 30; i++)
			{
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				eErr = _List.Append((i % 2) ? node1 : node2);
				Assert::IsTrue(eLIST_NO_ERR == eErr);
			}

			Assert::IsTrue(_List.GetCount() == 30);
			Assert::IsTrue(_List[0] == 20);
			Assert::IsTrue(_List[29] == 10);
		}

	};

	TEST_CLASS(USER_LINKLIST)
	{
	public:

		TEST_METHOD(Test_NodeCtor)
		{
			Node<unsigned int> a(10);
			Assert::IsTrue(a.GetVal() == 10);
		}

		TEST_METHOD(Test_NodeSetVal)
		{
			Node<unsigned int> a(10);
			a.SetVal(5);
			Assert::IsTrue(a.GetVal() == 5);
		}

		TEST_METHOD(Test_ListCtor)
		{
			LinkedList<unsigned int> _List(10);
			Assert::IsTrue(_List.GetCount() == 0);
			Assert::IsTrue(_List.GetCapacity() == 10);
		}
	};
}
