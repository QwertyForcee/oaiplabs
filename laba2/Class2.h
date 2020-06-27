//---------------------------------------------------------------------------
#include <string>
#include <vcl.h>
#ifndef ClassH
#define ClassH
using namespace std;
class Person{
 private:
 int number,age,height,weight;
 UnicodeString name,hobby,habits;
 public:
 Person(){
 };
 Person(int number,int age,int height,int weight,UnicodeString name,UnicodeString hobby,UnicodeString habits){
	this->number=number;
	this->age=age;
	this->height=height;
	this->weight=weight;
 }
 void LoadInfo(int number,int age,int height,int weight,UnicodeString name,UnicodeString hobby,UnicodeString habits){
  	this->number=number;
	this->age=age;
	this->height=height;
	this->hobby=hobby;
	this->weight=weight;
	this->name=name;
    this->habits=habits;
	this->weight=weight;
 }
 UnicodeString ShowName(){
	return name;
 }
 UnicodeString ShowHobby(){
	return hobby;
 }
 UnicodeString ShowHabits(){
	return habits;
 }
 int ShowNumber(){
	return number;
 }
 int ShowAge(){
	return age;
 }
 int ShowHeight(){
	return height;
 }
 int ShowWeight(){
	return weight;
 }


};



//---------------------------------------------------------------------------
#endif
