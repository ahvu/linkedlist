//============================================================================
// Name        : linked_list.cpp
// Author      : trdnguyen, avu
// Version     :
// Copyright   : Your copyright notice
// Description : A linked list template library
//============================================================================
#include "linked_list.h"
#include <string.h>
#include "linked_list_debug.h"

// TODO: unify Append,AddFirst, Insert functions
// TODO: remove redundant boundary check 

#ifndef LINKED_LIST_DEBUG
#define LIST_DEBUG(M, ...)
#define LIST_PRINT(M,...)
#else
#define LIST_DEBUG(M, ...) printf("Function:%s\r\n-D-   " M "\r\n", __func__, ##__VA_ARGS__)
#define LIST_PRINT(M,...) printf(M"\r\n",##__VA_ARGS__)
#endif
/*
 * @brief: Macro definition
 */
#define UNLIMITTED_LIST_SIZE	(unsigned int)0

/*
 * @brief: LinkedList member definition
 */
/*******************************************************
 * Subclass Node
 *******************************************************/
template <class T>
template <class U>
LinkedList<T>::Node<U>::Node()
{
	m_pNextNode = NULL_PTR;
}
template <class T>
template <class U>
LinkedList<T>::Node<U>::Node(U NodeVal)
{
	m_pNextNode = NULL_PTR;
	m_Val = NodeVal;
}
template <class T>
template <class U>
LinkedList<T>::Node<U>::Node(Node &rNode)
{
	m_pNextNode = NULL_PTR;
	m_Val = rNode.m_Val;
}
template <class T>
template <class U>
LinkedList<T>::Node<U>::~Node(){}

template <class T>
template <class U>
U& LinkedList<T>::Node<U>::GetVal(void)
{
    return m_Val;
}
template <class T>
template <class U>
void LinkedList<T>::Node<U>::SetVal(U NewVal)
{
    m_Val = NewVal;
}
template <class T>
template <class U>
LinkedList<T>::Node<U>* LinkedList<T>::Node<U>::GetNextNode(void)
{
    return m_pNextNode;
}
template <class T>
template <class U>
void LinkedList<T>::Node<U>::SetNextNode(Node* pNode)
{
    m_pNextNode = pNode;
}

/******************************************************
 * Public member functions
 ******************************************************/
template<class T>
LinkedList<T>::LinkedList(unsigned int uiCapacity)
{
	m_pFirst = NULL_PTR;
	m_pLast = NULL_PTR;
	m_uiNodeCount = 0;
	m_uiCapacity = uiCapacity;
	LIST_DEBUG("List@[%p] created with capacity %d", this, m_uiCapacity);
}
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& List)
{
	m_pFirst = NULL_PTR;
	m_pLast = NULL_PTR;
	m_uiNodeCount = 0;
	m_uiCapacity = List.m_uiCapacity;
	for(Node<T> *pNode = List.m_pFirst; pNode != NULL_PTR; pNode = pNode->GetNextNode())
	{
		Append(*pNode);
	}
	LIST_DEBUG("List@[%p] created with capacity %d", this, m_uiCapacity);
}
template<class T>
LinkedList<T>::~LinkedList()
{
	Node<T> *pFirst = m_pFirst;
	while(pFirst != NULL_PTR)
	{
		Node<T> *pNextNode = pFirst->GetNextNode();
		delete pFirst;
		pFirst = pNextNode;
	}
	m_pFirst = m_pLast = NULL_PTR;
	m_uiNodeCount = 0;
	LIST_DEBUG("List@[%p] destroyed", this);
}




template <class T>
E_LIST_ERROR_TYPE LinkedList<T>::AddFirst (T& NewHeadVal)
{
	Node<T> NewNode(NewHeadVal);
	return AddFirst(NewNode);
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Insert(T& NodeVal, unsigned int uiIdx)
{
	Node<T> NewNode(NodeVal);
	return Insert(NewNode, uiIdx);
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Insert(LinkedList<T>& InList, unsigned int uiIdx)
{
    if ((uiIdx > 0) &&
        (uiIdx > m_uiNodeCount))
    {
        return eLIST_INVALID_INDEX;
    }

    if ((InList.GetCount() > (this->GetCapacity() - this->GetCount())) &&
        (UNLIMITTED_LIST_SIZE != this->GetCapacity()))
    {
        return eLIST_OVER_CAPACITY;
    }

    if (InList.GetCount() == 0)
    {
		return eLIST_EMPTY_LIST;
    }

    E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

    Node<T>* pNodeInList = InList.m_pFirst;
    while ((pNodeInList != NULL_PTR) && (eErr == eLIST_NO_ERR))
    {
        eErr = Insert(*pNodeInList, uiIdx++);
        pNodeInList = pNodeInList->GetNextNode();
    }
    return eErr;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Append (T& NewLastVal)
{
	Node<T> NewNode(NewLastVal);
	return Append(NewNode);
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Append(LinkedList<T>& InList)
{
	return Insert(InList, m_uiNodeCount);
}

template<class T>
unsigned int LinkedList<T>::GetCount(void)
{
	LIST_DEBUG("Number of elements in list: %d",m_uiNodeCount);
    return m_uiNodeCount;
}

template<class T>
unsigned int LinkedList<T>::GetCapacity(void)
{
	return m_uiCapacity;
}



template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::RemoveFirst()
{
	if (m_uiNodeCount == 0)
	{
		LIST_DEBUG("Error: Empty list");
		return eLIST_EMPTY_LIST;
	}

	Node<T>* pCurrent = m_pFirst;
	m_pFirst = pCurrent->GetNextNode();
	delete pCurrent;
	m_uiNodeCount--;
	LIST_DEBUG("Info: Deleted first node");
	if (m_uiNodeCount <= 1)
    {
		m_pLast = m_pFirst;
    }

    return eLIST_NO_ERR;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::RemoveLast()
{

	if (m_uiNodeCount == 0)
	{
		LIST_DEBUG("Error: Empty list");
		return eLIST_EMPTY_LIST;
	}
	
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	delete m_pLast;
	m_uiNodeCount--;
	LIST_DEBUG("Info: Last node deleted");
	if(m_uiNodeCount >= 1)
	{
		Node<T>* pPrev = GetNodeByIdx(m_uiNodeCount - 1);
		pPrev->SetNextNode(NULL_PTR);
		m_pLast = pPrev;
	}
	else
	{
		m_pLast = NULL_PTR;	
	}
	m_pFirst = (m_uiNodeCount <= 1) ? m_pLast : m_pFirst;

	return eErr;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Remove(T Val)
{
	if (0 == m_uiNodeCount)
	{
		return  eLIST_EMPTY_LIST;
	}

	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

    if (Compare(Val, m_pFirst->GetVal()) == 0)
	{
        return RemoveFirst();
	}

	Node<T>* pCurrent = m_pFirst;
	Node<T>* pNext = pCurrent->GetNextNode();
	while (pNext != NULL_PTR)
	{
        if (Compare(pNext->GetVal(), Val) == 0)
		{
			pCurrent->SetNextNode(pNext->GetNextNode());
			delete pNext;
			break;
		}
		pCurrent = pNext;
		pNext = pNext->GetNextNode();
	}

    if (pNext == NULL_PTR)
	{
		LIST_DEBUG("Error: Node with given value not found");
		eErr = eLIST_NODE_NOT_FOUND;
	}
	else
	{
		LIST_DEBUG("Info: Node with given value deleted");
		m_uiNodeCount--;
	}

	return eErr;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::RemoveByIdx(unsigned int uiIndex)
{
	if (m_uiNodeCount <= uiIndex)
	{
		LIST_DEBUG("Error: Invalid index");
		return eLIST_INVALID_INDEX;
	}
	if (m_uiNodeCount == 0)
	{
		LIST_DEBUG("Error: Empty list");
		return eLIST_EMPTY_LIST;
	}

	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

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
		Node<T>* pCur = GetNodeByIdx(uiIndex);
		Node<T>* pPrev = GetNodeByIdx(uiIndex - 1);
		pPrev->SetNextNode(pCur->GetNextNode());
		delete pCur;
		m_uiNodeCount--;
		LIST_DEBUG("Info: Node with given index removed");
	}

	return eErr;
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

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::GetIndex(const T& NodeVal, unsigned int &ruiRetIdx)
{
	if (m_uiNodeCount == 0)
	{
		LIST_DEBUG("Error: Empty list");
		return eLIST_EMPTY_LIST;
	}

	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	Node<T>* pCurrent = this->m_pFirst;
	unsigned int uiIdx = 0;
	while (pCurrent != NULL_PTR)
	{
        if (Compare(NodeVal, pCurrent->GetVal()) == 0)
		{
			ruiRetIdx = uiIdx;
			LIST_DEBUG("Info: Found index value: %d",uiIdx);
			break;
		}
		pCurrent = pCurrent->GetNextNode();
		uiIdx++;
	}

	if (pCurrent == NULL_PTR)
	{
		LIST_DEBUG("Error: Node not found with given value");
		eErr = eLIST_NODE_NOT_FOUND;
	}
	return eErr;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::GetValByIdx(T& rRetVal, unsigned int uiIdx)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	
	Node<T>* pNode = GetNodeByIdx(uiIdx);
	if (pNode)
	{
        rRetVal = pNode->GetVal();
	}
	else
	{
		eErr = eLIST_INVALID_INDEX;
	}

	return eErr;
}

template <class T>
E_LIST_ERROR_TYPE LinkedList<T>::GetIndexList(const T& NodeVal, LinkedList<unsigned int>& ruiRetIdxList)
{

	if (m_uiNodeCount == 0) 
	{ 
		LIST_DEBUG("Error: Empty list");
		return eLIST_EMPTY_LIST; 
	}

	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
    ruiRetIdxList.Clear();

	unsigned int uiIdx = 0;
	bool bFound = false;
	for (Node<T>* pCur = m_pFirst; pCur != NULL_PTR; pCur = pCur->GetNextNode(), ++uiIdx)
	{
        if (Compare(pCur->GetVal(), NodeVal) == 0)
		{
            ruiRetIdxList.Append(uiIdx);
			bFound = true;
		}
	}

	if (!bFound)
	{
		LIST_DEBUG("Error: Node not found");
		eErr = eLIST_NODE_NOT_FOUND;
	}

	return eErr;
}



template<class T>
T& LinkedList<T>::operator[](unsigned int uiIdx)
{
	Node<T>* pNode = GetNodeByIdx(uiIdx);
	if (pNode)
	{
		return pNode->GetVal();
	}
	else
	{
		LL_AssertionHandler(LL_ASSERT_EXCEPTION);
	}
}


/******************************************************
 * Private member functions
 ******************************************************/
template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::TraverseList()
{
    E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
    Node<T>* pNode = this->m_pFirst;

    LIST_PRINT("List@[%p]", this);
    LIST_PRINT("|idx    |value  |Address");
    unsigned int uiIdx = 0;
    while (pNode != NULL_PTR)
    {
        LIST_PRINT("|%d |%d |%p", uiIdx, pNode->GetVal(), pNode);
        pNode = pNode->GetNextNode();
        uiIdx++;
    }
    return eErr;
}
template<class T>
LinkedList<T>::Node<T>* LinkedList<T>::GetNodeByIdx(unsigned int uiIdx)
{
	if (uiIdx >= m_uiNodeCount)
	{
		LIST_DEBUG("Error: Invalid index");
		return NULL_PTR;
	}

	Node<T> *pNode = m_pFirst;
	unsigned int uiIdxCount = 0;
	while ((pNode != NULL_PTR) && (uiIdxCount < uiIdx))
	{
		pNode = pNode->GetNextNode();
		++uiIdxCount;
	}
	return pNode;
}
template <class T>
E_LIST_ERROR_TYPE LinkedList<T>::AddFirst(Node<T>& rNewHead)
{
	if ((UNLIMITTED_LIST_SIZE != m_uiCapacity)&& (m_uiNodeCount >= m_uiCapacity))
	{
		return eLIST_OVER_CAPACITY;
	}

	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
		
    Node<T> *pNewHead = new Node<T>(rNewHead);
	if(pNewHead == NULL_PTR)
	{
		LL_AssertionHandler(LL_ASSERT_OUTOFMEMORY);
	}

	if(0 == m_uiNodeCount)
	{
		m_pFirst = m_pLast = pNewHead;
	}
	else
	{
		pNewHead->SetNextNode(m_pFirst);
		m_pFirst = pNewHead;
	}

	m_uiNodeCount++;
    LIST_DEBUG("Added new node [value]@[address] = [%d]@[%p]", m_pFirst->GetVal(), m_pFirst);

	return eErr;
}
template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Append(Node<T>& rNewLast)
{
	if((m_uiCapacity <= m_uiNodeCount) && (UNLIMITTED_LIST_SIZE != m_uiCapacity))
	{
		LIST_DEBUG("Error: Over capacity list");
		return eLIST_OVER_CAPACITY;
	}

	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

    Node<T> *pNode = new Node<T>(rNewLast);
	if(pNode == NULL_PTR)
	{
		return eLIST_OUT_OF_MEMORY;
	}

	if(0 == m_uiNodeCount)
	{
		m_pFirst = m_pLast = pNode;
	}
	else
	{
		m_pLast->SetNextNode(pNode);
		m_pLast = pNode;
	}

	m_uiNodeCount++;
	LIST_DEBUG("Added new node [value][address] = [%d]@[%p] to List@[%p]", m_pLast->GetVal(), m_pLast, this);

	return eErr;
}
template<class T>
int LinkedList<T>::Compare(T Val1, T Val2)
{
    return memcmp(&Val1, &Val2, sizeof(T));
}

/******************************************************
 * Protected member functions
 ******************************************************/

template<class T>
LinkedList<T>::LinkedList(Node<T>& rHead, unsigned int uiCapacity)
{
	m_pFirst = NULL_PTR;
	m_pLast = NULL_PTR;
	m_uiNodeCount = 0;
	m_uiCapacity = uiCapacity;
	Append(rHead);
	LIST_DEBUG("List@[%p] created with capacity %d", this, m_uiCapacity);
}
template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Insert(Node<T>& rNewNode, unsigned int uiIdx)
{
	if (m_uiNodeCount == uiIdx)
	{
		return Append(rNewNode);
	}

	if (m_uiNodeCount < uiIdx)
	{
		return eLIST_INVALID_INDEX;
	}

	if ((m_uiCapacity <= m_uiNodeCount) && (m_uiCapacity != UNLIMITTED_LIST_SIZE))
	{
        return eLIST_OVER_CAPACITY;
	}

    if (uiIdx == 0)
	{
        return AddFirst(rNewNode);
	}

    Node<T> *pNode = new Node<T>(rNewNode);
	if(pNode == NULL_PTR)
	{
		LL_AssertionHandler(LL_ASSERT_OUTOFMEMORY);
	}

	Node<T>* pPrev = GetNodeByIdx(uiIdx - 1);
	Node<T>* pCur = GetNodeByIdx(uiIdx);
    pPrev->SetNextNode(pNode);
    pNode->SetNextNode(pCur);
	m_uiNodeCount++;

	return eLIST_NO_ERR;
}
