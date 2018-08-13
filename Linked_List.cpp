//============================================================================
// Name        : Linked_List.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Linked_List.h"
#include <iostream>

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
	std::cout << "New node created with value: " << m_Val << std::endl;
}

template<class T>
ListNode<T>::ListNode(ListNode<T> &node)
{
	m_pNextNode = NULL_PTR;
	m_Val = node.m_Val;
        m_pNextNode = node.m_pNextNode;
	std::cout << "New node created with value: " << m_Val << std::endl;
}

template<class T>
ListNode<T>::~ListNode()
{
	std::cout << "Node at " << this << " destroyed " << std::endl;
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
	    std::cout << "Added new node [value][address] = [" << m_pFirst->m_Val <<"][" << m_pFirst << "] to List["<< this << "]" << std::endl;
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
	    std::cout << "Added new node [value][address] = [" << m_pFirst->m_Val <<"][" << m_pFirst << "] to List["<< this << "]" << std::endl;
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
	if(m_uiCapacity <= m_uiNodeCount)
	{
		err = eLIST_OVER_CAPACITY;
	}

	if(err != eLIST_NO_ERR) return err;

	ListNode<unsigned int> *node = new ListNode<T>(new_LastVal);
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

int main() 
{
	ListNode<unsigned int> *n1 = new ListNode<unsigned int>(1);
	ListNode<unsigned int> *n2 = new ListNode<unsigned int>(2);
	ListNode<unsigned int> *n3 = new ListNode<unsigned int>(3);
	ListNode<unsigned int> *n4 = new ListNode<unsigned int>(4);

	LinkedList<unsigned int> *a = new LinkedList<unsigned int>(10);
	a->AddLast(*n1);
	a->AddLast(*n2);
	a->AddLast(99);
    a->AddFirst(*n4);
    a->AddFirst(*n3);
    a->AddFirst(100);

	LinkedList<unsigned int> *b = new LinkedList<unsigned int>(*a,20);

    delete n1;
    delete n2;
    delete n3;
    delete n4;

	delete a;
    delete b;
    //getchar();
	return 0;
}
