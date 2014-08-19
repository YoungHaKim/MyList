#include "stdafx.h"
#include "List.h"
#include "Node.h"

List::List()
{
	m_Head = new Node();
	m_Tail = new Node();
	m_Count = 0;
}
List::~List()
{
	Node* node = m_Head;

	while (node->m_NextNode != nullptr)
	{
		Node* remNode = node;
		node = node->m_NextNode;

		remNode->m_NextNode = nullptr;
		remNode->m_PrevNode = nullptr;
		remNode->m_Ptr = nullptr;
		delete(remNode);
	}	

	delete m_Tail;
}

// PUBLIC

void List::Push_Back(void* ptr)
{
	Node* node = new Node();
	node->m_Ptr = ptr;

	if (m_Head->m_NextNode == nullptr) // list is empty
	{		
		AddNode(node, m_Head, m_Tail);
	}
	else
	{
		AddNode(node, m_Tail->m_PrevNode, m_Tail);
	}
}
void* List::Pop_Back()
{
	if (m_Tail->m_PrevNode == nullptr)
		return nullptr;
	
	void* objPtr = m_Tail->m_PrevNode->m_Ptr;
	RemoveNode(m_Tail->m_PrevNode);

	return objPtr;
}
void* List::GetItem(void* iterPtr)
{
	Node* node = (Node*)iterPtr;
	return node->m_Ptr;
}
void List::InsertAfter(void* iterPtr, void* objectPtr)
{
	Node* node = new Node();
	node->m_Ptr = objectPtr;

	AddNode(node, (Node*)iterPtr, ((Node*)iterPtr)->m_NextNode);
}

void* List::GetBeginIterator()
{
	return (void*)(m_Head->m_NextNode);
}
void* List::GetEndIterator()
{
	return (void*)(m_Tail->m_PrevNode);
}
void List::IterateForward(void** iterPtr)
{
	Node* node = (Node*)*iterPtr;
	node = node->m_NextNode;	
	
	if (node == m_Tail || node == m_Head) 
		*iterPtr = nullptr;
	else
		*iterPtr = node;
}
void List::IterateBackward(void** iterPtr)
{
	Node* node = (Node*)*iterPtr;
	node = node->m_PrevNode;

	if (node == m_Tail || node == m_Head)
		*iterPtr = nullptr;
	else
		*iterPtr = node;	
}

int List::Count()
{
	return m_Count;
}


/// PRIVATE

void List::AddNode(Node* newNode, Node* prevNode, Node* nextNode)
{
	prevNode->m_NextNode = newNode;
	nextNode->m_PrevNode = newNode;

	newNode->m_NextNode = nextNode;
	newNode->m_PrevNode = prevNode;

	++m_Count;
}
void List::RemoveNode(Node* node)
{
	Node* prevNode = node->m_PrevNode;
	Node* nextNode = node->m_NextNode;

	prevNode->m_NextNode = node->m_NextNode;
	nextNode->m_PrevNode = node->m_PrevNode;

	node->m_NextNode = nullptr;
	node->m_PrevNode = nullptr;
	node->m_Ptr = nullptr;

	delete(node);

	--m_Count;
}