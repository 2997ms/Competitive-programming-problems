#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int num;
int dis[105][105];
int dis_max[105];

void init()
{
	int i,j;
	for(i=1;i<=num;i++)
	{
		for(j=1;j<=num;j++)
		{
			if(i==j)
			{
				dis[i][j]=0;
			}
			else
			{
				dis[i][j]=1005;
			}
		}
	}
}
int main()
{
	int i,j,k,i_num,x,y;
	cin>>num>>x>>y;

	init();
	for(i=1;i<=num;i++)
	{
		cin>>i_num;
		int h;
		for(j=1;j<=i_num;j++)
		{
			cin>>h;
			dis[i][h]=0;
		}
	}
	for(k=1;k<=num;k++)
	{
		for(i=1;i<=num;i++)
		{
			for(j=1;j<=num;j++)
			{
				if(dis[i][k]+dis[k][j]<dis[i][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j]+1;
				}
			}
		}
	}
	if(dis[x][y]>=1000)
		cout<<-1<<endl;
	else
		cout<<dis[x][y]<<endl;
	return 0;
}