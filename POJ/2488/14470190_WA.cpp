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
int move_x[8]={-1,1,-2,2,-2,2,-1,1};//改成字典顺序
int move_y[8]={-2,-2,-1,-1,1,1,2,2};

int color[30][30];

void dfs(int a,int b)
{
	int k,temp_x,temp_y;
	for(k=0;k<8;k++)
	{
		temp_x = a + move_x[k];
		temp_y = b + move_y[k];

		if(temp_x>=1 && temp_x<=p && temp_y>=1 && temp_y<=q && color[temp_x][temp_y]==0)
		{
			color[temp_x][temp_y] = color[a][b]+1;
			path[num].x=temp_x;
			path[num].y=temp_y;
			num++;
			dfs(temp_x,temp_y);
		}
	}
}
bool check()
{
	if(num==p*q+1)
		return true;
	else 
		return false;
}

int main()
{
	cin>>Test;

	for(i=1;i<=Test;i++)
	{
		cin>>p>>q;
		cout<<"Scenario #"<<i<<":"<<endl;

		flag=0;
		for(n=1;n<=q;n++)
		{
			for(m=1;m<=p;m++)
			{
				memset(color,0,sizeof(color));
				num=2;
				if(flag==0)
				{
					color[m][n]=1;
					path[1].x=m;
					path[1].y=n;

					dfs(m,n);
					if(check())
					{
						flag=1;
					}
				}
			}
		}
		if(flag==1)
		{
			int v;
			for(v=1;v<=p*q;v++)
			{
				char temp_c=path[v].y-1+'A';
				cout<<temp_c<<path[v].x;
			}
			cout<<endl;
		}
		else
			cout<<"impossible"<<endl;
	}

	return 0;
}
