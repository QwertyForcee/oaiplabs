//---------------------------------------------------------------------------

#ifndef listsH
#define listsH
#include <iostream>
#include "queue.h"
class List:public Queue
{
public:
	void Sort(List* list);
    int Size;
	QNode *head;
};
void List::Sort(List* list){
	QNode* t1=NULL;
	QNode* t2=NULL;
	int temp=0;
	int count=list->GetSize();
	for (int j = 0; j < count-1 ; j++) {
		for (int i = 0; i < count -j- 1; i++) {
				int counter = 0;
				t1=&list->get_head();
				while (t1!=NULL) {
				if (counter == i) {
				break;
				}
				t1=t1->pNext;
				counter++;
				}
				t2=t1->pNext;
				if (t2->data <t1->data) {
				temp = t2->data;
				t2->data = t1->data;
				t1->data = temp;
				}
		}
	}
}
void RefreshBox(TListBox *ListListBox,List* list)
{
		if(list->GetSize()>0)
		{
			QNode* temp=&list->get_head();
			ListListBox->Items->Clear();
			while(temp){
				ListListBox->Items->Add(temp->data);
				temp=temp->pNext;
			}
		}else ListListBox->Items->Clear();
}
//---------------------------------------------------------------------------
#endif
