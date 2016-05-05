#include <iostream>
#include <string>
using namespace std;

int main()
{
	string start,end;
	char ch[40],s[200];
	int count,len;
	ch[0]='V'-1;
	for(count=1;count<=5;count++)
	{
		ch[count]=ch[count-1]+1;
	}
	ch[6]='A';
	for(count=7;count<=31;count++)
	{
		ch[count]=ch[count-1]+1;
	}
	while(cin>>start&&start!="ENDOFINPUT")
	{
		getchar();
		gets(s);
		len=strlen(s);
		for(count=0;count<len;count++)
		{
			if(s[count]>='A'&&s[count]<='Z')
			{
			  printf("%c",ch[s[count]-'A'+1]);
			}
			else
			{
				printf("%c",s[count]);
			}
		}
		cout<<endl;
		cin>>end;
	}
	return 0;
}
