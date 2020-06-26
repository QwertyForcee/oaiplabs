//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainwin.h"
#include "queue.h"
#include   "lists.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
Queue copy;
List listochek;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	 AddMemo->Text="";
	 copy.push_back(13);
	 copy.push_back(255);
	 copy.push_back(333);
	 copy.push_back(7);
	 for(int i=0;i<copy.GetSize();i++){
	  ListBox2->Items->Add(copy[i].data);
	 }
	 listochek.push_back(5);
	 listochek.push_back(53);
	 listochek.push_back(24);
	 listochek.push_back(6);
	 listochek.push_back(7);
	 listochek.push_back(100);

	 listochek.Sort(&listochek);
	 RefreshBox(Form2->ListListBox,&listochek);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::AddButClick(TObject *Sender)
{
   if(AddMemo->Text!="") {
   copy.push_back(AddMemo->Text.ToInt());
   RefreshBox(Form2->ListBox2,&copy);
   AddMemo->Text="";
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::PopButClick(TObject *Sender)
{
	if(copy.GetSize()!=0){
	copy.pop_front();
	RefreshBox(Form2->ListBox2,&copy);
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm2::ClearButClick(TObject *Sender)
{
	ListBox2->Items->Clear();
    copy.clear();
}
//---------------------------------------------------------------------------
