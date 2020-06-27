//---------------------------------------------------------------------------

#ifndef treeH
#define treeH
#include <vcl.h>
//---------------------------------------------------------------------------
class Tree {
	protected:
	class Node{
		protected:
		String fio;
		int passNum;
		Node* left;
		Node* right;
		public:
		Node(String fio, int passNum){
			this->fio = fio;
			this->passNum = passNum;
			left = NULL;
			right = NULL;
		}
		Node(){


		}
		int GetLongest(Node* node,int curr)
		{
			if(node==NULL) return curr;
			int t1=0,t2=0;
			if(right)
			{
				 t1=GetLongest(node->right,curr+1);
			}
			if(left)
			{
			      t2=GetLongest(node->left,curr+1);
			}
			return  t1>t2?t1:t2;

		}
		void Print(TTreeView* treeView,TMemo* memo, int kl){
			//treeView->Items->AddChildFirst(NULL,);

            if (kl== -1) {
				treeView->Items->AddFirst(NULL,fio + ":" + IntToStr(passNum));
			}
			else{
					treeView->Items->AddChildFirst(treeView->Items->Item[kl],fio + ":" + IntToStr(passNum));
			}
			kl++;
			if (left) {

				left->Print(treeView, memo,kl);

			}

			//memo->Lines->Add(fio + ":" + IntToStr(passNum));

			if (right) {

				right->Print(treeView, memo,kl);

			}
			kl--;

		}
		void Insert(String fio,int passNum){
			if (passNum > this->passNum && right) {
				right->Insert(fio, passNum);
			}
			else if(passNum > this->passNum && !right){
				right = new Node(fio, passNum);
			}
			else if(passNum < this->passNum && left){
				left->Insert(fio,passNum);
			}
			else {
				left = new Node(fio, passNum);
			}
		}
		void DelElement(int el){

			if(left){
				if (left->passNum == el) {
					if(!left->left && !left->right){
						delete left;
						left = NULL;
					}
					else if(!left->left && left->right){

						left = left->right;
					}
					else if(left->left && !left->right){

						left = left->left;
					}
					else{

                    }
				}
				left->DelElement(el);
			}
			if(right){
				right->DelElement(el);
			}


		}
		void Search(TMemo* memo, int number){
			if (number == passNum) {
				memo->Lines->Add(fio + ":" + IntToStr(passNum));
			}
			if (left) {
				left->Search(memo, number);
			}
			if(right){
				right->Search(memo, number);
			}

		}
		void Del(){
			if (left) {
				left->Del();
				delete left;
			}
			if (right) {
				right->Del();
				delete right;
			}
		}
		void PrObh(TMemo* memo){
			memo->Lines->Add(fio + ":" + IntToStr(passNum));
			if (left) {

				left->PrObh(memo);

			}
			if (right) {

				right->PrObh(memo);

			}
		}
		void ObrObh(TMemo* memo){

			if (left) {

				left->ObrObh(memo);

			}
			if (right) {

				right->ObrObh(memo);

			}
			memo->Lines->Add(fio + ":" + IntToStr(passNum));
		}
		void KeyObh(TMemo* memo){
			if (left) {

				left->KeyObh(memo);

			}
			memo->Lines->Add(fio + ":" + IntToStr(passNum));
			if (right) {

				right->KeyObh(memo);

			}

		}
		Node *createNode(String fio, int v)
		{
			Node *p = new Node;

			if (p != NULL)
			{
				p->fio = fio;
				p->passNum = v;
				p->left = NULL;
				p->right = NULL;
			}

			return p;
		}
		String GetFio(){
			return fio;
		}
		int GetPassNum(){
            return passNum;
		}
	};
	Node* root;
	public:
	Tree(){
		root = NULL;
	}
	int GetLong()
	{
        return root->GetLongest(root,0);
	}
	void Print(TTreeView* treeView, TMemo* memo){
		root->Print(treeView, memo,-1);
	}
	Node* GetRoot(){
		return root;
	}
	void SetRoot(Node* root){
		this->root = root;
	}
	void Insert(String fio, int passNum){
		if (!root) {
			root = new Node(fio, passNum);
		}
		else {
			root->Insert(fio,passNum);
		}
	}
	void Search(TMemo* memo,int number){
		memo->Clear();
		root->Search(memo,number);
	}

	void PrObh(TMemo* memo){
		memo->Clear();
		root->PrObh(memo);
	}
	void ObrObh(TMemo* memo){
		memo->Clear();
		root->ObrObh(memo);

	}
	void KeyObh(TMemo* memo){
		memo->Clear();
		root->KeyObh(memo);

	}


	~Tree(){
		if (!root) {
			return;
		}
		root->Del();
		delete root;
		root = NULL;

	}


};










#endif
