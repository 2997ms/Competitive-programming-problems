#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

const int MAX=0xfffffff;
int edge[105][105];
int vist[105],minidis[105];
int num;

void init()
{
	int i,j;
	memset(vist,0,sizeof(vist));
	
	for(i=1;i<=num;i++)
	{
		for(j=1;j<=num;j++)
		{
			if(j==i)
				edge[i][j]=0;
			else
				edge[i][j]=-1;
		}
	}
	for(i=1;i<=num;i++)
	{
		vist[i]=0;
		minidis[i]=MAX;
	}
}

void dijkstra(int i)
{
	int j,k;
	int position=i;
	
	vist[position]=1;
	minidis[position]=0;

	for(j=1;j<=num-1;j++)//一共要添加进num-1个点
	{
		for(k=1;k<=num;k++)
		{
			if(vist[k]==0 && edge[position][k]!=-1 && minidis[position]+edge[position][k] < minidis[k])//新填入的点更新minidis
			{
				minidis[k]=minidis[position]+edge[position][k];
			}
		}
		int min_value=MAX,min_pos;
		for(k=1;k<=num;k++)
		{
			if(vist[k]==0 && minidis[k]<min_value)//比较出最小的那一个作为新添入的店
			{
				min_value = minidis[k];
				min_pos = k;
			}
		}
		vist[min_pos]=1;
		position=min_pos;
	}

}

int main()
{
	int i,j;
	char temp[30];
	
	cin>>num;
	init();

	for(i=2;i<=num;i++)
	{
		for(j=1;j<i;j++)
		{
			cin>>temp;
			if(strcmp(temp,"x"))
				edge[j][i]=edge[i][j]=atoi(temp);
		}
	}
	dijkstra(1);
	
	int max_value = -1;
	for(i=1;i<=num;i++)
	{
		if(minidis[i]>max_value)
		{
			max_value=minidis[i];
		}
	}
	cout<<max_value<<endl;

	return 0;
}
