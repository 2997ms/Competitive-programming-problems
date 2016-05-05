#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

const int MAX = 100005;
int edge[1005][1005];
int vist[1005],vist2[1005],minidis1[1005][1005],minidis2[1005][1005];
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
				minidis1[i][j]=0;
				minidis2[i][j]=0;
			}
			else
			{
				edge[i][j]=-1;
				minidis1[i][j]=MAX;
				minidis2[i][j]=MAX;
			}
		}
	}
	for(i=1;i<=N;i++)
	{
		vist[i]=0;
		vist2[i]=0;
	}
}

void dijkstra(int i)
{
	int j,k;
	int position=i;
	int position2=i;

	vist[position]=1;
	vist2[position]=1;
	minidis1[i][position]=0;
	minidis2[position][i]=0;

	for(j=1;j<=N-1;j++)//一共要添加进num-1个点
	{
		for(k=1;k<=N;k++)
		{
			if(vist[k]==0 && edge[position][k]!=-1 && minidis1[i][position]+edge[position][k] < minidis1[i][k])//新填入的点更新minidis
			{
				minidis1[i][k]=minidis1[i][position]+edge[position][k];
			}
			if(vist2[k]==0 && edge[k][position2]!=-1 && minidis2[position2][i]+edge[k][position2] < minidis2[k][i])//新填入的点更新minidis
			{
				 minidis2[k][i]=minidis2[position2][i]+edge[k][position2];
			}
		}
		int min_value=MAX,min_pos=0;
		int min_value2=MAX,min_pos2=0;
		for(k=1;k<=N;k++)
		{
			if(vist[k]==0 && minidis1[i][k]<min_value)//比较出最小的那一个作为新添入的店
			{
				min_value = minidis1[i][k];
				min_pos = k;
			}
			if(vist2[k]==0 && minidis2[k][i]<min_value2)//比较出最小的那一个作为新添入的店
			{
				min_value2 = minidis2[k][i];
				min_pos2 = k;
			}
		}

		vist[min_pos]=1;
		position=min_pos;

		vist2[min_pos2]=1;
		position2=min_pos2;
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
	memset(vist2,0,sizeof(vist2));

	dijkstra(X);
	int ans=-1;
	for(i=1;i<=N;i++)
	{
		if(i==X)continue;
		ans=max(ans,minidis1[X][i]+minidis2[i][X]);
	}

	cout<<ans<<endl;
	return 0;
}
