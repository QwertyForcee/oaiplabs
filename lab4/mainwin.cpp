//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainwin.h"
#include "Stack.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
int Priority(char temp);
float Solve(UnicodeString string,float args[]);
TForm2 *Form2;
Stack* first=NULL;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	StrGrid->Cells[0][1] = "a";
	StrGrid->Cells[0][2] = "b";
	StrGrid->Cells[0][3] = "c";
	StrGrid->Cells[0][4] = "d";
	StrGrid->Cells[0][5] = "e";
	StrGrid->Cells[1][1] = "1,2";//a
	StrGrid->Cells[1][2] = "0,7";//b
	StrGrid->Cells[1][3] = "9,3";//c
	StrGrid->Cells[1][4] = "6,5";//d
	StrGrid->Cells[1][5] = "8,4";//e
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ConvertButClick(TObject *Sender)
{
	UnicodeString oldform=Edit1->Text;
	UnicodeString newform="";
	int length=oldform.Length();
	char temp1;
	char temp2;
	for (int i=1;i<=length;i++)
	{
		temp1=oldform[i];
		if (temp1 == '(')
		{
			first = first->push(first, temp1);
		}
		if (temp1 == ')')
		{
			while(first->GetData() != '('){
				first = first->pop(first,&temp2);
				newform += temp2;
			}
			first = first->pop(first, &temp2);
		}
		if (temp1 >= 'a' && temp1 <= 'e')
		{
			newform += temp1;
		}
		if (temp1 == '*' || temp1 == '/' || temp1 == '+' || temp1 == '-' || temp1 == '^')
		{
			while (first != NULL && Priority(first->GetData()) >= Priority(temp1)){
				first = first->pop(first, &temp2);
				newform += temp2;
			}
			first = first->push(first, temp1);
		}

	}
	while(first != NULL)
	{
		first = first->pop(first, &temp1);
		newform+= temp1;
	}
	Edit2->Text = newform;
}
int Priority(char temp){
	switch(temp){
		case '^': return 4;
		case '*': return 3;
		case '/': return 3;
		case '+': return 2;
		case '-': return 2;
		case '(': return 1;

	}
	return 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
	UnicodeString outStr = Edit2->Text;
	float arr[50];
	for (int i = 1; i <= 5; i++) {
		arr[StrGrid->Cells[0][i][1]] = StrToFloat(StrGrid->Cells[1][i]);
	}
	Edit3->Text = FloatToStr(Solve(outStr, arr));
}
float Solve(UnicodeString string,float args[]){
	char tempChar;
	char temp1, temp2;
	float arg1,arg2,result = 0;
	char chr = 'z' + 1;
	for (int i = 1; i <= string.Length(); i++) {

		tempChar = string[i];
		if (!(tempChar == '*' || tempChar == '/' || tempChar == '+' || tempChar == '-' || tempChar == '^')) {
			first = first->push(first, tempChar);
		}
		else {

			first = first->pop(first, &temp1);
			first = first->pop(first, &temp2);

			arg1 = args[temp1];
			arg2 = args[temp2];

			switch(tempChar){
				case '*': result = arg2 * arg1;break;
				case '/': result = arg2 / arg1;break;
				case '+': result = arg2 + arg1;break;
				case '-': result = arg2 - arg1;break;
				case '^': result = pow(arg2,arg1);break;
			}
			args[chr] = result;
			first = first->push(first,chr);
			chr++;

		}
	}
	return result;

}
//---------------------------------------------------------------------------
