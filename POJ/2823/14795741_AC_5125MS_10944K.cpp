#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#define maxn 1000005
int A[maxn];//存储数据
int Q[maxn];//队列
int P[maxn];//存储A[i]中的下标i
int Min[maxn];//输出最小
int Max[maxn];//输出最大
int n,k,num;

void get_min()
{
	int i;
	int head=1,tail=0;
	num=0;
	for(i=0;i<k-1;i++)
	{
		while(head<=tail && Q[tail]>=A[i])
		{
			tail--;
		}
		Q[++tail]=A[i];
		P[tail]=i;
		//while(head<i-k+1&&head<=tail)
		//	head++;
	}
	for(;i<n;i++)
	{
		while(head<=tail &&Q[tail]>=A[i])
		{
			tail--;
		}
		Q[++tail]=A[i];
		P[tail]=i;
		while(P[head]<i-k+1&&head<=tail)
			head++;
		Min[num++]=Q[head];
	}
}

void get_max()
{
	int i;
	int head=1,tail=0;
	num=0;
	for(i=0;i<k-1;i++)
	{
		while(head<=tail && Q[tail]<= A[i])
		{
			tail--;
		}
		Q[++tail]=A[i];
		P[tail]=i;
		//while(head<i-k+1&&head<=tail)
		//	head++;
	}
	for(;i<n;i++)
	{
		while(head<=tail &&Q[tail] <= A[i])
		{
			tail--;
		}
		Q[++tail]=A[i];
		P[tail]=i;
		while(P[head]<i-k+1&&head<=tail)
			head++;
		Max[num++]=Q[head];
	}
}

int main()
{	
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int i;
	scanf("%d%d",&n,&k);

	for(i=0;i<n;i++)
	{
		scanf("%d",A+i);
	}
	get_min();
	for(i=0;i<num;i++)
	{
		if(i==0)
		{
			printf("%d",Min[i]);
		}
		else
		{
			printf(" %d",Min[i]);
		}
	}
	printf("\n");

	get_max();
	for(i=0;i<num;i++)
	{
		if(i==0)
		{
			printf("%d",Max[i]);
		}
		else
		{
			printf(" %d",Max[i]);
		}
	}
	printf("\n");
	//system("pause");
	return 0;
}
