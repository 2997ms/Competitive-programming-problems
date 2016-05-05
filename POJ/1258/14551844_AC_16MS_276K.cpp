#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int num;
int map[102][102];
int stack[102];
int minidis[102];

int prim()
{
	int i,j,s,result;

	memset(stack,0,sizeof(stack));
	for(i=1;i<=num;i++)
	{
		minidis[i]=100005;
	}

	stack[1]=1;
	minidis[1]=0;
	s=1;
	result=0;

	for(i=1;i<=num-1;i++)
	{
		int min_all=100005;
		int min_temp=0;
		for(j=2;j<=num;j++)
		{
			if(stack[j]==0&&minidis[j]>map[s][j])
			{
				minidis[j]=map[s][j];
			}
			if(stack[j]==0&&minidis[j]<min_all)
			{
				min_temp=j;
				min_all=minidis[j];
			}
		}
		s=min_temp;
		stack[s]=1;
		result += min_all;
	}
	return result;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int i,j;

	while(cin>>num)
	{
		for(i=1;i<=num;i++)
		{
			for(j=1;j<=num;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		cout<<prim()<<endl;
	}
	return 0;
}
