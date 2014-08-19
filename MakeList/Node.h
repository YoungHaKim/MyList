#pragma once
class Node
{
public:
	Node();
	~Node();

	Node* m_NextNode;
	Node* m_PrevNode;
	void* m_Ptr;
};

