//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Class.h"
#include <stdio.h>
#include <ustring.h>
#include <string.h>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm2 *Form2;
int count=2;
Person *male=new Person[2];
Person *female=new Person[2];
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
    ListBox1->Clear();
	Memo1->Clear();
	Memo2->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ListBox1Click(TObject *Sender)
{
   int index=ListBox1->ItemIndex;
   Memo2->Clear();
   Memo2->Lines->Add("Name: "+male[index].ShowName());
   Memo2->Lines->Add("Hobby: "+male[index].ShowHobby());
   Memo2->Lines->Add("Habits: "+male[index].ShowHabits());
   Memo2->Lines->Add("Age: "+IntToStr(male[index].ShowAge()));
   Memo2->Lines->Add("Height: "+IntToStr(male[index].ShowHeight()));
   Memo2->Lines->Add("Weight: "+IntToStr(male[index].ShowWeight()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::LoadClick(TObject *Sender)
{
FileOpenDialog1->Execute();
TFileStream *thile=new TFileStream(FileOpenDialog1->FileName,fmOpenRead);
TStringList *SL=new TStringList;
SL->LoadFromStream(thile);
char *Ptr;
int number,age,height,weight;
 UnicodeString name,hobby,habits;
 int temp=0;
 for(int i=0;i<=count;i++)
 {
 number=StrToInt(SL->Strings[temp]);
 age=StrToInt(SL->Strings[temp+1]);
 height=StrToInt(SL->Strings[temp+2]);
 weight=StrToInt(SL->Strings[temp+3]);
 name=SL->Strings[temp+4];
 hobby=SL->Strings[temp+5];
 habits=SL->Strings[temp+6];
 male[i].LoadInfo(number,age,height,weight,name,hobby,habits);
 temp+=7;
 }


 //---------------
 for (int i = 0; i <= count; i++) {
   ListBox1->Items->Add(male[i].ShowName());
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::WomenLoadButClick(TObject *Sender)
{
FileOpenDialog2->Execute();
TFileStream *thile2=new TFileStream(FileOpenDialog2->FileName,fmOpenRead);
TStringList *SL=new TStringList;
SL->LoadFromStream(thile2);
char *Ptr;
int number,age,height,weight;
 UnicodeString name,hobby,habits;
 int temp=0;
 for(int i=0;i<=count;i++)
 {
 number=StrToInt(SL->Strings[temp]);
 age=StrToInt(SL->Strings[temp+1]);
 height=StrToInt(SL->Strings[temp+2]);
 weight=StrToInt(SL->Strings[temp+3]);
 name=SL->Strings[temp+4];
 hobby=SL->Strings[temp+5];
 habits=SL->Strings[temp+6];
 female[i].LoadInfo(number,age,height,weight,name,hobby,habits);
 temp+=7;
 }
 for (int i = 0; i <= count; i++) {
   ListBox2->Items->Add(female[i].ShowName());
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ListBox2Click(TObject *Sender)
{
	int index=ListBox2->ItemIndex;
   Memo1->Clear();
   Memo1->Lines->Add("Name: "+female[index].ShowName());
   Memo1->Lines->Add("Hobby: "+female[index].ShowHobby());
   Memo1->Lines->Add("Habits: "+female[index].ShowHabits());
   Memo1->Lines->Add("Age: "+IntToStr(female[index].ShowAge()));
   Memo1->Lines->Add("Height: "+IntToStr(female[index].ShowHeight()));
   Memo1->Lines->Add("Weight: "+IntToStr(female[index].ShowWeight()));
}
//---------------------------------------------------------------------------
