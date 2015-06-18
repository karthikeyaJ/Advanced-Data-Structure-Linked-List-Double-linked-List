#include "DoubleNode.h"
#include "DoubleList.h"



	IDoubleNode* DoubleList::getHead()
	{
	return(head);
	}
	IDoubleNode * DoubleList::getTail()
	{
		return(tail);
	}
	 void DoubleList::setHead(IDoubleNode * head)
	 {
		 this->head = (DoubleNode*)head;
	 }
	 void DoubleList::setTail(IDoubleNode * tail) 
	 {
		 this->tail = (DoubleNode*)tail;
	 }
	 
	 
	 
	 void DoubleList::addSorted(int value)
	 {
		 DoubleNode* currNode = new DoubleNode();
		 currNode->setValue(value);
		 DoubleNode* t1 = NULL;
		 DoubleNode* t2 = NULL;		

			 if (head == NULL)
			 {
				 setHead(currNode);
				 tail = currNode;
				 return;
			 }

			 else if ((currNode->getValue()) < (head->getValue()))
			 {
				 currNode->setNext(head);
				 head->setPrev(currNode);
				 head = currNode;
				 head->setPrev(NULL);
				 tail->setNext(NULL);
			 }

			 else if ((currNode->getValue()) > (tail->getValue()))
			 {

				 currNode->setPrev(tail);
				 tail->setNext(currNode);
				 tail = currNode;
				 tail->setNext(NULL);

			 }
			 else
			 {
				 t1 = head;
				 while (t1 != NULL)
				 {
					 
					 DoubleNode* t2 = (DoubleNode*)t1->getNext();
					 if (t2 == NULL)
						 break;
					 if ((currNode->getValue()) > (t1->getValue()) && (currNode->getValue()) < (t2->getValue()))
					 {

						 currNode->setPrev(t1);
						 t1->setNext(currNode);
						 currNode->setNext(t2);
						 t2->setPrev(currNode);
					 }
					 if (t1->getNext()!=NULL)
					 t1 = (DoubleNode*)t1->getNext();

				 }
			 }

		 }



	 
	 void DoubleList::orderSort2()
	 {
		 DoubleNode  *temp1 = NULL;
		 DoubleNode *curr = (DoubleNode*)head;
		 DoubleNode *prev = NULL;


		 while (curr != NULL && curr->getNext() != NULL)
		 {
			 temp1 = (DoubleNode *)curr->getNext();
			 if (temp1->getNext() != NULL)
			 {
				 curr->setNext(temp1->getNext());

				 temp1->setNext(curr);

				 curr->setPrev(temp1);

				 if (prev != NULL)
				 {
					 prev->setNext(temp1);
					 temp1->setPrev(prev);
				 }

				 if (curr == head)
				 {
					 head = temp1;
					 head->setPrev(NULL);
				 }
				 prev = curr;
				 curr = (DoubleNode *)curr->getNext();

				 curr->setPrev(prev);
			 }
			 else{ 
				 prev->setNext(temp1);
				 temp1->setPrev(prev);
				 curr->setNext(NULL);
				 temp1->setNext(curr);
				 curr->setPrev(temp1);
			     
				
			 }
		 }
		 tail = curr;
	 }
	 void DoubleList::orderSort3(){
	 
		 DoubleNode  *temp1 = NULL,*temp2=NULL;
		 DoubleNode *curr = (DoubleNode*)head;
		 DoubleNode *prev = (DoubleNode*)head;



		 while (curr != NULL && curr->getNext() != NULL)
		 {

			 temp1 = (DoubleNode *)curr->getNext();



			 if ((temp1->getNext()) != NULL)
			 {

				 if (prev->getNext() == curr)
				 {
					 prev->setNext(curr->getNext()->getNext());
					 temp2 = (DoubleNode *)curr->getNext()->getNext();
					 temp2->setPrev(prev);
				 }
				 curr->setNext(temp1->getNext()->getNext());

				 prev = (DoubleNode *)temp1->getNext();
				 temp1->setNext(curr);
				 prev->setNext(temp1);
				 if (curr == head)
				 {
					 head = prev;
					 head->setPrev(NULL);
				 }
					 temp1->setPrev(prev);
				 prev = curr;
				 prev->setPrev(temp1);

				 curr = (DoubleNode *)curr->getNext();
				 if (curr!=NULL)
				curr->setPrev(prev);
			 }
			 else
			 {
				 prev->setNext(temp1);
				 temp1->setNext(curr);

				 curr->setNext(NULL);
				 curr->setPrev(temp1);
				 if (curr == head)
					 head = prev;
				 temp1->setPrev(prev);

				 prev = curr;
				 curr = (DoubleNode *)curr->getNext();

			 }
		 }

		 tail = prev; 
	 
	 
	 }


	 void DoubleList::sequenceOrderSort()
	 {
		 DoubleNode * t1 = head;
		 DoubleNode * t2 = NULL;
		 DoubleNode * t3 = NULL;
		 DoubleNode *t4 = NULL;
		 DoubleNode * curr = head;
		 DoubleNode * temp1 = (DoubleNode *)curr->getNext();
		 t3 = (DoubleNode *)temp1->getNext();
		 curr->setNext(t3);
		 t3->setPrev(curr);
		 temp1->setNext(curr);
		 curr->setPrev(temp1);
		 head = temp1;
		 head->setPrev(NULL);
		 t1 = (DoubleNode *)curr->getNext();
		 temp1 = curr;
		 curr = t1;
		 int count, size = 2;
		 t2 = curr;
		 curr = (DoubleNode *)curr->getNext();
		 do{
			 size = size + 1;
			 for (count = 1; count < size; count++)
			 {
				 if (t2->getNext() != NULL)
				 {
					 t4 = (DoubleNode *)curr->getNext();
					 t2->setNext(t4);
					 if (t4 == NULL)
					 {
						 temp1->setNext(curr);
						 curr->setPrev(temp1);
						 curr->setNext(t1);
						 t1->setPrev(curr);
						 setTail(t2);
						 tail->setNext(NULL);
						 head->setPrev(NULL);
						 return;
						
					 }
					 t4->setPrev(t2);
					 temp1->setNext(curr);
					 curr->setPrev(temp1);

					 curr->setNext(t1);
					 t1->setPrev(curr);
					 t1 = curr;
					 curr = t2;
					 if (curr->getNext() != NULL)
					 
						 curr = (DoubleNode *)curr->getNext();

					 
				 }
			 }
			 if (count == size)
			 {
				 temp1 = t2;
				 t1 = curr;
				 t2 = curr;
				 if (curr != NULL)
					 curr = (DoubleNode *)curr->getNext();
				 count = 1;
			 }
		 } while (curr != NULL);

		 setTail(t2);

		 tail->setNext(NULL);
		 head->setPrev(NULL);
	
	 }
	 
	 void DoubleList::reverse(){

		 DoubleNode  *temp = NULL;
		 DoubleNode *curr = (DoubleNode*)head;
		 DoubleNode *prev = (DoubleNode*)head;


		 while (curr != NULL )
		 {
			     temp = prev;
			     prev = curr;
				 curr = (DoubleNode *)curr->getNext();
				 tail = head;
				 if (prev != head)
				 {
					 prev->setNext(temp);
					 temp->setPrev(prev);
					 prev->setPrev(NULL);
				 }
				 if (head == temp)
					 head->setNext(NULL);
			 
		 }
		 head = prev;
		 
	 }
	 
	 