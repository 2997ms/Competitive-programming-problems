#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int num;
char truck[2005][10];
int map[2005][2005];
int stack[2005];
int minidis[2005];

int dis(int x,int y)
{
	int i,result=0;
	for(i=0;i<7;i++)
	{
		if(truck[x][i]!=truck[y][i])
		{
			result++;
		}
	}
	return result;
}

int prim()
{
	int i,j,s,result;

	memset(stack,0,sizeof(stack));
	for(i=1;i<=num;i++)
	{
		minidis[i]=15;
	}

	stack[1]=1;
	minidis[1]=0;
	s=1;
	result=0;
	for(i=1;i<=num-1;i++)
	{
		int min_all=15;
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
		if(num==0)
			break;
		for(i=1;i<=num;i++)
		{
			scanf("%s",truck[i]);
		}
		for(i=1;i<=num;i++)
		{
			for(j=i+1;j<=num;j++)
			{
				map[i][j]=map[j][i]=dis(i,j);
			}
		}
		cout<<"The highest possible quality is 1/"<<prim()<<"."<<endl;
	}

	return 0;
}
