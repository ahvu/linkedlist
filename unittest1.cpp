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
				unsigned int uiObj = i;
				Assert::IsTrue(eLIST_NO_ERR == uiList.AddFirst(uiObj));
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
		TEST_METHOD(Test_Append_SingleNode_1)
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
		TEST_METHOD(Test_Append_SingleNode_2)
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
		TEST_METHOD(Test_Append_SingleNode_3)
		{
			LinkedList<unsigned int> uiList(3);
			unsigned int uiNodeVal = 5;
			for (int i = 0; i < 3; ++i)
			{
				unsigned int uiObj = i;
				Assert::IsTrue(eLIST_NO_ERR == uiList.Append(uiObj));
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
		LinkedList<unsigned int> m_uiList;
	public:
		void Setup()
		{
			m_uiList = LinkedList<unsigned int>();
			unsigned int uiObj = 0;
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.Append(uiObj));
			uiObj = 1;
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.Append(uiObj));
			uiObj = 2;
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.Append(uiObj));
			uiObj = 3;
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.Append(uiObj));
			uiObj = 4;
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.Append(uiObj));
			uiObj = 5;
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.Append(uiObj));
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.Append(uiObj));
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.Append(uiObj));
		}
		void Clean()
		{

		}
		/*
		*	Test Description: Test for normal case of GetIndex, correct Node value
		*	Input: Value of node
		*	Expected output: index of node
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_GetIndex_1_1)
		{
			Setup();
			unsigned int uiIdx;
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.GetIndex(0, uiIdx));
			Assert::IsTrue(uiIdx == 0);
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.GetIndex(1, uiIdx));
			Assert::IsTrue(uiIdx == 1);
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.GetIndex(5, uiIdx));
			Assert::IsTrue(uiIdx == 5);
			Clean();
		}
		/*
		*	Test Description: Test for abnormal case of GetIndex, incorrect Node value
		*	Input: Value of node
		*	Expected output: NA
		*	Return: eLIST_NODE_NOT_FOUND
		*/
		TEST_METHOD(Test_GetIndex_1_2)
		{
			Setup();
			unsigned int uiIdx = 0;
			Assert::IsTrue(eLIST_NODE_NOT_FOUND == m_uiList.GetIndex(10, uiIdx));
			Assert::IsTrue(uiIdx == 0); //the uiIdx is not modified
			Clean();
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
		LinkedList<unsigned int> m_uiList;
		unsigned int m_uiNodeVal;
		unsigned int m_uiIdx;
	public:
		void Setup(unsigned int uiList_cap)
		{
			m_uiList = LinkedList<unsigned int>(uiList_cap);
			for (int i = 0; i < 10; ++i)
			{
				unsigned int uiObj = i;
				Assert::IsTrue(eLIST_NO_ERR == m_uiList.Append(uiObj));
			}
		}
		void Clean()
		{
			m_uiNodeVal = 0;
			m_uiIdx = 0;
			m_uiList.Clear();
		}
		/*
		*	Test Description: Test for normal case of Insert, Insert new node to head
		*	Input: Value of node, index value
		*	Expected output: NA
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_Insert_1_1)
		{
			m_uiList = LinkedList<unsigned int>();
			m_uiNodeVal = 3;
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.Insert(m_uiNodeVal, 0));
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.Insert(m_uiNodeVal, 0));
			Assert::IsTrue(2 == m_uiList.GetCount());
			Clean();
		}
		/*
		*	Test Description: Test for normal case of Insert, Insert new node to random position
		*	Input: Value of node, index value
		*	Expected output: NA
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_Insert_1_2)
		{
			Setup(15);
			m_uiIdx = 5;
			unsigned int uiObj = 4;
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.Insert(uiObj, m_uiIdx));
			Assert::IsTrue(11 == m_uiList.GetCount());
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.GetValByIdx(m_uiNodeVal, m_uiIdx));
			Assert::IsTrue(4 == m_uiNodeVal);
			m_uiIdx = 2;
			uiObj = 3;
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.Insert(uiObj, m_uiIdx));
			Assert::IsTrue(12 == m_uiList.GetCount());
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.GetValByIdx(m_uiNodeVal, m_uiIdx));
			Assert::IsTrue(3 == m_uiNodeVal);
			Clean();
		}

		/*
		*	Test Description: Test for abnormal case of Insert, Insert with index == list count
		*	Input: Value of node, index value
		*	Expected output: NA
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_Insert_1_3)
		{
			Setup(15);
			unsigned int uiObj = 4;
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.Append(uiObj));
			Assert::IsTrue(11 == m_uiList.GetCount());
			Clean();
		}
		/*
		*	Test Description: Test for abnormal case of Insert, Insert with invalid index
		*	Input: Value of node, index value
		*	Expected output: NA
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_Insert_1_4)
		{
			Setup(10);
			unsigned uiObj = 5;
			Assert::IsTrue(eLIST_OVER_CAPACITY == m_uiList.Insert(uiObj, 5));
			Assert::IsTrue(eLIST_OVER_CAPACITY == m_uiList.Insert(uiObj, 6));
			Assert::IsTrue(eLIST_OVER_CAPACITY == m_uiList.Insert(uiObj, 7));
			Assert::IsTrue(10 == m_uiList.GetCount());
			Clean();
		}
	};

	TEST_CLASS(Test_Remove)
	{
		/*
		*	E_LIST_ERROR_TYPE Remove (T val);
		*/
		LinkedList<unsigned int> m_uiList;
		unsigned int m_uiIdx;
		unsigned int m_uiNodeVal;
	public:
		void Setup(unsigned int uiList_cap = 10)
		{
			m_uiList = LinkedList<unsigned int>(uiList_cap);
			for (int i = 0; i < 10; ++i)
			{
				unsigned int uiObj = i;
				Assert::IsTrue(eLIST_NO_ERR == m_uiList.Append(uiObj));
			}
		}
		void Clean()
		{
			m_uiNodeVal = 0;
			m_uiIdx = 0;
		}
		TEST_METHOD(Test_Remove_0_1)
		{
			LinkedList<unsigned int> uiList(10);
			unsigned int uiObj = 10;

			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(uiObj));
			Assert::IsTrue(eLIST_NO_ERR == uiList.Remove(10));
			//Assert::IsTrue(uiList.m_pFirst == uiList.m_pLast);
			//Assert::IsTrue(uiList.m_pFirst == NULL);

			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(uiObj));
			uiObj = 20;
			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(uiObj));
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
			Setup(10);
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.Remove(0));
			Assert::IsTrue(9 == m_uiList.GetCount());
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.GetValByIdx(m_uiNodeVal, 0));
			Assert::IsTrue(1 == m_uiNodeVal);
			Clean();
		}
		/*
		*	Test Description: Test for normal case of Remove, remove random node with value T
		*	Input: Value of node
		*	Expected output: NA
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_Remove_1_2)
		{
			Setup(10);
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.Remove(3));
			Assert::IsTrue(9 == m_uiList.GetCount());
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.GetValByIdx(m_uiNodeVal, 3));
			Assert::IsTrue(4 == m_uiNodeVal);
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.Remove(5));
			Assert::IsTrue(8 == m_uiList.GetCount());
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.GetValByIdx(m_uiNodeVal, 4));
			Assert::IsTrue(6 == m_uiNodeVal);
			Clean();
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
		}
		/*
		*	Test Description: Test for abnormal case of Remove, remove with wrong T value
		*	Input: Value of node
		*	Expected output: NA
		*	Return: eLIST_NODE_NOT_FOUND
		*/
		TEST_METHOD(Test_Remove_1_4)
		{
			Setup(10);
			Assert::IsTrue(eLIST_NODE_NOT_FOUND == m_uiList.Remove(20));
			Assert::IsTrue(eLIST_NODE_NOT_FOUND == m_uiList.Remove(30));
			Assert::IsTrue(10 == m_uiList.GetCount());
			Clean();
		}
	};

	//TEST_CLASS(Test_RemoveFirst)
	//{
	//	/*
	//	*	E_LIST_ERROR_TYPE RemoveFirst(void);
	//	*/
	//public:
	//	/*
	//	*	Test Description: Test for normal case of RemoveFirst
	//	*	Input: Value of node
	//	*	Expected output: NA
	//	*	Return: eLIST_NO_ERR
	//	*/
	//	TEST_METHOD(Test_RemoveFirst_1_1)
	//	{
	//		LinkedList<unsigned int> uiList(10);
	//		unsigned int uiNodeVal;

	//		Assert::IsTrue(eLIST_NO_ERR == uiList.Append(10));
	//		Assert::IsTrue(eLIST_NO_ERR == uiList.RemoveFirst());
	//		Assert::IsTrue(uiList.m_pFirst == uiList.m_pLast);
	//		Assert::IsTrue(uiList.m_pFirst == NULL);

	//		Assert::IsTrue(eLIST_NO_ERR == uiList.Append(10));
	//		Assert::IsTrue(eLIST_NO_ERR == uiList.Append(10));
	//		Assert::IsTrue(eLIST_NO_ERR == uiList.RemoveFirst());
	//		Assert::IsTrue(uiList.m_pFirst == uiList.m_pLast);
	//		Assert::IsTrue(uiList.m_pFirst != NULL);
	//	}
	//	/*
	//	*	Test Description: Test for abnormal case of RemoveFirst, Empty list
	//	*	Input: Value of node
	//	*	Expected output: NA
	//	*	Return: eLIST_EMPTY_LIST
	//	*/
	//	TEST_METHOD(Test_RemoveFirst_1_2)
	//	{
	//		LinkedList<unsigned int> uiList(10);
	//		unsigned int uiNodeVal;
	//		for (int i = 0; i < 10; ++i)
	//		{
	//			Assert::IsTrue(eLIST_NO_ERR == uiList.Append(i));
	//		}
	//		Assert::IsTrue(eLIST_NO_ERR == uiList.Remove(3));
	//		Assert::IsTrue(9 == uiList.GetCount());
	//		Assert::IsTrue(eLIST_NO_ERR == uiList.GetValByIdx(uiNodeVal, 3));
	//		Assert::IsTrue(4 == uiNodeVal);
	//		Assert::IsTrue(eLIST_NO_ERR == uiList.Remove(5));
	//		Assert::IsTrue(8 == uiList.GetCount());
	//		Assert::IsTrue(eLIST_NO_ERR == uiList.GetValByIdx(uiNodeVal, 4));
	//		Assert::IsTrue(6 == uiNodeVal);
	//	}
	//};

	TEST_CLASS(Test_GetValByIdx)
	{
		/*
		*	E_LIST_ERROR_TYPE LinkedList<T>::GetValByIdx(T& RetVal, unsigned int uiIdx)
		*/
		LinkedList<unsigned int> m_uiList;
		unsigned int m_uiIdx;
		unsigned int m_uiNodeVal;
	public:
		void Setup(unsigned int uiList_cap = 0)
		{
			m_uiList = LinkedList<unsigned int>(uiList_cap);

			for (unsigned int i = 0; i <= 10; i++)
			{
				unsigned int uiObj = i;
				Assert::IsTrue(eLIST_NO_ERR == m_uiList.AddFirst(uiObj));
			}
		}
		void Clean()
		{
			m_uiNodeVal = 0;
			m_uiIdx = 0;
		}
		/*
		*	Test Description: Test for normal case of GetValByIdx
		*	Input: valid value of uiIdx
		*	Expected output: RetVal of given index
		*	Return: eLIST_NO_ERR
		*/
		TEST_METHOD(Test_GetValByIdx_1_1)
		{
			Setup();
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.GetValByIdx(m_uiNodeVal, (unsigned int)0));
			Assert::IsTrue(m_uiNodeVal == 10);
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.GetValByIdx(m_uiNodeVal, (unsigned int)2));
			Assert::IsTrue(m_uiNodeVal == 8);
			Assert::IsTrue(eLIST_NO_ERR == m_uiList.GetValByIdx(m_uiNodeVal, (unsigned int)10));
			Assert::IsTrue(m_uiNodeVal == 0);
			Clean();
		}
		/*
		*	Test Description: Test for abnormal case of GetValByIdx, Invalid index
		*	Input: invalid value of m_uiIdx
		*	Expected output: NA
		*	Return: eLIST_INVALID_INDEX
		*/
		TEST_METHOD(Test_GetValByIdx_1_2)
		{
			Setup();
			Assert::IsTrue(eLIST_INVALID_INDEX == m_uiList.GetValByIdx(m_uiNodeVal, 13));
			Clean();
		}
	};
	TEST_CLASS(Test_Operator)
	{
		/*
		*	T& LinkedList<T>::operator[](const unsigned int uiIdx)
		*/
		LinkedList<unsigned int> m_uiList;
		unsigned int m_uiIdx;
		unsigned int m_uiNodeVal;
	public:
		void Setup(unsigned int uiList_cap = 10)
		{
			m_uiList = LinkedList<unsigned int>(uiList_cap);
			for (int i = 0; i < 10; ++i)
			{
				unsigned int uiObj = i;
				Assert::IsTrue(eLIST_NO_ERR == m_uiList.Append(uiObj));
			}
		}
		void Clean()
		{
			m_uiIdx = 0;
			m_uiNodeVal = 0;
		}
		/*
		*	Test Description: Test for normal case of Operator[], get the correct index value
		*	Input: valid index value
		*	Expected output: NA
		*	Return: T value
		*/
		TEST_METHOD(Test_Operator_1_1)
		{
			Setup();
			Assert::IsTrue(0 == m_uiList[0]);
			Assert::IsTrue(9 == m_uiList[9]);
			Clean();
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
			Setup();
			m_uiList[0] = 5;
			m_uiList[9] = 10;
			Assert::IsTrue(5 == m_uiList[0]);
			Assert::IsTrue(10 == m_uiList[9]);
			Clean();
		}
		/*
		*	Test Description: Test for abnormal case of Operator[],the index out of range
		*	Input: invalid index value
		*	Expected output: NA (enter infinite loop)
		*	Return: NA
		*/
		TEST_METHOD(Test_Operator_1_3)
		{
			Setup();
			//uiList[11] = 3;
			Clean();
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
	//// E_LIST_ERROR_TYPE Insert (Node<T>& NewNode, unsigned int uiIdx);
	//TEST_CLASS(Test_Insert_1)
	//{
	//public:
	//	/*
	//	 * Test_Insert_1_1
	//	 * Input: Empty list, NewNode, index = 0;
	//	 * Output eErr = eLIST_NO_ERR
	//			  NewNode inserted as first node
	//	 */
	//	TEST_METHOD(Test_Insert_1_1)
	//	{
	//		LinkedList<unsigned int> uiList(0);
	//		Assert::IsTrue(uiList.GetCount() == 0);
	//		unsigned int idx = 0;
	//		E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	//		Node<unsigned int> _Node(10);
	//		eErr = uiList.Insert(_Node, idx);
	//		Assert::IsTrue(eErr == eLIST_NO_ERR);
	//		Assert::IsTrue(uiList.GetCount() == 1);
	//		Assert::IsTrue(uiList[0] == _Node.GetVal());
	//	}

	//	/*
	//	 * Test_Insert_1_2
	//	 * Input: Empty list, NewNode, index = last index, 1;
	//	 * Output eErr = eLIST_NO_ERR
	//			  NewNodes inserted
	//	 */
	//	TEST_METHOD(Test_Insert_1_2)
	//	{
	//		LinkedList<unsigned int> uiList(0);
	//		Assert::IsTrue(uiList.GetCount() == 0);
	//		unsigned int idx = 0;
	//		E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	//		Node<unsigned int> _Node(10);
	//		eErr = uiList.Insert(_Node, idx);
	//		Assert::IsTrue(eErr == eLIST_NO_ERR);
	//		Assert::IsTrue(uiList.GetCount() == 1);
	//		Assert::IsTrue(uiList[0] == _Node.GetVal());

	//		eErr = uiList.Insert(_Node, uiList.GetCount() - 1);
	//		Assert::IsTrue(eErr == eLIST_NO_ERR);
	//		Assert::IsTrue(uiList.GetCount() == 2);
	//		Assert::IsTrue(uiList[1] == _Node.GetVal());

	//		eErr = uiList.Insert(_Node, 1);
	//		Assert::IsTrue(eErr == eLIST_NO_ERR);
	//		Assert::IsTrue(uiList.GetCount() == 3);
	//		Assert::IsTrue(uiList[1] == _Node.GetVal());
	//	}

	//	/*
	//	 * Test_Insert_1_3
	//	 * Input: Empty list, NewNode, index = > Count
	//	 * Output eErr = eLIST_INVALID_INDEX
	//	 */
	//	TEST_METHOD(Test_Insert_1_3)
	//	{
	//		LinkedList<unsigned int> uiList(0);
	//		Assert::IsTrue(uiList.GetCount() == 0);
	//		unsigned int idx = 5;
	//		E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	//		Node<unsigned int> _Node(10);
	//		eErr = uiList.Insert(_Node, idx);
	//		Assert::IsTrue(eErr == eLIST_INVALID_INDEX);
	//		Assert::IsTrue(uiList.GetCount() == 0);
	//	}

	//	/*
	//	 * Test_Insert_1_4
	//	 * Input: list {0,1,2,3} with capacity = 4 , NewNode, index = 0
	//	 * Output eErr = eLIST_OVER_CAPACITY
	//	 *				 no node inserted
	//	 */
	//	TEST_METHOD(Test_Insert_1_4)
	//	{
	//		LinkedList<unsigned int> uiList(4);
	//		Assert::IsTrue(uiList.GetCount() == 0);
	//		for (unsigned int i = 0; i < 4; i++)
	//		{
	//			uiList.Insert(i, 0);
	//		}
	//		E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	//		Node<unsigned int> _Node(10);
	//		eErr = uiList.Insert(_Node, 0);

	//		Assert::IsTrue(eErr == eLIST_OVER_CAPACITY);
	//		Assert::IsTrue(uiList.GetCount() == 4);
	//	}
	//};
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
			LinkedList<unsigned int> uiList(0);
			Assert::IsTrue(uiList.GetCount() == 0);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = uiList.RemoveLast();

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
			LinkedList<unsigned int> uiList(0);
			Assert::IsTrue(uiList.GetCount() == 0);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			for (unsigned int i = 0; i < 6; i++)
			{
				uiList.Append(i);
			}
			Assert::IsTrue(uiList.GetCount() == 6);
			Assert::IsTrue(uiList[uiList.GetCount() - 1] == 5);
			eErr = uiList.RemoveLast();

			Assert::IsTrue(uiList.GetCount() == 5);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(uiList[uiList.GetCount() - 1] == 4);
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
			LinkedList<unsigned int> uiList(0);
			Assert::IsTrue(uiList.GetCount() == 0);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = uiList.RemoveByIdx(10);
			Assert::IsTrue(eErr == eLIST_INVALID_INDEX);
		}
		/*
		 * Test_RemoveByIdx_2
		 * Input: list { 0, 1, 2, 3, 4, 5 }, remove idx 7
		 * Expected Output: eErr = eLIST_INVALID_INDEX
		 */
		TEST_METHOD(Test_RemoveByIdx_2)
		{
			LinkedList<unsigned int> uiList(0);
			Assert::IsTrue(uiList.GetCount() == 0);
			for (unsigned int i = 0; i < 6; i++)
			{
				uiList.Append(i);
			}
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = uiList.RemoveByIdx(7);
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
			LinkedList<unsigned int> uiList(0);
			Assert::IsTrue(uiList.GetCount() == 0);
			for (unsigned int i = 0; i < 6; i++)
			{
				uiList.Append(i);
			}
			Assert::IsTrue(uiList.GetCount() == (6 - 0));

			// Last index
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = uiList.RemoveByIdx(5);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(uiList.GetCount() == (6 - 1));

			// Random index
			eErr = uiList.RemoveByIdx(3);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(uiList[3] == 4);
			Assert::IsTrue(uiList.GetCount() == (6 - 2));

			// First index
			eErr = uiList.RemoveByIdx(0);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(uiList[0] == 1);
			Assert::IsTrue(uiList.GetCount() == (6 - 3));
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
			LinkedList<unsigned int> uiList(2);
			Assert::IsTrue(uiList.Clear() == eLIST_EMPTY_LIST);
		}
		/* Test_Clear_2
		 * Input : List { 1, 1, 1, 1, 1, 1, 1, 1 }
		 * Expected Output: eErr = eLIST_EMPTY_LIST
							List cleared
		 */
		TEST_METHOD(Test_Clear_2)
		{
			LinkedList<unsigned int> uiList(10);
			for (unsigned int i = 0; i < 10; i++)
			{
				unsigned uiObj = i;
				uiList.Append(uiObj);
			}
			Assert::IsTrue(uiList.GetCount() == 10);
			Assert::IsTrue(uiList.Clear() == eLIST_EMPTY_LIST);
			Assert::IsTrue(uiList.GetCount() == 0);
		}
	};
	// E_LIST_ERROR_TYPE GetIndexList(T val, LinkedList<unsigned int>& idxList);
	TEST_CLASS(Test_GetIndexList)
	{
		LinkedList<unsigned int> m_uiList;
	public:
		void Setup(unsigned uiList_cap = 10)
		{
			unsigned int uiObj = 0;
			m_uiList = LinkedList<unsigned int>(uiList_cap);
			uiObj = 0;
			m_uiList.Append(uiObj);
			uiObj = 1;
			m_uiList.Append(uiObj);
			uiObj = 2;
			m_uiList.Append(uiObj);
			uiObj = 3;
			m_uiList.Append(uiObj);
			uiObj = 4;
			m_uiList.Append(uiObj);
			uiObj = 1;
			m_uiList.Append(uiObj);
		}
		void Clean()
		{
		}
		
		/* Test_GetIndexList_1_1
		 * Input : Empty List
		 * Expected Output: eErr = eLIST_EMPTY_LIST
		 */
		TEST_METHOD(Test_GetIndexList_1_1)
		{
			LinkedList<unsigned int> uiList(13);
			Assert::IsTrue(uiList.GetCount() == 0);

			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			LinkedList<unsigned int> uiIdxList(0);

			eErr = uiList.GetIndexList(1, uiIdxList);
			Assert::IsTrue(eErr == eLIST_EMPTY_LIST);
		}
		/* Test_GetIndexList_1_2
		 * Input : List { 0, 1 , 2, 3, 4, 1 }, find value "1"
		 * Expected Output: eErr = eLIST_NO_ERR
							correct list of indices of value "1"
		 */
		TEST_METHOD(Test_GetIndexList_1_2)
		{
			Setup();
			LinkedList<unsigned int> uiIdxList(0);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = m_uiList.GetIndexList(1, uiIdxList);

			Assert::IsTrue(uiIdxList.GetCount() == 2);
			Assert::IsTrue((uiIdxList[0] == 1) && (uiIdxList[1] == 5));
			Clean();
		}

		/* Test_GetIndexList_1_3
		 * Input : List { 0, 1 , 2, 3, 4, 1 }, find value "10"
		 * Expected Output: eErr = Node not found 
		 */
		TEST_METHOD(Test_GetIndexList_1_3)
		{
			Setup();
			LinkedList<unsigned int> uiIdxList(0);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = m_uiList.GetIndexList(10, uiIdxList);

			Assert::IsTrue(eErr == eLIST_NODE_NOT_FOUND);
			Assert::IsTrue(uiIdxList.GetCount() == 0);
			Clean();
		}

	};
	//// Node<T>* GetNodeByIdx(unsigned int uiIdx);
	//TEST_CLASS(Test_GetNodeByIdx)
	//{
	//public:
	//	/*
	//	 * Test_GetNodeByIdx_1_1
	//	 * Input: Invalid index, List { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }
	//	 * Expected output: NULL
	//	 */
	//	TEST_METHOD(Test_GetNodeByIdx_1_1)
	//	{
	//		// Step 1: Create a list with 10 elements
	//		LinkedList<unsigned int> uiList(10);
	//		for (unsigned int i = 0; i < 10; i++)
	//		{
	//			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	//			Node<unsigned int> _Node(i);
	//			eErr = uiList.Append(_Node);
	//			Assert::IsTrue(eErr == eLIST_NO_ERR);
	//		}
	//		// Step 2: Get node by index
	//		Assert::IsTrue(uiList.GetNodeByIdx(12) == NULL);
	//	}
	//	/*
	//	 * Test_GetNodeByIdx_1_2
	//	 * Input: valid index, List { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }
	//	 * Expected output: node with right value
	//	 */
	//	TEST_METHOD(Test_GetNodeByIdx_1_2)
	//	{
	//		// Step 1: Create a list with 10 elements
	//		LinkedList<unsigned int> uiList(10);
	//		for (unsigned int i = 0; i < 10; i++)
	//		{
	//			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	//			Node<unsigned int> _Node(i);
	//			eErr = uiList.Append(_Node);
	//			Assert::IsTrue(eErr == eLIST_NO_ERR);
	//		}
	//		// Step 2: Get node by index
	//		Assert::IsTrue(uiList.GetNodeByIdx(12) == NULL);
	//		Assert::IsTrue(uiList.GetNodeByIdx(0)->GetVal() == 0);
	//	}
	//};
	//// E_LIST_ERROR_TYPE AddFirst (Node<T>& NewLast);
	//TEST_CLASS(Test_AddFirst_1)
	//{
	//public:
	//	/*
	//	 *  Test_AddFirst_1_1
	//	 *	Input: Node, empty list
	//	 *  Expected output: eErr = eLIST_NO_ERR,
	//						 m_pFirst == m_pLast,
	//						 m_pFist->Val == Node.val
	//						 list.m_uiNodeCount increases
	//	 */
	//	TEST_METHOD(Test_AddFirst_1_1)
	//	{
	//		LinkedList<unsigned int> uiList(1);
	//		Assert::IsTrue(uiList.GetCount() == 0);
	//		Node<unsigned int> node1(10);
	//		E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	//		eErr = uiList.AddFirst(node1);
	//		Assert::IsTrue(eLIST_NO_ERR == eErr);

	//		Assert::IsTrue(uiList.m_pFirst == uiList.m_pLast);
	//		Assert::IsTrue(uiList[0] == node1.GetVal());
	//		Assert::IsTrue(uiList.GetCount() == 1);
	//	}

	//	/*
	//	 *  Test_AddFirst_1_2
	//	 *	Input: Node, over capacity list
	//	 *  Expected output: eErr = eLIST_OVER_CAPACITY
	//						 list stays the same
	//	 */
	//	TEST_METHOD(Test_AddFirst_1_2)
	//	{
	//		LinkedList<unsigned int> uiList(1);
	//		Assert::IsTrue(uiList.GetCount() == 0);
	//		Node<unsigned int> node1(10);
	//		E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	//		eErr = uiList.AddFirst(node1);
	//		Assert::IsTrue(eLIST_NO_ERR == eErr);

	//		Node<unsigned int> node2(20);
	//		eErr = uiList.AddFirst(node2);
	//		Assert::IsTrue(eLIST_OVER_CAPACITY == eErr);
	//		Assert::IsTrue(uiList.GetCount() == 1);
	//	}

	//	/*
	//	 *  Test_AddFirst_1_3
	//	 *	Input: Nodes, unlimited size list
	//	 *  Expected output: eErr = eLIST_NO_ERR
	//						 list changes as Adding First
	//	 */
	//	TEST_METHOD(Test_AddFirst_1_3)
	//	{
	//		LinkedList<unsigned int> uiList(0);
	//		Assert::IsTrue(uiList.GetCount() == 0);
	//		Node<unsigned int> node1(10);
	//		Node<unsigned int> node2(20);
	//		for (int i = 0; i < 30; i++)
	//		{
	//			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	//			eErr = uiList.AddFirst((i % 2) ? node1 : node2);
	//			Assert::IsTrue(eLIST_NO_ERR == eErr);
	//		}

	//		Assert::IsTrue(uiList.GetCount() == 30);
	//		Assert::IsTrue(uiList[0] == 10);
	//		Assert::IsTrue(uiList[29] == 20);
	//	}

	//};
	//// E_LIST_ERROR_TYPE Append (Node<T>& NewLast);
	//TEST_CLASS(Test_Append_SingleNode)
	//{
	//public:
	//	/*
	//	 *  Test_Append_SingleNode_1
	//	 *	Input: Node, empty list
	//	 *  Expected output: eErr = eLIST_NO_ERR,
	//						 m_pFirst == m_pLast,
	//						 m_pFist->Val == Node.val
	//						 list.m_uiNodeCount increases
	//	 */
	//	TEST_METHOD(Test_Append_SingleNode_1)
	//	{
	//		LinkedList<unsigned int> uiList(1);
	//		Assert::IsTrue(uiList.GetCount() == 0);
	//		Node<unsigned int> node1(10);
	//		E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	//		eErr = uiList.Append(node1);
	//		Assert::IsTrue(eLIST_NO_ERR == eErr);

	//		Assert::IsTrue(uiList.m_pFirst == uiList.m_pLast);
	//		Assert::IsTrue(uiList[0] == node1.GetVal());
	//		Assert::IsTrue(uiList.GetCount() == 1);
	//	}

	//	/*
	//	 *  Test_Append_SingleNode_2
	//	 *	Input: Node, over capacity list
	//	 *  Expected output: eErr = eLIST_OVER_CAPACITY
	//						 list stays the same
	//	 */
	//	TEST_METHOD(Test_Append_SingleNode_2)
	//	{
	//		LinkedList<unsigned int> uiList(1);
	//		Assert::IsTrue(uiList.GetCount() == 0);
	//		Node<unsigned int> node1(10);
	//		E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	//		eErr = uiList.Append(node1);
	//		Assert::IsTrue(eLIST_NO_ERR == eErr);

	//		Node<unsigned int> node2(20);
	//		eErr = uiList.Append(node2);
	//		Assert::IsTrue(eLIST_OVER_CAPACITY == eErr);
	//		Assert::IsTrue(uiList.GetCount() == 1);
	//	}

	//	/*
	//	 *  Test_Append_SingleNode_3
	//	 *	Input: Nodes, unlimited size list
	//	 *  Expected output: eErr = eLIST_NO_ERR
	//						 list changes as appending
	//	 */
	//	TEST_METHOD(Test_Append_SingleNode_3)
	//	{
	//		LinkedList<unsigned int> uiList(0);
	//		Assert::IsTrue(uiList.GetCount() == 0);
	//		Node<unsigned int> node1(10);
	//		Node<unsigned int> node2(20);
	//		for (int i = 0; i < 30; i++)
	//		{
	//			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	//			eErr = uiList.Append((i % 2) ? node1 : node2);
	//			Assert::IsTrue(eLIST_NO_ERR == eErr);
	//		}

	//		Assert::IsTrue(uiList.GetCount() == 30);
	//		Assert::IsTrue(uiList[0] == 20);
	//		Assert::IsTrue(uiList[29] == 10);
	//	}

	//};

    // E_LIST_ERROR_TYPE Append (LinkedList<T>& InList);
	TEST_CLASS(Test_Append_List)
	{
	public:
		/*
		 *  Test_Append_List_1
		 *	Input: Nodes, unlimited size list
		 *  Expected output: eErr = eLIST_NO_ERR
							 list changes as appending
		 */
		TEST_METHOD(Test_Append_List_1)
		{
			LinkedList<unsigned int> uiList_1(0);
			LinkedList<unsigned int> uiList_2(0);
			LinkedList<unsigned int> uiList_toAppend(0);

			Assert::IsTrue(uiList_1.GetCount() == 0);
			for (unsigned int i = 0; i < 30; i++)
			{
				unsigned uiObj = i;
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				eErr = uiList_1.Append(uiObj);
				Assert::IsTrue(eErr == eLIST_NO_ERR);
				uiObj *= 2;
				eErr = uiList_2.Append(uiObj);
				Assert::IsTrue(eErr == eLIST_NO_ERR);
			}
			Assert::IsTrue(uiList_1.GetCount() == 30);
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = uiList_toAppend.Append(uiList_1);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(uiList_toAppend.GetCount() == 30);
			Assert::IsTrue(uiList_toAppend[29] == 29);

			eErr = uiList_toAppend.Append(uiList_2);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(uiList_toAppend.GetCount() == 60);
			Assert::IsTrue(uiList_toAppend[30] == 0);
		}
		/*
		 *  Test_Append_List_2
		 *	Input: Nodes, over capacity, invalid index ( index > count )
		 *  Expected output: eErr = eLIST_INVALID_INDEX 
							 list mustn't changes as appending
		 */
		TEST_METHOD(Test_Append_List_2)
		{
			LinkedList<unsigned int> uiList(0);
			LinkedList<unsigned int> uiList_toAppend(10);
			Assert::IsTrue(uiList.GetCount() == 0);
			for (int i = 0; i < 30; i++)
			{
				unsigned uiObj1 = 10;
				unsigned uiObj2 = 20;
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				eErr = uiList.Append((i % 2) ? uiObj1 : uiObj2);
				Assert::IsTrue(eLIST_NO_ERR == eErr);
			}
			Assert::IsTrue(uiList.GetCount() == 30);

			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = uiList_toAppend.Append(uiList);
			Assert::IsTrue(eErr == eLIST_OVER_CAPACITY);
			Assert::IsTrue(uiList_toAppend.GetCount() == 0);
		}
	};
	TEST_CLASS(USER_LINKLIST)
	{
	public:

		//TEST_METHOD(Test_NodeCtor)
		//{
		//	Node<unsigned int> a(10);
		//	Assert::IsTrue(a.GetVal() == 10);
		//}

		//TEST_METHOD(Test_NodeSetVal)
		//{
		//	Node<unsigned int> a(10);
		//	a.SetVal(5);
		//	Assert::IsTrue(a.GetVal() == 5);
		//}

		TEST_METHOD(Test_ListCtor)
		{
			LinkedList<unsigned int> uiList(10);
			Assert::IsTrue(uiList.GetCount() == 0);
			Assert::IsTrue(uiList.GetCapacity() == 10);
		}
	};
}
