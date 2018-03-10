#include "stack.h"
int main() {
	Stack stack;
	cout<<"Enter the expression\n";
	char*S=new char[30];
	cin>>S;

	/*cout<<(int)'('<<' '<<(int)')'<<endl;
	cout<<(int)'{'<<' '<<(int)'}'<<endl;
	cout<<(int)'['<<' '<<(int)']'<<endl;*/

	for(int i=0;S[i];i++)
	{
		if(S[i]=='('||S[i]=='{'||S[i]=='[')
			stack.Paste(S[i]);
		if(S[i]==')'||S[i]=='}'||S[i]==']')
			if(!stack.Compare(S[i])) 
				break;
			
	}
	if(stack.Get_Element()) cout<<"Error\n";
	else cout<<"Right\n";
	//stack.Show();
	delete []S;
	system("pause");
	return 0;
}
