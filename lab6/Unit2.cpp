//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "TreeStruct.h"
#include "tree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
Tree tree;
int numberOfElements = 0;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	Memo1->Text="";
	StringGrid1->Cells[0][0]="Ignatovich";
	StringGrid1->Cells[1][0]="543";
	StringGrid1->Cells[0][1]="Ivanov";
	StringGrid1->Cells[1][1]="343";
    numberOfElements=2;

}
//---------------------------------------------------------------------------
/*void FindIndex(Tree *node,int id){
   if (node=NULL)return;
   if(node->id==id)
   {
	 // Memo1->Text=ShowInfo(node);
   }
   else if(node->id>id)
   {
	  FindIndex(node->right,id);
   }
   else if(node->id<id)
   {
	FindIndex(node->left,id);
   }
}        */
//---------------------------------------------------------------------------

void __fastcall TForm2::FillButtonClick(TObject *Sender)
{
    tree.~Tree();
	for(int i = 0; i < numberOfElements; i++){
		tree.Insert(StringGrid1->Cells[0][i], StrToInt(StringGrid1->Cells[1][i]));
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::PrintButtonClick(TObject *Sender)
{
	Memo1->Clear();
	TreeView1->Items->Clear();
	for (int i = 0; i < numberOfElements; i++) {
		Memo1->Lines->Add(StringGrid1->Cells[0][i] + ":" + StringGrid1->Cells[1][i]);
	}
	tree.Print(TreeView1,Form2->Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
 if (IdEdit->Text!="" && NameEdit->Text!="") {
	tree.Insert(NameEdit->Text,StrToInt(IdEdit->Text));
	StringGrid1->Cells[0][numberOfElements]=NameEdit->Text;
	StringGrid1->Cells[1][numberOfElements]=IdEdit->Text;
    numberOfElements++;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
    tree.PrObh(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
    tree.ObrObh(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{
    tree.KeyObh(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button5Click(TObject *Sender)
{
	//tree.GetLongest(tree.GetRoot(),0);
	int res=tree.GetLong();
    ResLabel->Caption=res;
}
//---------------------------------------------------------------------------
