/*
 * list_node.h
 *
 *  Created on: Aug 20, 2018
 *      Author: trdnguyen
 */

#ifndef LIST_NODE_H_
#define LIST_NODE_H_

#ifndef NULL_PTR
#define NULL_PTR 0
#endif

template <class T>
class Node
{
protected:
	T m_Val;
	Node<T> *m_pNextNode;
public:
	Node();
	Node(T val);
	Node(Node<T> &node);
	~Node();
	T& GetVal(void);
	void SetVal(T NewVal);
	Node<T>* GetNextNode(void);
	void SetNextNode(Node<T>* pNode);
};


template class Node<unsigned int>;
template class Node<int>;

#endif /* LIST_NODE_H_ */
