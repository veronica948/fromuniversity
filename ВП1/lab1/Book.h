#include<conio.h>
#include<iostream>
#include<string.h>
using namespace std;

class Book {
    char author[10];
    char name_of_book[10];
    char izd[10];
    int year;
    int number_of_page;
     public:
    void Print_Book();
    void Create_Book();
    //int Compare_Author(char*t);
    //int Compare_Izd(char*t);
    int Get_Year();
	char* Get_Author();
    char* Get_Izd();
   };
