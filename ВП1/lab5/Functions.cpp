#include"Studying.h"
Studying::Studying(int _number,int _age,char* _lastname,char* _firstname,double _mark) {
	age=_age;
	strcpy(lastname,_lastname);
	strcpy(firstname,_firstname);
	mark=_mark;
	number=_number;
}
void Studying::Show(){
	cout<<"Number: "<<number<<endl;
	cout<<"Lastname: "<<lastname<<endl;
	cout<<"Firstname: "<<firstname<<endl;
	cout<<"Age: "<<age<<endl;
	cout<<"Mark: "<<mark<<endl;	
}	
int Studying::Get_Age() {
	return age;
}
double Studying::Get_Mark() {
	return mark;
};
char* Studying::Get_LastName() {
	return lastname;
}
char* Studying::Get_FirstName() {
	return firstname;
}
int Studying::Get_Number() {
	return number;
}
void Studying::Set_Age(int n) {
	age=n;
}
void Studying::Set_LastName(char *c) {
	strcpy(lastname,c);
}
void Studying::Set_FirstName(char *c) {
	strcpy(firstname,c);
}
void Studying::Set_Mark(int n) {
	mark=n;
}
void Studying::Set_Number(int n) {
	number=n;
}
void Student::Show() {
	Studying::Show();
	cout<<"Stip: "<<stip<<endl;
	cout<<"Kurs: "<<kurs<<endl;
	cout<<"Group: "<<group<<endl;
	
}
void Pupil::Show()
{
	Studying::Show();
	cout<<"Class: "<<cl<<endl;
}