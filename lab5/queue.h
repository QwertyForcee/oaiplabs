//---------------------------------------------------------------------------
#ifndef queueH
#define queueH
#include <iostream>
#include <vcl.h>
struct QNode {
	public:
		QNode *pNext;
		int data;
		QNode(int data=int(), QNode *pNext=NULL) {
			this->data = data;
			this->pNext = pNext;
		}
};
class Queue
{
public:
	Queue();
	~Queue();
	void pop_front();
	void clear();
	void push_back(int data);
	QNode get_head();
	int get_front();
	int GetSize() {
		return Size;
	}
	QNode& operator[](const int index);
private:
	int Size;
	QNode *head;
};

void RefreshBox(TListBox *ListBox2,Queue* queue);
Queue::Queue() {
	Size = 0;
	head = NULL;
}
Queue::~Queue() {
	clear();
}
void Queue::pop_front()
{
	QNode *temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}
QNode Queue::get_head()
{
   QNode *temp=head;
   return *temp;
}
int Queue::get_front()
{
   QNode *temp=head;
   return temp->data;

}
void Queue::clear()
{
	while (Size) {
		pop_front();
	}

}
void Queue::push_back(int data) {
	if (head==NULL)
	{
		head = new QNode(data);
	}
	else
	{
		QNode *current = this->head;
		while (current->pNext!=NULL) {
			current = current->pNext;
		}
		current->pNext = new QNode(data);
	}
	Size++;
}
void RefreshBox(TListBox *ListBox2,Queue* queue)
{
		if(queue->GetSize()>0)
		{
			QNode* temp=&queue->get_head();
			ListBox2->Items->Clear();
			while(temp){
				ListBox2->Items->Add(temp->data);
				temp=temp->pNext;
			}
		}else ListBox2->Items->Clear();
}
QNode& Queue::operator[](const int index)
{
	int counter = 0;
	QNode *current = this->head;
	while (current!=NULL) {
		if (counter == index) {
			return *current;
		}
		current=current->pNext;
		counter++;
	}
}
//---------------------------------------------------------------------------
#endif
