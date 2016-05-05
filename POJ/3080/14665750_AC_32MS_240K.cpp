#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

const int N=12;

int num;
string s[N];

void work()
{
	int start,i,len;
	string ans="";

	for(len=60;len>=3;len--)
	{
		for(start=0;start+len<=60;start++)
		{
			string test=s[0].substr(start,len);
			bool flag=true;

			for(i=1;i<=num-1;i++)
			{
				if(s[i].find(test)==string::npos)
				{
					flag=false;
					break;
				}
			}
			if(flag)
			{
				if(test.length()==ans.length()&&strcmp(ans.c_str(),test.c_str())>0)
				{
					ans=test;
				}
				else if(test.length()>ans.length())
				{
					ans=test;
				}
			}
		}
	}
	if(ans.length()<3)
		cout<<"no significant commonalities"<<endl;
	else
		cout<<ans<<endl;
}

int main()
{
	int Test,i;
	cin>>Test;

	while(Test--)
	{
		cin>>num;

		for(i=0;i<num;i++)
		{
			cin>>s[i];
		}
		work();
	}
	return 0;
}
