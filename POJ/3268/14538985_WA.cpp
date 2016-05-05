#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

const int MAX=0xfffffff;
int edge[1005][1005];
int vist[1005],minidis[1005][1005];
int N,M,X;

void init()
{
	int i,j;

	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			if(j==i)
			{
				edge[i][j]=0;
				minidis[i][j]=0;
			}
			else
			{
				edge[i][j]=-1;
				minidis[i][j]=MAX;
			}
		}
	}
	for(i=1;i<=N;i++)
	{
		vist[i]=0;
	}
}

void dijkstra(int i)
{
	int j,k;
	int position=i;

	vist[position]=1;
	minidis[i][position]=0;

	for(j=1;j<=N-1;j++)//一共要添加进num-1个点
	{
		for(k=1;k<=N;k++)
		{
			if(vist[k]==0 && edge[position][k]!=-1 && minidis[i][position]+edge[position][k] < minidis[i][k])//新填入的点更新minidis
			{
				minidis[i][k]=minidis[i][position]+edge[position][k];
			}
		}
		int min_value=MAX,min_pos=0;
		for(k=1;k<=N;k++)
		{
			if(vist[k]==0 && minidis[i][k]<min_value)//比较出最小的那一个作为新添入的店
			{
				min_value = minidis[i][k];
				min_pos = k;
			}
		}
		vist[min_pos]=1;
		position=min_pos;
	}

}

int main()
{
	int i;
	cin>>N>>M>>X;
	init();

	int temp1,temp2,temp3;
	for(i=1;i<=M;i++)
	{
		cin>>temp1>>temp2>>temp3;
		edge[temp1][temp2]=temp3;
	}

	memset(vist,0,sizeof(vist));
	dijkstra(N);
	
	memset(vist,0,sizeof(vist));
	dijkstra(X);

	cout<<minidis[N][X]+minidis[X][N]<<endl;
	return 0;
}
