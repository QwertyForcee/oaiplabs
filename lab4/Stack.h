//---------------------------------------------------------------------------
#include <iostream>
#ifndef StackH
#define StackH
class Stack{
	 private:
	 Stack* pNext;
	 char data;
	 public:
	 Stack();
	 char GetData();
	 char SetData(char data);
	 Stack* push(Stack* first, char data);
	 Stack* pop(Stack* first,char* data);
};
Stack::Stack(){
	pNext=NULL;
	data=NULL;
}
char Stack::GetData(){
	return data;
}
char Stack::SetData(char data){
	this->data=data;
}
Stack* Stack::push(Stack* first, char data){
		Stack* stack = new Stack;
		stack->data = data;
		stack->pNext =first;
		return stack;
}
Stack* Stack::pop(Stack* first,char* data){
   Stack* temp=first;
   *data = first->data;
   temp=temp->pNext;
   delete first;
   return temp;
}

//---------------------------------------------------------------------------
#endif
