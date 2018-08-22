/*
 * node.h
 *
 *  Created on: Aug 20, 2018
 *      Author: trdnguyen
 */

#ifndef NODE_H_
#define NODE_H_

#include "ll_compiler.h"

template <class T>
class Node
{
protected:
	T m_Val;
	Node<T> *m_pNextNode;
public:
	Node();
	Node(T val);
	Node(const Node<T> &Node);
	~Node();
	T& GetVal(void);
	void SetVal(T NewVal);
	Node<T>* GetNextNode(void);
	void SetNextNode(Node<T>* pNode);
};

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
#endif /* NODE_H_ */
