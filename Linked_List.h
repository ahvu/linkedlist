/*
 * Linked_List.h
 *
 *  Created on: Aug 9, 2018
 *      Author: trdnguyen
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

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

template <class T> class ListNode;
template <class T> class LinkedList;

template <class T>
class ListNode
{
protected:
	T m_Val;
	ListNode<T> *m_pNextNode;
public:
	ListNode();
	ListNode(T val);
	ListNode(ListNode<T> &node);
	~ListNode();
	T GetVal(void);
	void SetVal(T NewVal);
	friend class LinkedList<T>;
};

template <class T>
class LinkedList
{
protected:
	unsigned int m_uiNodeCount;
	unsigned int m_uiCapacity;
	ListNode<T> *m_pFirst;
	ListNode<T> *m_pLast ;
public:
	LinkedList(unsigned int uiCapacity = 0);
	LinkedList(ListNode<T> *Head, unsigned int uiCapacity = 0);
	LinkedList(LinkedList&  List, unsigned int uiCapacity = 0);
	~LinkedList();
	unsigned int GetCount(void);
	E_LIST_ERROR_TYPE AddFirst (ListNode<T>& NewHead); // Changed to reference as duplicate node creation

	E_LIST_ERROR_TYPE AddFirst (T NewHeadVal); 
	E_LIST_ERROR_TYPE AddLast (ListNode<T>& NewLast); // Changed to reference as duplicate node creation
	E_LIST_ERROR_TYPE AddLast (T NewLastVal);
	E_LIST_ERROR_TYPE AddAfter(ListNode<T> NewNode, ListNode<T> BaseNode);
	E_LIST_ERROR_TYPE AddAfter(T NodeVal, ListNode<T> BaseNode);
	E_LIST_ERROR_TYPE AddBefore(ListNode<T> NewNode, ListNode<T> BaseNode);
	E_LIST_ERROR_TYPE AddBefore(T NodeVal, ListNode<T> BaseNode);
	ListNode<T>& Find(T Val);
	ListNode<T>& FindLast(T Val);
	E_LIST_ERROR_TYPE GetIndex(T val, unsigned int *puiIdxRet);
	E_LIST_ERROR_TYPE GetIndex(ListNode<T> Node, unsigned int *puiIdxRet);
	E_LIST_ERROR_TYPE Remove (T val);
	E_LIST_ERROR_TYPE Remove (ListNode<T> Node);
	E_LIST_ERROR_TYPE RemoveFirst(void);
	E_LIST_ERROR_TYPE RemoveLast(void);
	E_LIST_ERROR_TYPE RemoveByIdx (unsigned int uiIndex);
	E_LIST_ERROR_TYPE Clear(void);
};

#endif /* LINKED_LIST_H_ */
