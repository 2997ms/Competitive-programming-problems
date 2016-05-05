#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int pend_flag,flag;

void cal(string s)
{
	if(s.length() == 0)
	{
		return;
	}
	else 
	{
		int len=s.length();
		if(s[len-1]>='p' && s[len-1]<='z')
		{
			flag++;
			cal(s.substr(0,len-1));
		}
		else if(s[len-1]=='N')
		{
			cal(s.substr(0,len-1));
		}
		else if(s[len-1]=='C'||s[len-1]=='D'||s[len-1]=='E'||s[len-1]=='I')
		{
			flag--;
			cal(s.substr(0,len-1));
		}
		else
		{
			flag=0;
			return;
		}
	}
}

int main()
{
	string s;
	while(cin>>s)
	{
		flag=0;

		cal(s);

		if(flag==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}