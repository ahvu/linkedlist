/*
 * node.h
 *
 *  Created on: Aug 20, 2018
 *      Author: trdnguyen
 */

#ifndef NODE_H_
#define NODE_H_

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
	Node(const Node<T> &node);
	~Node();
	T& GetVal(void);
	void SetVal(T NewVal);
	Node<T>* GetNextNode(void);
	void SetNextNode(Node<T>* pNode);
};


#endif /* NODE_H_ */
