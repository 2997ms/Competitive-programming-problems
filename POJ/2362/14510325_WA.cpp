#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int num_s,flag,sum;
int stick[25];
bool visit[25];

bool dfs(int num,int length,int stick_st,int * stick,bool *visit)
{
	if(num==4)
		return true;
	int i;
	for(i=stick_st;i<=num_s;i++)
	{
		if(visit[i])continue;

		visit[i]=true;
		if(length+stick[i]<(sum/4))
		{
			if(dfs(num,length+stick[i],i+1,stick,visit))
			{
				return true;
			}
		}
		else if(length+stick[i]==(sum/4))
		{
			if(dfs(num+1,0,1,stick,visit))
			{
				return true;
			}
		}
		visit[i]=false;
	}
	return false;
}

bool cmp(const int a,const int b)
{
	return a>b;
}

int main()
{
	int Test,i;
	cin>>Test;

	while(Test--)
	{
		cin>>num_s;
		sum=0;
		flag=0;
		for(i=1;i<=num_s;i++)
		{
			cin>>stick[i];
			visit[i]=false;
			sum += stick[i];
		}
		if(num_s<4||sum%4)//!!!!num小于4的情况
		{
			cout<<"NO"<<endl;
		}
		else
		{
			sort(stick+1,stick+1+num_s,cmp);
			if(stick[1]>sum/4)
				cout<<"NO"<<endl;
			else
			{
				if(dfs(1,0,1,stick,visit))//第一个数代表当前完成第几根木棒了
				                              //第二个数代表当前要完成的长度
				                              //第三个数代表木棒从第几个开始找起的
				{
					cout<<"YES"<<endl;
				}
				else
				{
					cout<<"NO"<<endl;
				}
			}
		}
	}
	return 0;
}

