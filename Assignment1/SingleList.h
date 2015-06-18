#ifndef SINGLELIST_H
#define SINGLELIST_H

#include "Interfaces01.h"

class SingleList : public ISingleList
{

private:
	ISingleNode* n; //= (ISingleNode*)malloc(sizeof(ISingleNode));
	//ISingleNode* curr;

public:
	SingleList() { n = NULL; }
	~SingleList() { delete n; };
    ISingleNode * getHead();
	void setHead(ISingleNode * head);
	void addHead(int value);
	void orderSort2();
	void orderSort3();
	void sequenceOrderSort();
	void reverse();
};

#endif