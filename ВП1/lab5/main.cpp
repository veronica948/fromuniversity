#include"Studying.h"
void list_menu() {
    cout<<"1-Enter a new student"<<endl;
    cout<<"2-Enter a new pupil"<<endl;
    cout<<"3-Enter a new studying"<<endl;
    cout<<"4-Print all"<<endl;
    cout<<"5-Print a studying with given number "<<endl;
	cout<<"6-Exit"<<endl;
}
    
int main(){
	int index=0;
	Studying** Array = new Studying*[20];
	Student* p = new Student(23,18,"Weihrauch","Patrick",8.8,500);
	Array[index] = new Student (23,19,"Muller","Patrick",8.8,500,2,9);
	index++;
	Array[index] = new Student (28,27,"Neuer","Manuel",8.9,800,5,9);
	index++;
	Array[index] = new Pupil (22,6,"Kroos","Toni",5.5,1);
	index++;
	Array[index] = new Pupil (1,10,"Lahm","Phillip",6.0,4);
	index++;
	Array[index] = new Studying (1,10,"Reus","Marco",8.4);
	index++;	
	/*Student stud(42,23,"Ozil","Mesut",7,543,4,4);
	stud.Show();*/
	 int f=1;
	 int t=0;
	 int n;
	 char* firstname=new char[10];
	 char* lastname=new char[10];
	 int number,age,kurs,group,stip,cl;
	 double mark;
     while(f)
		{ list_menu();
		  cout<<"Choose numeral"<<endl;
		  
		  cin>>n;
		  switch(n){
		  case 1:   cout<<"Enter the number: ";
					cin>>number;
			        cout<<"Enter the name: ";
					cin>>firstname;
					cout<<"Enter the lastname: ";
					cin>>lastname;
					cout<<"Enter the age: ";
					cin>>age;
					cout<<"Enter the mark: ";
					cin>>mark;
					cout<<"Enter the stip: ";
					cin>>stip;
					cout<<"Enter the kurs: ";
					cin>>kurs;
					cout<<"Enter the group: ";
					cin>>group;
					Array[index]=new Student(number,age,lastname,firstname,mark,stip,kurs,group);
					index++;
					break;
		  case 2:   cout<<"Enter the number: ";
					cin>>number;
			        cout<<"Enter the name: ";
					cin>>firstname;
					cout<<"Enter the lastname: ";
					cin>>lastname;
					cout<<"Enter the age: ";
					cin>>age;
					cout<<"Enter the mark: ";
					cin>>mark;
					cout<<"Enter the class: ";
					cin>>cl;
					Array[index]=new Pupil(number,age,lastname,firstname,mark,cl);
					index++;
					break;
		  case 3:   cout<<"Enter the number: ";
					cin>>number;
			        cout<<"Enter the name: ";
					cin>>firstname;
					cout<<"Enter the lastname: ";
					cin>>lastname;
					cout<<"Enter the age: ";
					cin>>age;
					cout<<"Enter the mark: ";
					cin>>mark;
					Array[index]=new Studying(number,age,lastname,firstname,mark);
					index++;
					break;
		  case 4: for(int i=0;i<index;i++)
					{
						Array[i]->Show();
						cout<<endl;
					 }
				  break;

		  case 5: cout<<"Enter the number: ";
				  cin>>number;
				  
				  for(int i=0;i<index;i++)
						if(Array[i]->Get_Number()==number)
							{t=1;
							Array[i]->Show();
							cout<<endl;
							}
				  if(!t) cout<<"No elements"<<endl;
				  break;
		  case 6: f=0;
				  break;
  
		  default: cout<<"Error";
				   break;
			}
		}
	delete [] firstname;
	delete [] lastname;
	for(int i=0;i<index;i++)
		delete Array[i];
	delete [] Array;
	system("pause");
	return 0;
}