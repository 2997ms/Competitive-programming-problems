#include <iostream>
using namespace std;

int main()
{
	char a[30];

	while(scanf("%s",a)!=EOF)
	{
		int len=strlen(a);
		int count,pre=0;
		for(count=0;count<len;count++)
		{
			if(a[count]=='B'||a[count]=='F'||a[count]=='P'||a[count]=='V')
			{
				if(pre!=1)
				{
					pre=1;
					cout<<pre;
				}
			}
			else if(a[count]=='C'||a[count]=='G'||a[count]=='J'||a[count]=='K'||a[count]=='Q'||a[count]=='S'||a[count]=='X'||a[count]=='Z')
			{
				if(pre!=2)
				{
					pre=2;
					cout<<pre;
				}
			}
			else if(a[count]=='D'||a[count]=='T')
			{
				if(pre!=3)
				{
					pre=3;
					cout<<pre;
				}
			}
			else if(a[count]=='L')
			{
				if(pre!=4)
				{
					pre=4;
					cout<<pre;
				}
			}
			else if(a[count]=='M'||a[count]=='N')
			{
				if(pre!=5)
				{
					pre=5;
					cout<<pre;
				}
			}
			else if(a[count]=='R')
			{
				if(pre!=6)
				{
					pre=6;
					cout<<pre;
				}
			}
			else 
				pre=0;
		}
		cout<<endl;
	}
	return 0;
}

