#pragma once

class Node;

class List
{
public:
	List();
	~List();

	void	Push_Back(void* objectPtr);
	void*	Pop_Back();
	void*	GetItem(void* iterPtr);	
	void	InsertAfter(void* iterPtr, void* objectPtr);
	
	void*	GetBeginIterator();
	void*	GetEndIterator();	
	void	IterateForward(void** iterPtr);
	void	IterateBackward(void** iterPtr);

	int		Count();

private:
	void	AddNode(Node* newNode, Node* prevNode, Node* nextNode);
	void	RemoveNode(Node* node);

private:
	Node*	m_Head;
	Node*	m_Tail;
	int		m_Count;

};

