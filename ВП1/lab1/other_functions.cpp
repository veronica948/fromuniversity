
#include"Archive.h"

void list_menu() {
    cout<<"1-Enter the books"<<endl;
    cout<<"2-Print the books"<<endl;
    cout<<"3-Special author"<<endl;
    cout<<"4-Special publishing house"<<endl;
    cout<<"5- After special year"<<endl;
    cout<<"6-Exit"<<endl;
}
void menu(Archive arch) {
     int f=1;
     while(f)
{ list_menu();
  cout<<"Choose numeral"<<endl;
  int n;
  cin>>n;
  switch(n){
  case 1: cout<<"Enter the books"<<endl;
          arch.Create_Archive();
          break;
  case 2: arch.Print_Archive();
          break;
  case 3: arch.special_author();
          break;
  case 4: arch.special_izd();
          break;
  case 6: f=0;
          break;
  case 5: arch.after_year();
          break;
  default: cout<<"Error";
           break;
    }
}
}
int main() {
   cout<<"Enter the number of books ";
   int n;
   cin>>n;
   Archive arch(n);
   menu(arch);
   system("pause");
   return 0;
}
