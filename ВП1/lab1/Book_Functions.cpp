#include"Book.h"

void Book::Create_Book() {
  cout<<"Author ";
  cin>>author;
  cout<<"Book's name ";
  cin>>name_of_book;
  cout<<"Izdatelstvo ";
  cin>>izd;
  cout<<"Year ";
  cin>>year;
  cout<<"Numbers of page ";
  cin>>number_of_page;
  cout<<endl;
 }
void Book:: Print_Book()  {
  cout.width(10);
  cout<<author;
  cout.width(10);
  cout<<name_of_book;
  cout.width(10);
  cout<<izd;
  cout.width(10);
  cout<<year;
  cout.width(10);
  cout<<number_of_page;
  cout<<endl;
 }
int Book::Get_Year() {
   return year;
}
/*
int Book::Compare_Author(char*t) {
 if(strcmp(author,t)) return 0;
 return 1;
}

int Book::Compare_Izd(char*t) {
  if(strcmp(izd,t)) return 0;
 return 1;
 }
 */
char* Book::Get_Author()
{ return author; }
 char* Book::Get_Izd()
{ return izd; }

