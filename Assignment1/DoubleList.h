
#pragma once

#include "Interfaces01.h"

class DoubleList : public IDoubleList
{
 //= (ISingleNode*)malloc(sizeof(ISingleNode));
	DoubleNode* head=NULL;
	DoubleNode* tail=NULL;



public :
	DoubleList() { head = NULL; tail = NULL; }
	~DoubleList() { delete head; delete tail; }
	IDoubleNode * getHead();
	IDoubleNode * getTail();
	void setHead(IDoubleNode * head);
	void setTail(IDoubleNode * tail);
	void addSorted(int value);
	void orderSort2();
	void orderSort3();
	void sequenceOrderSort();
	void reverse();
};
