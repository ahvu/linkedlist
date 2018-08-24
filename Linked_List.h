/*
 * Linked_List.h
 *
 *  Created on: Aug 9, 2018
 *      Author: trdnguyen
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "ll_compiler.h"

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

inline E_LIST_ERROR_TYPE LL_ASSERT(E_LIST_ERROR_TYPE err)
{
	switch(err)
	{
		case eLIST_NO_ERR:
		case eLIST_EMPTY_LIST:
		case eLIST_OVER_CAPACITY:
		case eLIST_INVALID_INDEX:
		case eLIST_OUT_OF_MEMORY:
		default:
			return err;
			break;
	}
}
template <class T>
class LinkedList
{
public:
	LinkedList(unsigned int uiCapacity = 0);
    LinkedList(const LinkedList<T>& rList);
	~LinkedList();
    
	unsigned int GetCount(void);
	unsigned int GetCapacity(void);
    
	E_LIST_ERROR_TYPE AddFirst (T NewHeadVal); 
	E_LIST_ERROR_TYPE Append (T NewLastVal);
    E_LIST_ERROR_TYPE Append (LinkedList<T>& InList);
    E_LIST_ERROR_TYPE Insert (T NodeVal, unsigned int uiIdx);
    E_LIST_ERROR_TYPE Insert (LinkedList<T>& InList, unsigned int uiIdx);

	E_LIST_ERROR_TYPE RemoveFirst(void);
	E_LIST_ERROR_TYPE RemoveLast(void);
    E_LIST_ERROR_TYPE Remove (T NodeVal);
    E_LIST_ERROR_TYPE RemoveByIdx (unsigned int uiIdx);
	E_LIST_ERROR_TYPE Clear(void);
    
    E_LIST_ERROR_TYPE GetIndex(T NodeVal, unsigned int &ruiIdx);
    E_LIST_ERROR_TYPE GetIndexList(T NodeVal, LinkedList<unsigned int>& uiIdxList);
    E_LIST_ERROR_TYPE GetValByIdx(T& rRetVal, unsigned int uiIdx);

    T& operator[](unsigned int uiIdx);

private:
    template <class U>
    class Node
        {
        protected:
        	U m_Val;
        	Node *m_pNextNode;
        public:
        	Node();
        	Node(U NodeVal);
        	Node(Node &rNode);
        	~Node();
        	U& GetVal(void);
        	void SetVal(U NewVal);
        	Node* GetNextNode(void);
        	void SetNextNode(Node* pNode);
        };
#ifdef UNIT_TEST
private:
    E_LIST_ERROR_TYPE TraverseList();
    E_LIST_ERROR_TYPE AddFirst(Node<T>& rNewHead);
    E_LIST_ERROR_TYPE Append(Node<T>& rNewLast);
    Node<T>* GetNodeByIdx(unsigned int uiIdx);
    int Compare(T Val1, T Val2);
protected:
    unsigned int m_uiNodeCount;
    unsigned int m_uiCapacity;
    Node<T> *m_pFirst;
    Node<T> *m_pLast;

    LinkedList(Node<T> &rHead, unsigned int uiCapacity = 0);
    E_LIST_ERROR_TYPE Insert(Node<T>& rNewNode, unsigned int uiIdx);
#else
private:
    E_LIST_ERROR_TYPE TraverseList();
    E_LIST_ERROR_TYPE AddFirst(Node<T>& rNewHead);
    E_LIST_ERROR_TYPE Append(Node<T>& rNewLast);
    Node<T>* GetNodeByIdx(unsigned int uiIdx);
    int Compare(T Val1, T Val2);
protected:
    unsigned int m_uiNodeCount;
    unsigned int m_uiCapacity;
    Node<T> *m_pFirst;
    Node<T> *m_pLast;

    LinkedList(Node<T> &rHead, unsigned int uiCapacity = 0);
    E_LIST_ERROR_TYPE Insert(Node<T>& rNewNode, unsigned int uiIdx);
#endif
};
#ifdef LL_SEPERATE_IMPLEMENTATION 
#else
#include "linked_list_impl.h"
#endif // LL_SEPERATE_IMPLEMENTATION


template class LinkedList<unsigned int>;
template class LinkedList<int>;

#endif /* LINKED_LIST_H_ */
