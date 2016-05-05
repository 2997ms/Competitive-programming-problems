#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#pragma warning(disable:4996)
using namespace std;

int row,col,num;
char value[250][250];
int dis[2502][2502];
int visit[2502][2502];
int stack[2502];
int minidis[2502];

map <int,int> hash1;

void dfs(int i,int j,int x,int y,int step)
{
	if(step>=row*col)
		return;

	if(value[x][y]=='A'||value[x][y]=='S')
	{
		dis[hash1[i*100+j]][hash1[x*100+y]]=min(dis[hash1[i*100+j]][hash1[x*100+y]],step);
	}
	visit[x][y]=1;

	if(x<row && value[x+1][y]!='#' && visit[x+1][y]==0)
	{
		dfs(i,j,x+1,y,step+1);
	}
	if(y<col && value[x][y+1]!='#' && visit[x][y+1]==0)
	{
		dfs(i,j,x,y+1,step+1);
	}
	if(x>1 && value[x-1][y]!='#' && visit[x-1][y]==0)
	{
		dfs(i,j,x-1,y,step+1);
	}
	if(y>1 && value[x][y-1]!='#' && visit[x][y-1]==0)
	{
		dfs(i,j,x,y-1,step+1);
	}

	visit[x][y]=0;
}
int prim()
{
	int i,j,s,result;

	memset(stack,0,sizeof(stack));
	for(i=1;i<=num;i++)
	{
		minidis[i]=2502;
	}

	stack[1]=1;
	minidis[1]=0;
	s=1;
	result=0;

	for(i=1;i<=num-1;i++)
	{
		int min_all=2502;
		int min_temp=0;
		for(j=2;j<=num;j++)
		{
			if(stack[j]==0&&minidis[j]>dis[s][j])
			{
				minidis[j]=dis[s][j];
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
	int Test,i,j,map_num;
	scanf("%d",&Test);

	while(Test--)
	{
		scanf("%d%d",&row,&col);

		num=0;
		memset(visit,0,sizeof(visit));
		memset(value,0,sizeof(value));
		hash1.clear();
		map_num=0;

		for(i=1;i<=row*col;i++)
		{
			for(j=1;j<=row*col;j++)
			{
				dis[i][j]=row*col+1;
			}
		}

		for(i=1;i<=row;i++)
		{
			gets(value[i]+1);
			for(j=1;j<=col;j++)
			{
				if(value[i][j]=='A'||value[i][j]=='S')
				{
					map_num++;
					hash1[i*100+j]=map_num;
					num++;
				}
			}
		}

		for(i=1;i<=row;i++)
		{
			for(j=1;j<=col;j++)
			{
				if(value[i][j]=='A'||value[i][j]=='S')
				{
					dfs(i,j,i,j,0);
				}
			}
		}
		printf("%d\n",prim());
	}
	return 0;
}
