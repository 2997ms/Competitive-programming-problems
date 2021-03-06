#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int MAX;
int edge[1005][1005];
int vist[1005],level[1005],minidis[1005],value[1005];
int level_diff,good_num;

void init()
{
	int i,j;

	for(i=1;i<=good_num;i++)
	{
		for(j=1;j<=good_num;j++)
		{
			if(j==i)
			{
				edge[i][j]=0;
			}
			else
			{
				edge[i][j]=-1;
			}
		}
		vist[i]=0;
	}
}
void init2()
{
	int i;
	for(i=1;i<=good_num;i++)
	{
		minidis[i]=MAX;
	}
}

void dijkstra(int i)
{
	int j,k;
	int position=i;

	vist[position]=1;
	minidis[position]=0;

	for(j=1;j<=good_num-1;j++)//一共要添加进num-1个点
	{
		for(k=1;k<=good_num;k++)
		{
			if(vist[k]==0 && abs(level[i]-level[k])<=level_diff && edge[position][k]!=-1 && minidis[position]+edge[position][k] < minidis[k])//新填入的点更新minidis
			{
				minidis[k]=minidis[position]+edge[position][k];
			}
		}
		int min_value=MAX,min_pos=0;
		for(k=1;k<=good_num;k++)
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
	int i,j,replace;

	cin>>level_diff>>good_num;
	init();
	for(i=1;i<=good_num;i++)
	{
		cin>>value[i]>>level[i]>>replace;
		int temp,temp_prefrence;
		for(j=1;j<=replace;j++)
		{
			cin>>temp>>temp_prefrence;
			edge[i][temp]=temp_prefrence;
		}
	}
	MAX=value[1];
	init2();

	memset(vist,0,sizeof(vist));

	dijkstra(1);
	int ans=MAX;
	
	for(i=1;i<=good_num;i++)
	{
		ans=min(ans,minidis[i]+value[i]);
	}

	cout<<ans<<endl;
	return 0;
}
