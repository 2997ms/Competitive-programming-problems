#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

vector<string>dic;
vector<string>modi;

void solve(string test)
{
	modi.clear();
	int i;
	int len=dic.size();

	for(i=0;i<len;i++)
	{
		if(dic[i]==test)
		{
			cout<<test<<" is correct"<<endl;
			return;
		}
		if(dic[i].length()==test.length())
		{
			int result=0,j;
			for(j=0;j<test.length();j++)
			{
				if(dic[i][j]==test[j])
					result++;
			}
			if(result==test.length()-1)
			{
				modi.push_back(dic[i]);
			}
		}
		else if(dic[i].length()+1==test.length())
		{
			int result=0,j=0,k=0;
			for(j=0;j<dic[i].length()&&k<test.length();k++)
			{
				if(dic[i][j]==test[k])
				{
					result++;
					j++;
				}
			}
			if(result==dic[i].length())
			{
				modi.push_back(dic[i]);
			}
		}
		else if(dic[i].length()-1==test.length())
		{
			int result=0,j=0,k=0;
			for(k=0;k<test.length()&&j<dic[i].length();j++)
			{
				if(dic[i][j]==test[k])
				{
					result++;
					k++;
				}
			}
			if(result==test.length())
			{
				modi.push_back(dic[i]);
			}
		}
	}

	if(modi.size())
	{
		cout<<test<<":";
		for(i=0;i<modi.size();i++)
		{
			cout<<" "<<modi[i];
		}
		cout<<endl;
	}
	else
		cout<<test<<":"<<endl;
}

int main()
{
	string test;
	dic.clear();
	while(cin>>test)
	{
		if(test=="#")
			break;
		dic.push_back(test);
	}
	while(cin>>test)
	{
		if(test=="#")
			break;
		solve(test);
	}
	return 0;
}
