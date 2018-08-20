/*
 * Linked_List.h
 *
 *  Created on: Aug 9, 2018
 *      Author: trdnguyen
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "node.h"

template <class T> class Node;
template <class T> class LinkedList;

typedef enum _E_LIST_ERROR_TYPE
{
	eLIST_NO_ERR = 0,
	eLIST_EMPTY_LIST,
	eLIST_OVER_CAPACITY,
	eLIST_INVALID_INDEX,
	eLIST_OUT_OF_MEMORY,
	eLIST_INVALID_NODE,
	eLIST_NODE_NOT_FOUND,
	eLIST_MAX_ERR
}E_LIST_ERROR_TYPE;


template <class T>
class LinkedList
{
protected:
	unsigned int m_uiNodeCount;
	unsigned int m_uiCapacity;
	Node<T> *m_pFirst;
	Node<T> *m_pLast ;
	E_LIST_ERROR_TYPE Insert (Node<T>& NewNode, unsigned int uiIdx);
public:
	LinkedList(unsigned int uiCapacity = 0);
	LinkedList(Node<T> &Head, unsigned int uiCapacity = 0);
	LinkedList(const LinkedList<T>& List);
	~LinkedList();
	unsigned int GetCount(void);
	unsigned int GetCapacity(void);
	E_LIST_ERROR_TYPE GetValByIdx(T& RetVal,unsigned int uiIdx);
	T& operator[](unsigned int uiIdx);
	E_LIST_ERROR_TYPE GetIndex(T val, unsigned int *puiIdxRet);
	E_LIST_ERROR_TYPE AddFirst (T NewHeadVal); 
	E_LIST_ERROR_TYPE Insert (T NodeVal, unsigned int uiIdx);
	E_LIST_ERROR_TYPE Append (T NewLastVal);
	E_LIST_ERROR_TYPE Remove (T val);
	E_LIST_ERROR_TYPE RemoveFirst(void);
	E_LIST_ERROR_TYPE RemoveLast(void);
	E_LIST_ERROR_TYPE RemoveByIdx (unsigned int uiIndex);
	E_LIST_ERROR_TYPE Clear(void);
	E_LIST_ERROR_TYPE TraverseList();
	E_LIST_ERROR_TYPE GetIndexList(T val, LinkedList<unsigned int>& idxList);
	LinkedList<unsigned int>* GetIndexList(T val);

private:
	Node<T>* GetNodeByIdx(unsigned int uiIdx);
	E_LIST_ERROR_TYPE AddFirst (Node<T>& NewHead);
	E_LIST_ERROR_TYPE Append (Node<T>& NewLast);
	int compare(T val1,T val2);
};

template class LinkedList<unsigned int>;
template class LinkedList<int>;
template class Node<unsigned int>;
template class Node<int>;
#endif /* LINKED_LIST_H_ */
