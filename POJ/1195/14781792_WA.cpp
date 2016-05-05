#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#define MY_MAX 1100
int C[MY_MAX][MY_MAX];
int s;

int lowbit(int x)
{
	return x&(-x);
}

void Add(int y,int x,int a)
{
	while(y<=s)
	{
		int temp=x;
		while(temp<=s)
		{
			C[y][temp]+=a;
			temp +=lowbit(temp);
		}
		y +=lowbit(y);
	}
}

int QuerySum(int y,int x)
{
	int nSum=0;
	while(y>0)
	{
		int temp=x;
		while(temp>0)
		{
			nSum += C[y][temp];
			temp -= lowbit(temp);
		}
		y -=lowbit(y);
	}
	return nSum;
}

int main()
{	
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	int oper;
	int x,y,a,le,b,r,t;

	while(true)
	{
		scanf("%d",&oper);
		if(oper==0)
		{
			scanf("%d",&s);
			memset(C,0,sizeof(C));
		}
		else if(oper==1)
		{
			scanf("%d%d%d",&x,&y,&a);
			Add(x+1,y+1,a);
		}
		else if(oper==2)
		{
			scanf("%d%d%d%d",&le,&b,&r,&t);
			printf("%d\n",QuerySum(r+1,t+1) + QuerySum(le+1,b+1)- QuerySum(le,t+1) - QuerySum(r,b+1));
		}
		else if(oper==3)
		{
			break;
		}
	}
	//system("pause");
	return 0;
}
