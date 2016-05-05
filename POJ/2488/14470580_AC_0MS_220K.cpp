#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

struct struct_a{
	int x;
	int y;
}path[900];

int Test,i,p,q,m,n,flag,num;
int move_x[10]={-1,1,-2,2,-2,2,-1,1};//改成字典顺序
int move_y[10]={-2,-2,-1,-1,1,1,2,2};

int color[30][30];

int dfs(int a,int b,int step)
{
	if(flag==1)
		return 1;
	int k,temp_x,temp_y;
	if(step==q*p)
	{
		flag=1;
		return 1;
	}
	for(k=0;k<8;k++)
	{
		temp_x = a + move_x[k];
		temp_y = b + move_y[k];

		if(temp_x>=1 && temp_x<=p && temp_y>=1 && temp_y<=q && color[temp_x][temp_y]==0)
		{
			color[temp_x][temp_y] = color[a][b]+1;
			path[step].x=temp_x;
			path[step].y=temp_y;
			dfs(temp_x,temp_y,step+1);
			if(flag)
				return 1;
		}
	}
	color[a][b]=0;
	return 0;
}

int main()
{
	cin>>Test;

	for(i=1;i<=Test;i++)
	{
		cin>>p>>q;
		cout<<"Scenario #"<<i<<":"<<endl;

		flag=0;
		memset(color,0,sizeof(color));
		color[1][1]=1;
		path[0].x=1;
		path[0].y=1;

		dfs(1,1,1);

		if(flag==1)
		{
			int v;
			for(v=0;v<p*q;v++)
			{
				char temp_c=path[v].y-1+'A';
				cout<<temp_c<<path[v].x;
			}
			cout<<endl;
		}
		else
			cout<<"impossible"<<endl;
		cout<<endl;
	}

	return 0;
}
