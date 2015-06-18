#pragma once

#include "Interfaces01.h"

class SingleNode : public ISingleNode
{
private:
	int value;
	ISingleNode *next;

public:
	SingleNode() { next = NULL; }
	~SingleNode() { delete next; }
	void setValue(int value);
	int getValue();
	ISingleNode * getNext();
	void setNext(ISingleNode * next);
};