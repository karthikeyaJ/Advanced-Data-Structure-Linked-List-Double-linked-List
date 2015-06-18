#include "DoubleNode.h"
void DoubleNode::setValue(int value)
{
	this->value = value;
}

int DoubleNode::getValue()
{
	return(this->value);
}

void DoubleNode::setPrev(IDoubleNode * prev)
{
	_prev =prev;
}

IDoubleNode * DoubleNode::getPrev()
{
	return _prev;
}

void DoubleNode::setNext(IDoubleNode * next)
{
	_next = next;
}

IDoubleNode* DoubleNode::getNext()
{
	return _next;
};

