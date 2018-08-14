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

using namespace std;
#ifndef NULL_PTR
#define NULL_PTR 0
#endif
#define UNLIMITTED_LIST_SIZE	(unsigned int)0

template<class T>
ListNode<T>::ListNode()
{
	m_pNextNode = NULL_PTR;
	std::cout << "New node created with no value" << std::endl;
}

template<class T>
ListNode<T>::ListNode(T val)
{
	m_pNextNode = NULL_PTR;
	m_Val = val;
	std::cout << "New node created with [value]@[address]: [" << m_Val << "]@" << "[" << this << "]" << std::endl;
}

template<class T>
ListNode<T>::ListNode(ListNode<T> &node)
{
	m_pNextNode = NULL_PTR;
	m_Val = node.m_Val;
    m_pNextNode = node.m_pNextNode;
	std::cout << "New node created with [value]@[address]: [" << m_Val << "]@" << "[" << this << "]" << std::endl;
}

template<class T>
ListNode<T>::~ListNode()
{
	std::cout << "Node [" << this->m_Val << "]@[" << this << "] destroyed " << std::endl;
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


//LinkedList class definition:
template <class T>
E_LIST_ERROR_TYPE LinkedList<T>::AddFirst (ListNode<T>& NewHead)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	if ((UNLIMITTED_LIST_SIZE == m_uiCapacity)||(m_uiNodeCount < m_uiCapacity))
	{
		ListNode<T> *pNewHead = new ListNode<T>(NewHead);
		if((NULL_PTR == m_pFirst) && (NULL_PTR == m_pLast))
		{
			m_pFirst = m_pLast = pNewHead;
		}
		else
		{
			pNewHead->m_pNextNode = m_pFirst;
			m_pFirst = pNewHead;
		}
        ++m_uiNodeCount;
	    std::cout << "Added new node [value]@[address] = [" << m_pFirst->m_Val <<"]@[" << m_pFirst << "] to List["<< this << "]" << std::endl;
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
		if((NULL_PTR == m_pFirst) && (NULL_PTR == m_pLast))
		{
			m_pFirst = m_pLast = pNewHead;
		}
		else
		{
			pNewHead->m_pNextNode = m_pFirst;
			m_pFirst = pNewHead;
		}
		++m_uiNodeCount;
	    std::cout << "Added new node [value]@[address] = [" << m_pFirst->m_Val <<"]@[" << m_pFirst << "] to List["<< this << "]" << std::endl;
	}
	else
	{
		eErr = eLIST_OVER_CAPACITY;
	}
	return eErr;
}

template<class T>
LinkedList<T>::LinkedList(unsigned int uiCapacity) : m_uiCapacity(uiCapacity)
{
	std::cout << "Creating List[" << this << "]" << std::endl;
	//std::cout << __FUNCTION__ << std::endl;
	m_pFirst = NULL_PTR;
	m_pLast = NULL_PTR;
	m_uiNodeCount = 0;
	std::cout << "List created with capacity: " << m_uiCapacity << std::endl;
}

template<class T>
LinkedList<T>::LinkedList(LinkedList& List, unsigned int uiCapacity)
{
	std::cout << "Creating List[" << this << "]" << std::endl;
	m_pFirst = NULL_PTR;
	m_pLast = NULL_PTR;
	m_uiNodeCount = 0;
	m_uiCapacity = (uiCapacity > List.m_uiCapacity) ? uiCapacity: List.m_uiCapacity;
	for(ListNode<T> *node = List.m_pFirst; node != NULL_PTR; node = node->m_pNextNode)
	{
		this->AddLast(*node);
	}
	std::cout << "List created with capacity: " << m_uiCapacity << std::endl;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	//std::cout << __FUNCTION__ << std::endl;
	ListNode<T> *first = m_pFirst;
	while(first != NULL)
	{
		ListNode<T> *next = first->m_pNextNode;
		delete first;
		first = next;
	}
	std::cout << "List@[" << this << "] destroyed" << std::endl;
}

template<class T>
ListNode<T>& LinkedList<T>::FindLast(T Val)
{
	unsigned int idx = 0;
	ListNode<T>* pNode = this->m_pFirst;
	ListNode<T>* pRet = pNode;
	while (pNode != NULL)
	{
		if (pNode->m_Val == Val)
		{
			pRet = pNode;
		}
		pNode = pNode->m_pNextNode;
	}
	std::cout << "Node with value [" << Val << "] found at [" << pRet << "]" << std::endl;
	return *pRet;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::AddBefore(T NodeVal, ListNode<T>& BaseNode)
{
	ListNode<T> node(NodeVal);
	return AddBefore(node, BaseNode);
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::AddBefore(ListNode<T>& NewNode, ListNode<T>& BaseNode)
{
	E_LIST_ERROR_TYPE err = eLIST_NO_ERR;
	unsigned int idx = -1;
	this->GetIndex(BaseNode, &idx);

	if (idx == -1)
	{
		err = eLIST_NODE_NOT_FOUND;
	}

	if (err != eLIST_NO_ERR) return err;

	if (idx == 0)
	{
		err = AddFirst(NewNode);
	}
	else
	{
		ListNode<T>& Prev = GetNode(idx - 1);
		err = AddBetween(Prev, BaseNode,NewNode);
	}

	return err;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::AddBetween(ListNode<T>& Left, ListNode<T>& Right, ListNode<T>& NewNode)
{
	E_LIST_ERROR_TYPE err = eLIST_NO_ERR;

	if (Left.m_pNextNode != &Right)
		err = eLIST_INVALID_NODE;

	if (err != eLIST_NO_ERR) return err;

	ListNode<T> *pNewHead = new ListNode<T>(NewNode);
	Left.m_pNextNode = pNewHead;
	pNewHead->m_pNextNode = &Right;
	m_uiCapacity++;

	return err;
} 

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::AddLast (ListNode<T>& NewLast)
{
	//std::cout << __FUNCTION__ << std::endl;
	E_LIST_ERROR_TYPE err = eLIST_NO_ERR;
	if(m_uiCapacity <= m_uiNodeCount)
	{
		err = eLIST_OVER_CAPACITY;
	}

	if(err != eLIST_NO_ERR) return err;

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
	std::cout << "Added new node [value][address] = [" << m_pLast->m_Val <<"][" << m_pLast << "] to List["<< this << "]" << std::endl;

	return err;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::AddLast (T new_LastVal)
{
	//std::cout << __FUNCTION__ << std::endl;
	E_LIST_ERROR_TYPE err = eLIST_NO_ERR;
	if (m_uiCapacity <= m_uiNodeCount)
	{
		err = eLIST_OVER_CAPACITY;
	}

	if (err != eLIST_NO_ERR) return err;

	ListNode<unsigned int> *node = new ListNode<T>(new_LastVal);
	if (NULL_PTR == m_pFirst)
	{
		m_pFirst = m_pLast = node;
	}
	else
	{
		m_pLast->m_pNextNode = node;
		m_pLast = node;
	}
	m_uiNodeCount++;
	std::cout << "Added new node [value][address] = [" << m_pLast->m_Val << "][" << m_pLast << "] to List[" << this << "]" << std::endl;

	return err;
}


template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::TraverseList()
{
	E_LIST_ERROR_TYPE err = eLIST_NO_ERR;

	if (this->m_pFirst == NULL_PTR)
		err = eLIST_EMPTY_LIST;

	if (err != eLIST_NO_ERR) return err;

	ListNode<T>* pNode = this->m_pFirst;

	std::cout << "List@[" << this << "]" << std::endl;
	std::cout << "|idx	|value	|Address" << std::endl;
	int idx = 0;
	while (pNode != NULL_PTR)
	{
		std::cout << "|" << idx++ << "	|" << pNode->m_Val << "	|" << pNode << std::endl;
		pNode = pNode->m_pNextNode;
	}
	return err;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Remove(T val)
{
	E_LIST_ERROR_TYPE err = eLIST_NO_ERR;

	if (this->m_pFirst == NULL_PTR)
		err = eLIST_EMPTY_LIST;

	if (err != eLIST_NO_ERR) return err;

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
			pNext = pCurrent->m_pNextNode;
		}
	}

	if (found)
	{
		this->m_uiNodeCount--;
	}
	else
	{
		err = eLIST_NODE_NOT_FOUND;
	}

	return err;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::RemoveFirst()
{
	E_LIST_ERROR_TYPE err = eLIST_NO_ERR;

	if (this->m_pFirst == NULL_PTR)
		err = eLIST_EMPTY_LIST;

	if (err != eLIST_NO_ERR) return err;

	ListNode<T>* pCurrent = this->m_pFirst;
	this->m_pFirst = pCurrent->m_pNextNode;
	delete pCurrent;

	return err;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::RemoveLast()
{
	E_LIST_ERROR_TYPE err = eLIST_NO_ERR;

	if (this->m_pFirst == NULL_PTR)
		err = eLIST_EMPTY_LIST;

	if (err != eLIST_NO_ERR) return err;

	ListNode<T>* pCurrent = this->m_pFirst;
	this->m_pFirst = pCurrent->m_pNextNode;
	delete pCurrent;

	return err;
}
template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::GetIndex(T val, unsigned int *puiIdxRet)
{
	E_LIST_ERROR_TYPE err = eLIST_NO_ERR;

	if (this->m_pFirst == NULL_PTR)
	err = eLIST_EMPTY_LIST;

	if (err != eLIST_NO_ERR) return err;

	ListNode<T>* pCurrent = this->m_pFirst;
	bool found = false;
	unsigned int idx = 0;
	while (pCurrent != NULL)
	{
		if (val == pCurrent->m_Val)
		{
			*puiIdxRet = idx;
			found = true;
			break;
		}
		pCurrent = pCurrent->m_pNextNode;
		idx++;
	}

	if (!found) err = eLIST_NODE_NOT_FOUND;
	return err;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::GetIndex(ListNode<T>& Node, unsigned int *puiIdxRet)
{
	E_LIST_ERROR_TYPE err = eLIST_NO_ERR;

	if (this->m_pFirst == NULL_PTR)
		err = eLIST_EMPTY_LIST;

	if (err != eLIST_NO_ERR) return err;
	ListNode<T>* pCurrent = this->m_pFirst;
	bool found = false;
	unsigned int idx = 0;
	while (pCurrent != NULL)
	{
		if (&Node == pCurrent)
		{
			*puiIdxRet = idx;
			found = true;
			break;
		}
		pCurrent = pCurrent->m_pNextNode;
		idx++;
	}

	if (!found) err = eLIST_NODE_NOT_FOUND;
	return err;
}

template<class T>
ListNode<T>& LinkedList<T>::GetNode(unsigned int idx)
{
	ListNode<T> *pNode = this->m_pFirst;
	int i = 0;
	while ((pNode != NULL_PTR) && (i++ < idx))
	{
		pNode = pNode->m_pNextNode;
	}
	return *pNode;
}

template<class T>
unsigned int LinkedList<T>::GetCount(void)
{
	return this->m_uiNodeCount;
}
