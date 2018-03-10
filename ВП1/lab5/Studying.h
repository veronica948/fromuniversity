#include<iostream>
#include<string.h>
using namespace std;
class Studying {
	int number;
	int age;
	double mark;
protected:
	char lastname[20];
	char firstname[20];
	
public:
	Studying(int _number,int _age,char* _lastname,char* _firstname,double _mark);
	virtual void Show();
	int Get_Age();
	double Get_Mark();
	char* Get_LastName();
	char* Get_FirstName();
	int Get_Number();
	void Set_Age(int n);
	void Set_LastName(char *c);
	void Set_FirstName(char *c);
	void Set_Mark(int n);
	void Set_Number(int n);
};

class Student: public Studying {
	int stip;
	int group;
	int kurs;
public:
	Student(int _number,int _age,char* _lastname,char* _firstname,double _mark,int _stip=0,int _kurs=1,int _group=1):Studying(_number,_age,_lastname,_firstname,_mark) {
		stip=_stip;
		group=_group;
		kurs=_kurs;
	}
	void Set_Stip(int n) {stip=n;}
	int Get_Stip() {return stip;}
	void Set_Group(int n) {group=n;}
	int Get_Group() {return group;}
	void Set_Kurs(int n) {kurs=n;}
	int Get_Kurs() {return kurs;}
	void Show();
};

class Pupil: public Studying{
	int cl;
public:
	Pupil(int _number,int _age,char* _lastname,char* _firstname,double _mark,int _cl=1):Studying(_number,_age,_lastname,_firstname,_mark) {cl=_cl;}
	void Show();
	void Set_Class(int n) {cl=n;}
	int Get_Class() {return cl;}
};
