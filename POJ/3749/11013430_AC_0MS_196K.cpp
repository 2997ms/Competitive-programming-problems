#include <iostream>
#include <string>
using namespace std;

int main()
{
	string start,end;
	char oper[240],A[26]={'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'};
	while(cin>>start&&start!="ENDOFINPUT")
	{
		getchar();
		gets(oper);
		int len=strlen(oper);
		for(int count=0;count<len;count++)
		{
			if(oper[count]>='A'&&oper[count]<='Z')
			{
				cout<<A[oper[count]-'A'];
			}
			else
				cout<<oper[count];
		}
		cout<<endl;
	    cin>>end;
	}
	return 0;
}
