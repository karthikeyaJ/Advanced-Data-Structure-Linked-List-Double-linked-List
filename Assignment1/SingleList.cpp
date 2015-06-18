#include "SingleList.h"
#include "SingleNode.h"

ISingleNode *  SingleList::getHead()
{
	return(n);
}
void SingleList::setHead(ISingleNode * head){
	this->n = (ISingleNode*)head;
}
void SingleList::addHead(int value)
{
	if (getHead() == NULL)
	{
		SingleNode * n = new SingleNode;
		n->setValue(value);
		n->setNext(NULL);
		setHead(n);
	}
	else
	{
		SingleNode * n = new SingleNode;
		n->setValue(value);
		n->setNext(NULL);

		SingleNode * curr = (SingleNode *)getHead();
		n->setNext(curr);
		setHead(n);

	}

}
void SingleList::orderSort2(){
	SingleNode  *temp = NULL;
	SingleNode *curr = (SingleNode*)n;
	SingleNode *prev = NULL;


	while (curr != NULL && curr->getNext() != NULL)
	{

		temp = (SingleNode *)curr->getNext();
		curr->setNext(temp->getNext());
		temp->setNext(curr);

		if (prev != NULL)
			prev->setNext(temp);

		if (curr == n)
			n = temp;

		prev = curr;

		curr = (SingleNode *)curr->getNext();


	}


}
void SingleList::orderSort3(){

	SingleNode  *temp = NULL;
	SingleNode *curr = (SingleNode*)n;
	SingleNode *prev = (SingleNode*)n;


	while (curr != NULL && curr->getNext() != NULL)
	{

		temp = (SingleNode *)curr->getNext();

		

		if ((temp->getNext()) != NULL)
		{

			if (prev->getNext() == curr)
			{
				prev->setNext(curr->getNext()->getNext());
			}
			curr->setNext(temp->getNext()->getNext());
			
			prev = (SingleNode *)temp->getNext();
			temp->setNext(curr);
			prev->setNext(temp);
			if (curr == n)
				n = prev;

			prev = curr;

			curr = (SingleNode *)curr->getNext();
		}
		else
		{
			prev->setNext(temp);
			temp->setNext(curr);
			curr->setNext(NULL);
			if (curr == n)
			n = prev;
			prev = curr;
		}
	}
}

void SingleList::sequenceOrderSort(){

	ISingleNode * t1 = n;
	ISingleNode * t2 = NULL;
	ISingleNode * curr = n;
	ISingleNode * temp1 = curr->getNext();
	curr->setNext(temp1->getNext());
	temp1->setNext(curr);
	n = temp1;
	t1 = curr->getNext();
	temp1 = curr;
	curr = t1;
	int count,size = 2;
	t2 = curr;
	curr = curr->getNext();
	do{
		size = size + 1;
		for (count = 1; count < size; count++)
		{
			if (t2->getNext() != NULL)
			{	
				t2->setNext(curr->getNext());
				temp1->setNext(curr);
				curr->setNext(t1);
				t1 = curr;
				curr = t2;
				if (curr->getNext() != NULL)
					curr = curr->getNext();
			}
		}
		if (count == size)
		{
			temp1 = t2;
			t1 = curr;
			t2 = curr;
			if (curr!=NULL)
			curr = curr->getNext();
			count = 1;
		}
	} while (curr != NULL);
}


void SingleList::reverse(){

	SingleNode  *temp = NULL;
	SingleNode *curr = (SingleNode*)n;
	SingleNode *prev = (SingleNode*)n;


	while (curr != NULL)
	{
		temp = prev;
		prev = curr;
		curr = (SingleNode *)curr->getNext();

		if (prev != n)
			prev->setNext(temp);
		if (n == temp)
			n->setNext(NULL);
	}

	n = prev;
}





