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

template <class T>
class ListNode
{
protected:
	T m_Val;
	ListNode<T> *m_p_NextNode;
public:
	ListNode();
	ListNode(T val);
	ListNode(ListNode<T> &node);
	~ListNode();
	T Get_Val(void);
	void Set_Val(T new_val);
};

template <class T>
class LinkedList
{
protected:
	unsigned int m_uiNodeCount;
	unsigned int m_uiCapacity;
	ListNode<T> *m_p_First;
	ListNode<T> *m_p_Last ;
public:
	LinkedList(unsigned int Capacity = 0);
	LinkedList(ListNode<T> *_head, unsigned int Capacity = 0);
	LinkedList(LinkedList&  _list, unsigned int Capacity = 0);
	~LinkedList();
	E_LIST_ERROR_TYPE Add_First (ListNode<T> new_head);
	E_LIST_ERROR_TYPE Add_First (T new_head_val);
	E_LIST_ERROR_TYPE Add_Last (ListNode<T> new_last);
	E_LIST_ERROR_TYPE Add_Last (T new_last_val);
	E_LIST_ERROR_TYPE Add_After(ListNode<T> new_node, ListNode<T> base_node);
	E_LIST_ERROR_TYPE Add_After(T node_val, ListNode<T> base_node);
	E_LIST_ERROR_TYPE Add_Before(ListNode<T> new_node, ListNode<T> base_node);
	E_LIST_ERROR_TYPE Add_Before(T node_val, ListNode<T> base_node);
	ListNode<T>& Find(T val);
	ListNode<T>& Find_Last(T val);
	E_LIST_ERROR_TYPE Get_Index(T val, unsigned int *idx_val);
	E_LIST_ERROR_TYPE Get_Index(ListNode<T> Node, unsigned int *idx_val);
	E_LIST_ERROR_TYPE Remove (T val);
	E_LIST_ERROR_TYPE Remove (ListNode<T> Node);
	E_LIST_ERROR_TYPE Remove_First(void);
	E_LIST_ERROR_TYPE Remove_Last(void);
	E_LIST_ERROR_TYPE Remove_By_Idx (unsigned int index);
	E_LIST_ERROR_TYPE Clear(void);
};
#endif /* LINKED_LIST_H_ */
