#include "stdafx.h"
#include "Node.h"


Node::Node()
{
	m_NextNode = nullptr;
	m_PrevNode = nullptr;
	m_Ptr = nullptr;
}


Node::~Node()
{
}
