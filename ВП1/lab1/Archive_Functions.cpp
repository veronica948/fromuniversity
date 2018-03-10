#include"Archive.h"

Archive::Archive(int a) {
 n=a;
 books=new Book [n];
 if(!books)
        {cout<<"Error";
        exit(1);}
}
Archive::~Archive() {
 delete []books;
}
void Archive::Create_Archive() {
 for(int i=0;i<n;i++)
 books[i].Create_Book();
}
void Archive::Print_table() { cout.width(10);
  cout<<"Author ";
  cout.width(10);
  cout<<"Book's name";
  cout.width(10);
  cout<<"Izdat ";
  cout.width(10);
  cout<<"Year ";
  cout.width(10);
  cout<<"Pages ";
  cout<<endl;
}                             
void Archive::Print_Archive() {
 Print_table();
 for(int i=0;i<n;i++)
 books[i].Print_Book();
}
void Archive::special_author() {
   char t[20];
   cout<<"Enter author"<<endl;
   cin>>t;
   int f=1;
   Print_table();
   for(int i=0;i<n;i++)
   if(!strcmp(books[i].Get_Author(),t))
   {books[i].Print_Book();  f=0;}
   if(f) {cout<<"No books"<<endl;}
}
void Archive::special_izd() {
   char t[20];
   cout<<"Enter publishing house"<<endl;
   cin>>t;
   int f=1;
   Print_table();
   for(int i=0;i<n;i++)
    if(!strcmp(books[i].Get_Izd(),t))
  { books[i].Print_Book(); f=0;}
  if(f) cout<<"No books"<<endl;
}
void Archive::after_year() {
   int N;
   cout<<"Enter the year"<<endl;
   cin>>N;
   Print_table();
   int f=1;
   for(int i=0;i<n;i++)
   if(books[i].Get_Year()>N)  {f=0;
   books[i].Print_Book(); }
   if(f) cout<<"No books"<<endl;
   }