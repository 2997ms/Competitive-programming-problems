#include <iostream>
#include <string>
using namespace std;

int main()
{
	char s[100];
	int count;
	while(gets(s)&&(s[0]!='#'||s[1]!='\0'))
	{
		for(count=0;s[count];count++)
		{
		  if(s[count]==' ')
			  cout<<"%20";
		  else if(s[count]=='!')
			  cout<<"%21";
		  else if(s[count]=='$')
			  cout<<"%24";
		  else if(s[count]=='%')
			  cout<<"%25";
		  else if(s[count]=='(')
			  cout<<"%28";
		  else if(s[count]==')')
			  cout<<"%29";
		  else if(s[count]=='*')
			  cout<<"%2a";
		  else
			  cout<<s[count];
		}
		cout<<endl;
	}
	return 0;
}

