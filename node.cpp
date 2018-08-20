/*
 * list_node.cpp
 *
 *  Created on: Aug 20, 2018
 *      Author: trdnguyen
 */

#include "linked_list.h"
/*
 * @brief: ListNode member definition
 */
template<class T>
Node<T>::Node()
{
	m_pNextNode = NULL_PTR;
}

template<class T>
Node<T>::Node(T Val)
{
	m_pNextNode = NULL_PTR;
	m_Val = Val;
}

template<class T>
Node<T>::Node(const Node<T>& rNode)
{
	m_pNextNode = NULL_PTR;
	m_Val = rNode.m_Val;
}

template<class T>
Node<T>::~Node()
{
	//Do nothing
}

template <class T>
T& Node<T>::GetVal(void)
{
	return m_Val;
}

template <class T>
void Node<T>::SetVal(T NewVal)
{
	m_Val = NewVal;
}

template <class T>
Node<T>* Node<T>::GetNextNode(void)
{
	return m_pNextNode;
}

template <class T>
void Node<T>::SetNextNode(Node<T>* pNode)
{
	m_pNextNode = pNode;
}
