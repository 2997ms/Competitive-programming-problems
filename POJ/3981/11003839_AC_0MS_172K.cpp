#include <iostream>
using namespace std;

int main()
{
	char a[1005];
	while(gets(a))
	{
		int len=strlen(a);
		int count;
		for(count=2;count<len;count++)
		{
			if(a[count-2]=='y'&&a[count-1]=='o'&&a[count]=='u')
			{
				a[count-2]='w';
				a[count-1]='e';
				a[count]='\n';
			}
		}
		for(count=0;count<len;count++)
		{
			if(a[count]!='\n')
				cout<<a[count];
		}
		cout<<endl;
	}
	return 0;
}