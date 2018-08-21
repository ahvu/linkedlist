//============================================================================
// Name        : Linked_List.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "linked_list.h"
#include "linked_list_debug.h"
#include "node.h"
#include "string.h"

/*
 * @brief: Macro definition
 */
#define UNLIMITTED_LIST_SIZE	(unsigned int)0

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
	LIST_DEBUG("List@[%p] created with capacity %d", this, m_uiCapacity);
}

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
LinkedList<T>::LinkedList(const LinkedList<T>& List)
{
	m_pFirst = NULL_PTR;
	m_pLast = NULL_PTR;
	m_uiNodeCount = 0;
	m_uiCapacity = List.m_uiCapacity;
	for(Node<T> *pNewNode = List.m_pFirst; pNewNode != NULL_PTR; pNewNode = pNewNode->GetNextNode())
	{
		Append(*pNewNode);
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
E_LIST_ERROR_TYPE LinkedList<T>::AddFirst (Node<T>& NewHead)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	if ((UNLIMITTED_LIST_SIZE == m_uiCapacity)||(m_uiNodeCount < m_uiCapacity))
	{
		Node<T> *pNewHead = new Node<T>(NewHead);
		if(0 == m_uiNodeCount)
		{
			m_pFirst = m_pLast = pNewHead;
		}
		else
		{
			pNewHead->SetNextNode(m_pFirst);
			m_pFirst = pNewHead;
		}
        ++m_uiNodeCount;
        LIST_DEBUG("Added new node [value]@[address] = [%d]@[%p]", m_pFirst->GetVal(), m_pFirst);
	}
	else
	{
		LIST_DEBUG("Error: Over capacity of list");
		eErr = eLIST_OVER_CAPACITY;
	}
	return eErr;
}

template <class T>
E_LIST_ERROR_TYPE LinkedList<T>::AddFirst (T NewHeadVal)
{
	Node<T> NewNode(NewHeadVal);
	return AddFirst(NewNode);
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::InsertList(LinkedList<T>& InList, unsigned int uiIdx)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	if ((uiIdx > 0) &&
		(uiIdx >= m_uiNodeCount))
	{
		eErr = eLIST_INVALID_INDEX;
	}
	
	if ((InList.GetCount() > (this->GetCapacity() - this->GetCount())) &&
		(UNLIMITTED_LIST_SIZE != this->GetCapacity()))
	{
		eErr = eLIST_OVER_CAPACITY;
	}

	if(InList.GetCount() == 0)
	{ 
		eErr = eLIST_EMPTY_LIST;
	}

	if (eErr != eLIST_NO_ERR)
	{
		return eErr;
	}

	Node<T>* pNodeInList = InList.m_pFirst;
	if (m_uiNodeCount == 0)
	{
		while ((pNodeInList != NULL_PTR) && (eErr == eLIST_NO_ERR))
		{
			eErr = Append(*pNodeInList);
			pNodeInList = pNodeInList->GetNextNode();
		}
	}
	else
	{
		while ((pNodeInList != NULL_PTR) && (eErr == eLIST_NO_ERR))
		{
			eErr = Insert(*pNodeInList,uiIdx++);
			pNodeInList = pNodeInList->GetNextNode();
		}
	}

	return eErr;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Insert(T NodeVal, unsigned int uiIdx)
{
	Node<T> NewNode(NodeVal);
	return Insert(NewNode, uiIdx);
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Insert(Node<T>& NewNode, unsigned int uiIdx)
{
	if (uiIdx == 0)
	{
		return AddFirst(NewNode);
	}

	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	if (m_uiNodeCount <= uiIdx)
	{
		LIST_DEBUG("Error: Invalid Index ");
		eErr = eLIST_INVALID_INDEX;
	}

	if ((m_uiCapacity <= m_uiNodeCount) && (m_uiCapacity != UNLIMITTED_LIST_SIZE))
	{
		eErr = eLIST_OVER_CAPACITY;
	}

	if (eErr != eLIST_NO_ERR)
	{
		return eErr;
	}

	Node<T>* pPrev = GetNodeByIdx(uiIdx - 1);
	Node<T>* pCur = GetNodeByIdx(uiIdx);

	Node<T> *pNewHead = new Node<T>(NewNode);
	pPrev->SetNextNode(pNewHead);
	pNewHead->SetNextNode(pCur);
	m_uiNodeCount++;

	return eErr;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Append (Node<T>& NewLast)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	if((m_uiCapacity <= m_uiNodeCount) && (UNLIMITTED_LIST_SIZE != m_uiCapacity))
	{
		LIST_DEBUG("Error: Over capacity list");
		eErr = eLIST_OVER_CAPACITY;
	}

	if (eErr != eLIST_NO_ERR)
	{
		return eErr;
	}

	Node<T> *pNode = new Node<T>(NewLast);
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
int LinkedList<T>::compare(T val1, T val2)
{
	return memcmp(&val1, &val2, sizeof(T));
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Append (T NewLastVal)
{
	Node<T> NewNode(NewLastVal);
	return Append(NewNode);
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

	Node<T>* pNode = this->m_pFirst;

	//std::cout << "List@[" << this << "]" << std::endl;
	//std::cout << "|idx	|value	|Address" << std::endl;
	unsigned int uiIdx = 0;
	while (pNode != NULL_PTR)
	{

		//std::cout << "|" << uiIdx++ << "	|" << pNode->GetVal() << "	|" << pNode << std::endl;
		pNode = pNode->GetNextNode();
	}
	return eErr;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::Remove(T Val)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	if (0 == m_uiNodeCount)
	{
		LIST_DEBUG("Error: Empty list");
		eErr = eLIST_EMPTY_LIST;
	}

	if (eErr != eLIST_NO_ERR)
	{
		return eErr;
	}

	Node<T>* pCurrent = this->m_pFirst;
	Node<T>* pNext = pCurrent->GetNextNode();

	bool found = false;
	if(compare(Val,pCurrent->GetVal()) == 0)
	{
		this->m_pFirst = pNext;
		delete pCurrent;
		found = true;
	}
	else
	{
		while (pNext != NULL_PTR)
		{
			if (compare(pNext->GetVal(),Val) == 0)
			{
				pCurrent->SetNextNode(pNext->GetNextNode());
				delete pNext;
				found = true;
				break;
			}
			pCurrent = pNext;
			pNext = pNext->GetNextNode();
		}
	}

	if (found)
	{
		LIST_DEBUG("Info: Node with given value deleted");
		this->m_uiNodeCount--;
	}
	else
	{
		LIST_DEBUG("Error: Node with given value not found");
		eErr = eLIST_NODE_NOT_FOUND;
	}
	return eErr;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::RemoveFirst()
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	if (m_uiNodeCount == 0)
	{
		LIST_DEBUG("Error: Empty list");
		eErr = eLIST_EMPTY_LIST;
	}


	if (eErr != eLIST_NO_ERR)
	{
		return eErr;
	}

	Node<T>* pCurrent = m_pFirst;
	m_pFirst = pCurrent->GetNextNode();
	delete pCurrent;
	m_uiNodeCount--;
	LIST_DEBUG("Info: Deleted first node");
	if (m_uiNodeCount <= 1)
		m_pLast = m_pFirst;

	return eErr;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::RemoveLast()
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	if (m_uiNodeCount == 0)
	{
		LIST_DEBUG("Error: Empty list");
		eErr = eLIST_EMPTY_LIST;
	}
	if (eErr != eLIST_NO_ERR)
	{
		return eErr;
	}
	
	delete m_pLast;
	m_uiNodeCount--;
	LIST_DEBUG("Info: Last node deleted");
	if (m_uiNodeCount == 0)
	{
		m_pLast = NULL_PTR;
	}
	else
	{
		Node<T>* pPrev = GetNodeByIdx(m_uiNodeCount - 1);
		pPrev->SetNextNode(NULL_PTR);
		m_pLast = pPrev;
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

	if (m_uiNodeCount <= uiIndex)
	{
		LIST_DEBUG("Error: Invalid index");
		eErr = eLIST_INVALID_INDEX;
	}
	if (m_uiNodeCount == 0)
	{
		LIST_DEBUG("Error: Empty list");
		eErr = eLIST_EMPTY_LIST;
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
E_LIST_ERROR_TYPE LinkedList<T>::GetIndex(T val, unsigned int& ruiIdxRet)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	if (m_uiNodeCount == 0)
	{
		LIST_DEBUG("Error: Empty list");
		eErr = eLIST_EMPTY_LIST;
	}

	if (eErr != eLIST_NO_ERR)
	{
		return eErr;
	}

	Node<T>* pCurrent = this->m_pFirst;
	bool bFound = false;
	unsigned int uiIdx = 0;
	while (pCurrent != NULL_PTR)
	{
		if (compare(val, pCurrent->GetVal()) == 0)
		{
			ruiIdxRet = uiIdx;
			bFound = true;
			LIST_DEBUG("Info: Found index value: %d",uiIdx);
			break;
		}
		pCurrent = pCurrent->GetNextNode();
		uiIdx++;
	}

	if (!bFound)
	{
		LIST_DEBUG("Error: Node not found with given value");
		eErr = eLIST_NODE_NOT_FOUND;
	}
	return eErr;
}

template<class T>
E_LIST_ERROR_TYPE LinkedList<T>::GetValByIdx(T& RetVal,unsigned int uiIdx)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	
	Node<T>* pNode = GetNodeByIdx(uiIdx);
	if (pNode)
	{
		RetVal = pNode->GetVal();
	}
	else
	{
		eErr = eLIST_INVALID_INDEX;
	}

	return eErr;
}

template<class T>
T& LinkedList<T>::operator[](const unsigned int uiIdx)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;
	Node<T>* pNode = GetNodeByIdx(uiIdx);
	if (pNode)
	{
		return pNode->GetVal();
	}
	else
	{
		throw (0);
	}
}

template<class T>
Node<T>* LinkedList<T>::GetNodeByIdx(unsigned int uiIdx)
{
	if (uiIdx >= m_uiNodeCount)
	{
		LIST_DEBUG("Error: Invalid index");
		return NULL_PTR;
	}

	Node<T> *pNode = this->m_pFirst;
	unsigned int uiIdxCount = 0;
	while ((pNode != NULL_PTR) && (uiIdxCount < uiIdx))
	{
		pNode = pNode->GetNextNode();
		++uiIdxCount;
	}
	return pNode;
}

template <class T>
E_LIST_ERROR_TYPE LinkedList<T>::GetIndexList(T val, LinkedList<unsigned int>& idxList)
{
	E_LIST_ERROR_TYPE eErr = eLIST_NO_ERR;

	if (m_uiNodeCount == 0) 
	{ 
		LIST_DEBUG("Error: Empty list");
		eErr = eLIST_EMPTY_LIST; 
	}

	if (eErr != eLIST_NO_ERR) 
	{
		return eErr; 
	}

	idxList.Clear();

	unsigned int uiIdx = 0;
	bool bFound = false;
	for (Node<T>* pCur = m_pFirst; pCur != NULL_PTR; pCur = pCur->GetNextNode(), ++uiIdx)
	{
		if (compare(pCur->GetVal(), val) == 0)
		{
			idxList.Append(uiIdx);
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
unsigned int LinkedList<T>::GetCount(void)
{
	LIST_DEBUG("Number of elements in list: %d",m_uiNodeCount);
	return this->m_uiNodeCount;
}

template<class T>
unsigned int LinkedList<T>::GetCapacity(void)
{
	return m_uiCapacity;
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
