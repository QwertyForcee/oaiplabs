//---------------------------------------------------------------------------

#include <vcl.h>
#include "Unit3.h"
#pragma hdrstop

#include "mainwin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int min;
HashTable* table;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
    Memo1->Clear();
	Memo2->Clear();
	Memo3->Clear();
	Edit1->Text = "";
	Edit2->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
	try {
		table = new HashTable(StrToInt(Edit2->Text));
	} catch (...) {
		return;
	}
    min=1000;
	for (int i = 0; i < StrToInt(Edit1->Text); i++) {
		int random =  1 + rand() % 100;
		if(random<min)min=random;
		table->Add(random);
		Memo1->Lines->Add(IntToStr(random));
	}
	int* keyArr = new int[StrToInt(Edit1->Text)];
	int pos = 0;
	int haveMin=0;
	for (int i = 0; i < StrToInt(Edit2->Text); i++) {
		haveMin=0;
		Stack* stack = table->GetStack(i);
		String str = "";
		while (stack->Filled()){
			keyArr[pos] = stack->GetKey();
			str += IntToStr(stack->GetKey());
			str+= "->";
			if(stack->GetKey()==min)
			{
				haveMin=1;
			}
			stack = stack->Pop();
			pos++;
		}
        if(haveMin)Memo2->Lines->Append(str);
		table->SetStack(i, stack);
		Memo3->Lines->Append(str);
	}
	for (int i = 0; i < StrToInt(Edit1->Text); i++) {
		table->Add(keyArr[i]);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	table->DeleteTable();
	Memo1->Clear();
	Memo2->Clear();
	Memo3->Clear();
	Edit1->Text = "";
	Edit2->Text = "";
}
//---------------------------------------------------------------------------
