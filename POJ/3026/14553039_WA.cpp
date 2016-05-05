#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

int row,col,num;
char value[250][250];
int dis[250][250];
int visit[250][250];
int visit2[250][250];
int stack[250];
int minidis[250];
vector<int>x;
vector<int>y;

map <int,int> hash1;

void bfs(int i,int j)
{
	queue<int>x_x;
	queue<int>y_y;
	queue<int>cishu;

	while(x_x.size())x_x.pop();
	while(y_y.size())y_y.pop();
	while(cishu.size())cishu.pop();

	x_x.push(i);
	y_y.push(j);
	cishu.push(0);

	int temp_x,temp_y,temp_cishu;
	
	memset(visit,0,sizeof(visit));
	visit[i][j]=1;
	dis[hash1[i*100+j]][hash1[i*100+j]]=0;

	while(x_x.size())
	{
		temp_x=x_x.front();
		temp_y=y_y.front();
		temp_cishu=cishu.front();

		x_x.pop();
		y_y.pop();
		cishu.pop();

		if(value[temp_x][temp_y]=='S'||value[temp_x][temp_y]=='A')
		{
			dis[hash1[temp_x*100+temp_y]][hash1[i*100+j]]=dis[hash1[i*100+j]][hash1[temp_x*100+temp_y]]=temp_cishu;
		}

		if(value[temp_x+1][temp_y]!='#' && visit[temp_x+1][temp_y]==0&&temp_x<row)
		{
			visit[temp_x+1][temp_y]=1;

			x_x.push(temp_x+1);
			y_y.push(temp_y);
			cishu.push(temp_cishu+1);
		}
		if(value[temp_x][temp_y+1]!='#' && visit[temp_x][temp_y+1]==0&&temp_y<col)
		{
			visit[temp_x][temp_y+1]=1;

			x_x.push(temp_x);
			y_y.push(temp_y+1);
			cishu.push(temp_cishu+1);
		}
		if( value[temp_x-1][temp_y]!='#' && visit[temp_x-1][temp_y]==0 && temp_x>1)
		{
			visit[temp_x-1][temp_y]=1;

			x_x.push(temp_x-1);
			y_y.push(temp_y);
			cishu.push(temp_cishu+1);
		}
		if(value[temp_x][temp_y-1]!='#' && visit[temp_x][temp_y-1]==0&&temp_y>1)
		{
			visit[temp_x][temp_y-1]=1;

			x_x.push(temp_x);
			y_y.push(temp_y-1);
			cishu.push(temp_cishu+1);
		}
	}
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
		hash1.clear();
		x.clear();
		y.clear();
		map_num=0;
		//gets(value[0]+1);
		for(i=1;i<=row;i++)
		{
			gets(value[i]+1);
			//if(i==1||i==row)continue;
			for(j=2;j<=col;j++)
			{
				if(value[i][j]=='A'||value[i][j]=='S')
				{
					map_num++;
					hash1[i*100+j]=map_num;
					x.push_back(i);
					y.push_back(j);
					num++;
				}
			}
		}
		for(i=0;i<num;i++)
		{
			bfs(x[i],y[i]);
		}
		printf("%d\n",prim());
	}
	return 0;
}
