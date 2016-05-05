#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

string s;

void solve()
{
	int i,j;
	int len=s.length();
	
	for(i=0;i<len;i++)
	{
		int result=1;
		for(j=i+1;j<len;j++)
		{
			if(s[j]==s[i])
			{
				result++;
			}
			else
			{
				break;
			}
		}
		cout<<result<<s[i];
		i=i+result-1;
	}
	cout<<endl;
}

int main()
{

	int Test;
	cin>>Test;
	
	while(Test--)
	{
		cin>>s;
		solve();
	}
	return 0;
}
