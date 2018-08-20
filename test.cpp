#include "stdafx.h"
#include "CppUnitTest.h"
#include "list_node.h"
#include "linked_list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
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

		TEST_METHOD(Test_GetValByIdx1)
		{
			LinkedList<unsigned int> _List(10);
			Assert::IsTrue(_List.GetCount() == 0);
			for (unsigned int i = 0; i < 20; i++)
			{
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				eErr = _List.Append(i);
				if (i < 10)
				{
					Assert::IsTrue(eErr == eLIST_NO_ERR);
					Assert::IsTrue(_List.GetCount() == (i + 1));
				}
				else
				{
					Assert::IsTrue(eErr == eLIST_OVER_CAPACITY);
				}
			}

			unsigned int first = 100;
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = _List.GetValByIdx(first, 20);
			Assert::IsTrue(eErr == eLIST_INVALID_INDEX);

			eErr = _List.GetValByIdx(first, 0);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(first == 0);

			eErr = _List.GetValByIdx(first, 5);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(first == 5);

			eErr = _List.GetValByIdx(first, 9);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(first == 9);
		}

		TEST_METHOD(Test_GetValByIdx2)
		{
			LinkedList<unsigned int> _List(10);
			Assert::IsTrue(_List.GetCount() == 0);
			for (unsigned int i = 0; i < 20; i++)
			{
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				eErr = _List.Append(i);
				if (i < 10)
				{
					Assert::IsTrue(eErr == eLIST_NO_ERR);
					Assert::IsTrue(_List.GetCount() == (i + 1));
				}
				else
				{
					Assert::IsTrue(eErr == eLIST_OVER_CAPACITY);
				}
			}

			unsigned int uiTmp = 100;

			uiTmp = _List[0];
			Assert::IsTrue(uiTmp == 0);

			_List[0] = 6;
			Assert::IsTrue(_List[0] == 6);

			uiTmp = _List[5];
			Assert::IsTrue(uiTmp == 5);

			uiTmp = _List[9];
			Assert::IsTrue(uiTmp == 9);
		}

		TEST_METHOD(Test_GetIndex)
		{
			LinkedList<unsigned int> _List(10);
			Assert::IsTrue(_List.GetCount() == 0);
			for (unsigned int i = 0; i < 10; i++)
			{
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				eErr = _List.Append(i * 2);
				if (i < 10)
				{
					Assert::IsTrue(eErr == eLIST_NO_ERR);
					Assert::IsTrue(_List.GetCount() == (i + 1));
				}
			}
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			unsigned int uiIdx = 100;

			eErr = _List.GetIndex(1, &uiIdx);
			Assert::IsTrue(eErr == eLIST_NODE_NOT_FOUND);

			eErr = _List.GetIndex(0, &uiIdx);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(uiIdx == 0);

			eErr = _List.GetIndex(12, &uiIdx);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(uiIdx == 6);

			eErr = _List.GetIndex(18, &uiIdx);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(uiIdx == 9);
		}

		TEST_METHOD(Test_AddFirst)
		{
			LinkedList<unsigned int> _List(10);
			Assert::IsTrue(_List.GetCount() == 0);
			for (unsigned int i = 0; i < 20; i++)
			{
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				eErr = _List.AddFirst(i);
				if (i < 10)
				{
					Assert::IsTrue(eErr == eLIST_NO_ERR);
					Assert::IsTrue(_List.GetCount() == (i + 1));
					unsigned int first = 100;
					_List.GetValByIdx(first, 0);
					Assert::IsTrue(first == i);
				}
				else
				{
					Assert::IsTrue(eErr == eLIST_OVER_CAPACITY);
				}
			}
		}

		TEST_METHOD(Test_Append)
		{
			LinkedList<unsigned int> _List(10);
			Assert::IsTrue(_List.GetCount() == 0);
			for (unsigned int i = 0; i < 20; i++)
			{
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				eErr = _List.Append(i);
				if (i < 10)
				{
					Assert::IsTrue(eErr == eLIST_NO_ERR);
					Assert::IsTrue(_List.GetCount() == (i + 1));
					unsigned int last = 100;
					_List.GetValByIdx(last, _List.GetCount() - 1);
					Assert::IsTrue(last == i);
				}
				else
				{
					Assert::IsTrue(eErr == eLIST_OVER_CAPACITY);
				}
			}
		}

		TEST_METHOD(Test_Insert)
		{
			LinkedList<unsigned int> _List(13);
			Assert::IsTrue(_List.GetCount() == 0);
			for (unsigned int i = 0; i < 10; i++)
			{
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				eErr = _List.Append(i);
				Assert::IsTrue(eErr == eLIST_NO_ERR);
				Assert::IsTrue(_List.GetCount() == (i + 1));
			}
			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

			unsigned int curCnt = _List.GetCount();
			unsigned int uiIdx = 10;

			eErr = _List.Insert(6, uiIdx);
			Assert::IsTrue(eErr == eLIST_INVALID_INDEX);
			Assert::IsTrue(curCnt == _List.GetCount());

			uiIdx = 0;
			unsigned int uiTmp = 100;
			unsigned int setVal = 6;
			eErr = _List.Insert(setVal, uiIdx);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			_List.GetValByIdx(uiTmp, uiIdx);
			Assert::IsTrue(uiTmp == setVal);
			Assert::IsTrue(++curCnt = _List.GetCount());

			uiIdx = 4;
			eErr = _List.Insert(setVal, uiIdx);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			_List.GetValByIdx(uiTmp, uiIdx);
			Assert::IsTrue(uiTmp == setVal);
			Assert::IsTrue(++curCnt = _List.GetCount());

			uiIdx = 9;
			eErr = _List.Insert(setVal, uiIdx);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			_List.GetValByIdx(uiTmp, uiIdx);
			Assert::IsTrue(uiTmp == setVal);
			Assert::IsTrue(++curCnt = _List.GetCount());

			// List capacity = 13
			eErr = _List.Insert(setVal, uiIdx);
			Assert::IsTrue(curCnt == _List.GetCount());
			Assert::IsTrue(eErr == eLIST_OVER_CAPACITY);
		}
		TEST_METHOD(Test_InsertList)
		{
			//LinkedList<unsigned int> List1(20);
			//LinkedList<unsigned int> List2(20);

			//for (unsigned int i = 0; i < 10; i++)
			//{
			//	List1.Append(i);
			//	List2.Append(i);
			//}
			//Assert::IsTrue(List1.GetCount() == 10);
			//E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

			//eErr = List1.Insert(List2, 5);
			//Assert::IsTrue(eErr == eLIST_NO_ERR);

			//Assert::IsTrue(List1.GetCapacity() == 40);

			//Assert::IsTrue(List1.GetCount() == 20);

			//for (int i = 0; i > 10; i++)
			//{
			//	Assert::IsTrue(List1[i + 5] == List2[2]);
			//}
		}

		TEST_METHOD(Test_Remove)
		{
			LinkedList<unsigned int> _List(13);
			Assert::IsTrue(_List.GetCount() == 0);


			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = _List.Remove(1);
			Assert::IsTrue(eErr == eLIST_EMPTY_LIST);

			for (unsigned int i = 0; i < 10; i++)
			{
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				eErr = _List.Append(i);
				Assert::IsTrue(eErr == eLIST_NO_ERR);
				Assert::IsTrue(_List.GetCount() == (i + 1));
			}

			unsigned int curCnt = _List.GetCount();

			eErr = _List.Remove(10);
			Assert::IsTrue(eErr == eLIST_NODE_NOT_FOUND);
			Assert::IsTrue(curCnt == _List.GetCount());

			eErr = _List.Remove(0);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(--curCnt == _List.GetCount());
		}

		TEST_METHOD(Test_RemoveFirst)
		{
			LinkedList<unsigned int> _List(13);
			Assert::IsTrue(_List.GetCount() == 0);


			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = _List.RemoveFirst();
			Assert::IsTrue(eErr == eLIST_EMPTY_LIST);

			for (unsigned int i = 0; i < 10; i++)
			{
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				eErr = _List.Append(i);
				Assert::IsTrue(eErr == eLIST_NO_ERR);
				Assert::IsTrue(_List.GetCount() == (i + 1));
			}

			unsigned int curCnt = _List.GetCount();

			unsigned int uiFirst = 100;
			eErr = _List.RemoveFirst();
			_List.GetValByIdx(uiFirst, 0);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(uiFirst == 1);
			Assert::IsTrue(--curCnt == _List.GetCount());
		}

		TEST_METHOD(Test_RemoveLast)
		{
			LinkedList<unsigned int> _List(13);
			Assert::IsTrue(_List.GetCount() == 0);

			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = _List.RemoveLast();
			Assert::IsTrue(eErr == eLIST_EMPTY_LIST);

			for (unsigned int i = 0; i < 10; i++)
			{
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				eErr = _List.Append(i);
				Assert::IsTrue(eErr == eLIST_NO_ERR);
				Assert::IsTrue(_List.GetCount() == (i + 1));
			}

			unsigned int curCnt = _List.GetCount();

			unsigned int uiLast = 100;
			eErr = _List.RemoveLast();
			_List.GetValByIdx(uiLast, _List.GetCount() - 1);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(uiLast == 8);
			Assert::IsTrue(--curCnt == _List.GetCount());
		}

		TEST_METHOD(Test_RemoveByIdx)
		{
			LinkedList<unsigned int> _List(13);
			Assert::IsTrue(_List.GetCount() == 0);

			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			eErr = _List.RemoveByIdx(0);
			Assert::IsTrue(eErr == eLIST_EMPTY_LIST);

			for (unsigned int i = 0; i < 10; i++)
			{
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				eErr = _List.Append(i);
				Assert::IsTrue(eErr == eLIST_NO_ERR);
				Assert::IsTrue(_List.GetCount() == (i + 1));
			}

			unsigned int curCnt = _List.GetCount();

			unsigned int uiTmp = 100;

			// Remove invalid index
			unsigned int uiIdx = 20;
			eErr = _List.RemoveByIdx(uiIdx);
			Assert::IsTrue(eErr == eLIST_INVALID_INDEX);
			Assert::IsTrue(curCnt == _List.GetCount());

			// Remove first index
			uiIdx = 0;
			_List.GetValByIdx(uiTmp, 0);
			Assert::IsTrue(uiTmp == 0);
			eErr = _List.RemoveByIdx(uiIdx);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(--curCnt == _List.GetCount());
			_List.GetValByIdx(uiTmp, uiIdx);
			Assert::IsTrue(uiTmp == 1);

			// Remove last index
			uiIdx = _List.GetCount() - 1;
			eErr = _List.RemoveByIdx(uiIdx);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(--curCnt == _List.GetCount());
			_List.GetValByIdx(uiTmp, _List.GetCount() - 1);
			Assert::IsTrue(uiTmp == 8);

			// Remove random index
			uiIdx = 3;
			// [1,2,3,4,5,6,7,8]
			eErr = _List.RemoveByIdx(uiIdx);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			// [1,2,3,5,6,7,8]
			Assert::IsTrue(--curCnt == _List.GetCount());
			_List.GetValByIdx(uiTmp, 3);
			Assert::IsTrue(uiTmp == 5);
		}

		TEST_METHOD(Test_Clear)
		{
			LinkedList<unsigned int> _List(13);
			Assert::IsTrue(_List.GetCount() == 0);

			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

			for (unsigned int i = 0; i < 10; i++)
			{
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				eErr = _List.Append(i);
				Assert::IsTrue(eErr == eLIST_NO_ERR);
				Assert::IsTrue(_List.GetCount() == (i + 1));
			}

			eErr = _List.Clear();
			Assert::IsTrue(eErr = eLIST_EMPTY_LIST);
			Assert::IsTrue(_List.GetCount() == 0);
		}

		TEST_METHOD(Test_GetIndexList_1)
		{
			LinkedList<unsigned int> _List(13);
			Assert::IsTrue(_List.GetCount() == 0);

			E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
			LinkedList<unsigned int> uiIdxList(0);
			eErr = _List.GetIndexList(1, uiIdxList);
			Assert::IsTrue(eErr == eLIST_EMPTY_LIST);

			for (unsigned int i = 0; i < 5; i++)
			{
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				eErr = _List.Append(i);
				Assert::IsTrue(eErr == eLIST_NO_ERR);
				Assert::IsTrue(_List.GetCount() == (i + 1));
			}

			for (unsigned int i = 0; i < 5; i++)
			{
				E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
				eErr = _List.Append(1);
				Assert::IsTrue(eErr == eLIST_NO_ERR);
			}

			eErr = _List.GetIndexList(10, uiIdxList);
			Assert::IsTrue(eErr == eLIST_NODE_NOT_FOUND);

			eErr = _List.GetIndexList(1, uiIdxList);
			Assert::IsTrue(eErr == eLIST_NO_ERR);
			Assert::IsTrue(uiIdxList.GetCount() == 6);

			unsigned int uiTmp = 100;
			uiIdxList.GetValByIdx(uiTmp, 0);
			Assert::IsTrue(uiTmp == 1);

			uiIdxList.GetValByIdx(uiTmp, 1);
			Assert::IsTrue(uiTmp == 5);
		}

		TEST_METHOD(Test_GetIndexList_2)
		{
		}
	};
}