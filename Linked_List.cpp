//============================================================================
// Name        : Linked_List.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Linked_List.h"
#include <iostream>
#include <vector>
#include "dbg.h"

using namespace std;
/*
 * @brief: Macro definition
 */
#ifndef NULL_PTR
#define NULL_PTR 0
#endif
#define UNLIMITTED_LIST_SIZE	(unsigned int)0
/*
 * @brief: ListNode member definition
 */
template<class T>
ListNode<T>::ListNode()
{
	m_pNextNode = NULL_PTR;
	debug("New node created with no value");
}

template<class T>
ListNode<T>::ListNode(T val)
{
	m_pNextNode = NULL_PTR;
	m_Val = val;
	debug("New node created with [value]@[address]: [%d]@[%x]", m_Val, this);
}

template<class T>
ListNode<T>::ListNode(ListNode<T> &node)
{
	m_pNextNode = NULL_PTR;
	m_Val = node.m_Val;
    m_pNextNode = node.m_pNextNode;
	debug("New node created with [value]@[address]: [%d]@[%x]", m_Val, this);
}

template<class T>
ListNode<T>::~ListNode()
{
	debug("Node [%d]@[%x] destroyed", m_Val,this);
}

template <class T>
T ListNode<T>::GetVal(void)
{
	return m_Val;
}

template <class T>
void ListNode<T>::SetVal(T new_val)
{
	m_Val = new_val;
}


/*
 * @brief: LinkedList member definition
 */
template<class T>
LinkedList<T>::LinkedList(unsigned int uiCapacity)
{
	m_pFirst = NULL_PTR;
	m_pLast = NULL_PTR;
	m_uiNodeCount = 0;
	m_uiCapacity = uiCapacity;
	debug("List@[%x] created with capacity %d", this, m_uiCapacity);
}

template<class T>
LinkedList<T>::LinkedList(ListNode<T>& Head, unsigned int uiCapacity)
{
	m_pFirst = NULL_PTR;
	m_pLast = NULL_PTR;
	m_uiNodeCount = 0;
	m_uiCapacity = uiCapacity;
	Append(Head);
	debug("List@[%x] created with capacity %d, nCnt = %d", this, m_uiCapacity,m_uiNodeCount);
}
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& List, unsigned int uiCapacity)
{
	m_pFirst = NULL_PTR;
	m_pLast = NULL_PTR;
	m_uiNodeCount = 0;
	if (UNLIMITTED_LIST_SIZE != uiCapacity)
	{
		m_uiCapacity = (uiCapacity > List.m_uiCapacity) ? uiCapacity : List.m_uiCapacity;
	}
	else
	{
		m_uiCapacity = UNLIMITTED_LIST_SIZE;
	}

	for(ListNode<T> *node = List.m_pFirst; node != NULL_PTR; node = node->m_pNextNode)
	{
		Append(*node);
	}
	debug("List@[%x] created with capacity %d, nCnt = %d", this, m_uiCapacity,m_uiNodeCount);
}

template<class T>
LinkedList<T>::~LinkedList()
{
	ListNode<T> *pFirst = m_pFirst;
	while(pFirst != NULL_PTR)
	{
		ListNode<T> *pNextNode = pFirst->m_pNextNode;
		delete pFirst;
		pFirst = pNextNode;
	}
	m_pFirst = m_pLast = NULL_PTR;
	m_uiNodeCount = 0;
	debug("List@[%x] destroyed", this);
}

template <class T>
E_LIST_ERROR_TYPE LinkedList<T>::AddFirst (ListNode<T>& NewHead)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	if ((UNLIMITTED_LIST_SIZE == m_uiCapacity)||(m_uiNodeCount < m_uiCapacity))
	{
		ListNode<T> *pNewHead = new ListNode<T>(NewHead);
		if(0 == m_uiNodeCount)
		{
			m_pFirst = m_pLast = pNewHead;
		}
		else
		{
			pNewHead->m_pNextNode = m_pFirst;
			m_pFirst = pNewHead;
		}
        ++m_uiNodeCount;
		debug("Added new node [value]@[address] = [%d]@[%x]", m_pFirst->m_Val, m_pFirst);
	}
	else
	{
		eErr = eLIST_OVER_CAPACITY;
	}
	return eErr;
}

template <class T>
E_LIST_ERROR_TYPE LinkedList<T>::AddFirst (T NewHeadVal)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	if ((UNLIMITTED_LIST_SIZE == m_uiCapacity)||(m_uiNodeCount < m_uiCapacity))
	{
		ListNode<T> *pNewHead = new ListNode<T>(NewHeadVal);
		if(0 == m_uiNodeCount)
		{
			m_pFirst = m_pLast = pNewHead;
		}
		else
		{
			pNewHead->m_pNextNode = m_pFirst;
			m_pFirst = pNewHead;
		}
		++m_uiNodeCount;
		debug("Added new node [value]@[address] = [%d]@[%x] to List@[%x]", m_pFirst->m_Val, m_pFirst, this);
	}
	else
	{
		eErr = eLIST_OVER_CAPACITY;
	}
	return eErr;
}

/*
 * @brief: find the first ListNode<T> & that contain value.
 * @return: Linked list node if the node is found, Otherwise return NULL_PTR
 */
template<class T>
ListNode<T>* LinkedList<T>::Find (T Val)
{
	if(0 == m_uiNodeCount)
	{
		return NULL_PTR;
	}
	else
	{
		ListNode<T> *pTempNode = m_pFirst;
		while (pTempNode != NULL_PTR)
		{
			if (pTempNode->m_Val == Val)
			{
				break;
			}
			pTempNode = pTempNode->m_pNextNode;
		}
		return pTempNode;
	}
}

template<class T>
ListNode<T>* LinkedList<T>::FindLast(T Val)
{
	if(0 == m_uiNodeCount)
	{
		return NULL_PTR;
	}
	else
	{
		ListNode<T>* pNode = this->m_pFirst;
		ListNode<T>* pRet = NULL_PTR;
		while (pNode != NULL_PTR)
		{
			if (pNode->m_Val == Val)
			{
				pRet = pNode;
			}
			pNode = pNode->m_pNextNode;
		}
		debug("Found Node@[%x] with value [%d]", pRet, Val);
		return pRet;
	}
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Insert(T NodeVal, ListNode<T>& BaseNode)
{
	ListNode<T> node(NodeVal);
	return Insert(node, BaseNode);
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Insert(ListNode<T>& NewNode, ListNode<T>& BaseNode)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	unsigned int uiIdx = 0;
	eErr = GetIndex(BaseNode, &uiIdx);

	if (eErr != eLIST_NO_ERR) return eErr;
	
	Insert(NewNode, uiIdx);
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Insert(T NodeVal, unsigned int uiIdx)
{
	ListNode<T> node(NodeVal);
	return Insert(node, uiIdx);
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Insert(ListNode<T>& NewNode, unsigned int uiIdx)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	if (m_uiNodeCount <= uiIdx)
	{
		eErr = eLIST_INVALID_INDEX;
	}

	if (eErr != eLIST_NO_ERR)
	{
		return eErr;
	}

	if (uiIdx == 0)
	{
		eErr = AddFirst(NewNode);
	}
	else
	{
		ListNode<T>* pPrev = GetNodeByIdx(uiIdx - 1);
		ListNode<T>* pCur = GetNodeByIdx(uiIdx);
		if (pPrev && pCur)
		{
			eErr = AddBetween(*pPrev, *pCur, NewNode);
		}
		else eErr = eLIST_INVALID_NODE;
	}

	return eErr;
}

/*
 * @brief: Add one node after a given node in linked list.
 * @return: E_LIST_ERROR_TYPE
 */
template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::AddAfter(ListNode<T>& NewNode, ListNode<T>* BaseNode)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	if(0 == m_uiNodeCount)
	{
		eErr = eLIST_EMPTY_LIST;
	}
	else if (&NewNode == NULL_PTR)
	{
		eErr = eLIST_INVALID_NODE;
	}
	else if((UNLIMITTED_LIST_SIZE == m_uiCapacity)||(m_uiNodeCount < m_uiCapacity))
	{
		ListNode<T>* pTempNode = m_pFirst;
		while(pTempNode != NULL_PTR)
		{
			if (pTempNode == BaseNode)
			{
				break;
			}
			pTempNode = pTempNode->m_pNextNode;
		}
		if (NULL_PTR == pTempNode)
		{
			eErr = eLIST_NODE_NOT_FOUND;
		}
		else
		{
			ListNode<T> *pNewNode = new ListNode<T>(NewNode);
			if (pTempNode == m_pLast)
			{
				m_pLast->m_pNextNode = pNewNode;
				m_pLast = pNewNode;
			}
			else
			{
				pNewNode->m_pNextNode = pTempNode->m_pNextNode;
				pTempNode->m_pNextNode = pNewNode;
			}
			++m_uiNodeCount;
			std::cout << "Added new node [value][address] = [" << pNewNode->m_Val <<"][" << pNewNode << "]"\
								<<"after node value: "<<pTempNode->m_Val<< std::endl;
		}
	}
	else
	{
		std::cout<<"Over capacity for list !! \n";
		eErr = eLIST_OVER_CAPACITY;
	}
	return eErr;
}

/*
 * @brief: Add one node after a given node value in linked list.
 * @return: E_LIST_ERROR_TYPE
 */
template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::AddAfter(T NodeVal, ListNode<T>* BaseNode)
{
	ListNode<T> node(NodeVal);
	return AddAfter(node, BaseNode);
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::AddBetween(ListNode<T>& Left, ListNode<T>& Right, ListNode<T>& NewNode)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	if (Left.m_pNextNode != &Right)
	{
		eErr = eLIST_INVALID_NODE;
	}

	if (eErr != eLIST_NO_ERR)
	{
		return eErr;
	}

	ListNode<T> *pNewHead = new ListNode<T>(NewNode);
	Left.m_pNextNode = pNewHead;
	pNewHead->m_pNextNode = &Right;
	m_uiNodeCount++;

	return eErr;
} 

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Append (ListNode<T>& NewLast)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	if(m_uiCapacity <= m_uiNodeCount &&
	   UNLIMITTED_LIST_SIZE != m_uiNodeCount)
	{
		eErr = eLIST_OVER_CAPACITY;
	}

	if (eErr != eLIST_NO_ERR) 
	{
		return eErr;
	}

	ListNode<unsigned int> *node = new ListNode<T>(NewLast);
	if(NULL_PTR == m_pFirst)
	{
		m_pFirst = m_pLast = node;
	}
	else
	{
		m_pLast->m_pNextNode = node;
		m_pLast = node;
	}

	m_uiNodeCount++;
	debug("Added new node [value][address] = [%d]@[%x] to List@[%x]", m_pLast->m_Val, m_pLast, this);

	return eErr;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Append (T new_LastVal)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	if (m_uiCapacity <= m_uiNodeCount &&
		m_uiCapacity != UNLIMITTED_LIST_SIZE)
	{
		eErr = eLIST_OVER_CAPACITY;
	}

	if (eErr != eLIST_NO_ERR)
	{
		return eErr;
	}

	ListNode<unsigned int> *node = new ListNode<T>(new_LastVal);
	if (0 == m_uiNodeCount)
	{
		m_pFirst = m_pLast = node;
	}
	else
	{
		m_pLast->m_pNextNode = node;
		m_pLast = node;
	}
	m_uiNodeCount++;
	debug("Added new node [value][address] = [%d]@[%x] to List@[%x]", m_pLast->m_Val, m_pLast, this);

	return eErr;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::TraverseList()
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	if (0 == m_uiNodeCount)
	{
		eErr = eLIST_EMPTY_LIST;
	}

	if (eErr != eLIST_NO_ERR)
	{
		return eErr;
	}

	ListNode<T>* pNode = this->m_pFirst;

	std::cout << "List@[" << this << "]" << std::endl;
	std::cout << "|idx	|value	|Address" << std::endl;
	unsigned int uiIdx = 0;
	while (pNode != NULL_PTR)
	{
		
		std::cout << "|" << uiIdx++ << "	|" << pNode->m_Val << "	|" << pNode << std::endl;
		pNode = pNode->m_pNextNode;
	}
	return eErr;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Remove(T val)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	if (0 == m_uiNodeCount)
	{
		eErr = eLIST_EMPTY_LIST;
	}

	if (eErr != eLIST_NO_ERR)
	{
		return eErr;
	}

	ListNode<T>* pCurrent = this->m_pFirst;
	ListNode<T>* pNext = pCurrent->m_pNextNode;

	bool found = false;
	if (val == pCurrent->m_Val)
	{
		this->m_pFirst = pNext;
		delete pCurrent;
		found = true;
	}
	else
	{
		while (pNext != NULL_PTR)
		{
			if (pNext->m_Val == val)
			{
				pCurrent->m_pNextNode = pNext->m_pNextNode;
				delete pNext;
				found = true;
				break;
			}
			pCurrent = pNext;
			pNext = pNext->m_pNextNode;
		}
	}

	if (found)
	{
		this->m_uiNodeCount--;
	}
	else
	{
		eErr = eLIST_NODE_NOT_FOUND;
	}

	return eErr;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::RemoveFirst()
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	if (m_uiNodeCount == 0)
		eErr = eLIST_EMPTY_LIST;

	if (eErr != eLIST_NO_ERR)
	{
		return eErr;
	}

	ListNode<T>* pCurrent = m_pFirst;
	m_pFirst = pCurrent->m_pNextNode;
	delete pCurrent;
	m_uiNodeCount--;

	if (m_uiNodeCount <= 1)
		m_pLast = m_pFirst;

	return eErr;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::RemoveLast()
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	if (m_uiNodeCount == 0)
		eErr = eLIST_EMPTY_LIST;

	if (eErr != eLIST_NO_ERR)
	{
		return eErr;
	}
	
	delete m_pLast;
	m_uiNodeCount--;

	if (m_uiNodeCount == 0)
	{
		m_pLast = NULL_PTR;
	}
	else
	{
		ListNode<T>* pPrev = GetNodeByIdx(m_uiNodeCount - 1);
		if (pPrev)
		{
			pPrev->m_pNextNode = NULL_PTR;
			m_pLast = pPrev;
		}
		else
		{
			eErr = eLIST_INVALID_NODE;
		}
	}
	
	if (m_uiNodeCount <= 1)
	{
		m_pFirst = m_pLast;
	}

	return eErr;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::RemoveByIdx(unsigned int uiIndex)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	if (m_uiNodeCount == 0) 
	{
		eErr = eLIST_EMPTY_LIST; 
	}
	if (m_uiNodeCount <= uiIndex) 
	{
		eErr = eLIST_INVALID_INDEX; 
	}

	if (eErr != eLIST_NO_ERR)
	{
		return eErr;
	}

	if (0 == uiIndex)
	{
		eErr = RemoveFirst();
	}
	else if ((m_uiNodeCount - 1) == uiIndex)
	{
		eErr = RemoveLast();
	}
	else
	{
		ListNode<T>* pCur = GetNodeByIdx(uiIndex);
		ListNode<T>* pPrev = GetNodeByIdx(uiIndex - 1);
		if (pCur && pPrev)
		{
			pPrev->m_pNextNode = pCur->m_pNextNode;
			delete pCur;
			m_uiNodeCount--;
		}
		else
		{
			eErr = eLIST_INVALID_INDEX;
		}
	}

	return eErr;
}
template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::GetIndex(T val, unsigned int *puiIdxRet)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	if (m_uiNodeCount == 0) 
	{ 
		eErr = eLIST_EMPTY_LIST; 
	}

	if (eErr != eLIST_NO_ERR) 
	{
		return eErr; 
	}

	ListNode<T>* pCurrent = this->m_pFirst;
	bool bFound = false;
	unsigned int uiIdx = 0;
	while (pCurrent != NULL_PTR)
	{
		if (val == pCurrent->m_Val)
		{
			*puiIdxRet = uiIdx;
			bFound = true;
			break;
		}
		pCurrent = pCurrent->m_pNextNode;
		uiIdx++;
	}

	if (!bFound) { eErr = eLIST_NODE_NOT_FOUND; }
	return eErr;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::GetIndex(ListNode<T>& Node, unsigned int *puiIdxRet)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	if (0 == m_uiNodeCount)
	{
		eErr = eLIST_EMPTY_LIST;
	}

	if (eErr != eLIST_NO_ERR) return eErr;
	ListNode<T>* pCurrent = this->m_pFirst;
	bool bFound = false;
	unsigned int uiIdx = 0;
	while (pCurrent != NULL_PTR)
	{
		if (&Node == pCurrent)
		{
			*puiIdxRet = uiIdx;
			bFound = true;
			break;
		}
		pCurrent = pCurrent->m_pNextNode;
		uiIdx++;
	}

	if (!bFound)
	{
		eErr = eLIST_NODE_NOT_FOUND;
	}

	return eErr;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::GetValByIdx(T& RetVal,unsigned int uiIdx)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	
	ListNode<T>* pNode = GetNodeByIdx(uiIdx);
	if (pNode)
	{
		RetVal = pNode->m_Val;
	}
	else
	{
		eErr = eLIST_INVALID_INDEX;
	}

	return eErr;
}

template<class T>
ListNode<T>* LinkedList<T>::GetNodeByIdx(unsigned int uiIdx)
{
	if (uiIdx >= m_uiNodeCount) 
	{ 
		return NULL_PTR; 
	}

	ListNode<T> *pNode = this->m_pFirst;
	unsigned int ui = 0;
	while ((pNode != NULL_PTR) && (ui++ < uiIdx))
	{
		pNode = pNode->m_pNextNode;
	}
	return pNode;
}

template <class T>
E_LIST_ERROR_TYPE LinkedList<T>::GetIndex(T val, LinkedList<unsigned int>& idxList)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	if (m_uiNodeCount == 0) 
	{ 
		eErr = eLIST_EMPTY_LIST; 
	}

	if (eErr != eLIST_NO_ERR) 
	{
		return eErr; 
	}

	idxList.Clear();

	unsigned int uiIdx = 0;
	bool bFound = false;
	for (ListNode<T>* pCur = m_pFirst; pCur != NULL_PTR; pCur = pCur->m_pNextNode, uiIdx++)
	{
		if (pCur->m_Val == val)
		{
			idxList.Append(uiIdx);
			bFound = true;
		}
	}

	if (!bFound)
	{
		eErr = eLIST_NODE_NOT_FOUND;
	}

	return eErr;
}

template<class T>
unsigned int LinkedList<T>::GetCount(void)
{
	return this->m_uiNodeCount;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Clear(void)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	while (eErr != eLIST_EMPTY_LIST)
	{
		eErr = RemoveFirst();
	}
	return eErr;
}
