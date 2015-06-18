#ifndef DOUBLENODE_H
#define DOUBLENODE_H

#include "Interfaces01.h"

struct DoubleNode : public IDoubleNode
{
	int value;
	IDoubleNode * _prev;
	IDoubleNode * _next;
public:
	
	DoubleNode() { _prev = NULL; _next = NULL; }
	~DoubleNode() { delete _prev; delete _next; }
	 void setValue(int value);
	 int getValue();
	 IDoubleNode * getPrev();
	 IDoubleNode * getNext();
	 void setPrev(IDoubleNode * prev);
	 void setNext(IDoubleNode * next);

};

#endif