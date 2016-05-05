#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int row,col,sum;
char value[30][30];
int flag[30][30];

void dfs(int x,int y)
{
	flag[x][y]=1;
	
	if(x>1&&flag[x-1][y]==0&&value[x-1][y]=='.')
	{
		dfs(x-1,y);
	}
	if(y>1&&flag[x][y-1]==0&&value[x][y-1]=='.')
	{
		dfs(x,y-1);
	}
	if(x<row&&flag[x+1][y]==0&&value[x+1][y]=='.')
	{
		dfs(x+1,y);
	}
	if(y<col&&flag[x][y+1]==0&&value[x][y+1]=='.')
	{
		dfs(x,y+1);
	}
}

void solve1()
{
	int i,j;
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			if(value[i][j]=='@')
			{
				dfs(i,j);
				return;
			}
		}
	}
}

void solve2()
{
	int i,j;
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			if(flag[i][j])
			{
				sum++;
			}
		}
	}
}

int main()
{
	int i,j;
	while(cin>>col>>row)
	{
		if(col+row==0)
			break;
		memset(flag,0,sizeof(flag));
		sum=0;
		for(i=1;i<=row;i++)
		{
			cin>>value[i]+1;
		}
		solve1();
		solve2();

		cout<<sum<<endl;
	}

	return 0;
}
