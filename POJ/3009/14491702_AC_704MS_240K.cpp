#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#define up 0
#define down 1
#define left 2
#define right 3

int value[25][25];
int row,col,flag,tui_x,tui_y,result,result_zuizhong;

bool can_tui(int x_r,int y_r,int dir)
{
	if(dir==up||dir==down)
	{
		int i,j;
		if(dir==up)
		{
			if(value[x_r-1][y_r]==1)
				return false;
			for(i=1;i<x_r;i++)
			{
				if(value[i][y_r])
					return true;
			}
			return false;
		}
		else
		{
			if(value[x_r+1][y_r]==1)
				return false;
			for(i=x_r+1;i<=row;i++)
			{
				if(value[i][y_r])
					return true;
			}
			return false;
		}
	}
	else
	{
		int i,j;
		if(dir==left)
		{
			if(value[x_r][y_r-1]==1)
				return false;
			for(i=1;i<y_r;i++)
			{
				if(value[x_r][i])
					return true;
			}
			return false;
		}
		else
		{
			if(value[x_r][y_r+1]==1)
				return false;
			for(i=y_r+1;i<=col;i++)
			{
				if(value[x_r][i])
					return true;
			}
			return false;
		}
	}
}

void tui(int x_r,int y_r,int dir)
{
	int i,j;
	if(dir==up)
	{
		for(i=x_r-1;i>=1;i--)
		{
			if(value[i][y_r]==1)
			{
				tui_x=i+1;
				tui_y=y_r;
				return;
			}
			if(value[i][y_r]==3)
			{
				tui_x=i;
				tui_y=y_r;
				return;
			}
		}
	}
	else if(dir==down)
	{
		for(i=x_r+1;i<=row;i++)
		{
			if(value[i][y_r]==1)
			{
				tui_x=i-1;
				tui_y=y_r;
				return;
			}
			if(value[i][y_r]==3)
			{
				tui_x=i;
				tui_y=y_r;
				return;
			}
		}
	}
	else if(dir==left)
	{
		for(i=y_r-1;i>=1;i--)
		{
			if(value[x_r][i]==1)
			{
				tui_x=x_r;
				tui_y=i+1;
				return;
			}
			if(value[x_r][i]==3)
			{
				tui_x=x_r;
				tui_y=i;
				return;
			}
		}
	}
	else
	{
		for(i=y_r+1;i<=col;i++)
		{
			if(value[x_r][i]==1)
			{
				tui_x=x_r;
				tui_y=i-1;
				return;
			}
			if(value[x_r][i]==3)
			{
				tui_x=x_r;
				tui_y=i;
				return;
			}
		}
	}
}

void dfs(int x_r,int y_r,int step,int dir)
{
	if(step>11)
		return;
	if(value[x_r][y_r]==3)
	{
		flag=1;
		result=min(result,step);
		return;
	}
	if(dir==up)
	{
		value[x_r-1][y_r]=0;
	}
	else if(dir==down)
	{
		value[x_r+1][y_r]=0;
	}
	else if(dir==left)
	{
		value[x_r][y_r-1]=0;
	}
	else if(dir==right)
	{
		value[x_r][y_r+1]=0;
	}

	if(can_tui(x_r,y_r,up))
	{
		tui(x_r,y_r,up);
		int temp_x=tui_x;
		int temp_y=tui_y;
		dfs(temp_x,temp_y,step+1,up);
	}
	if(can_tui(x_r,y_r,left))
	{
		tui(x_r,y_r,left);
		int temp_x=tui_x;
		int temp_y=tui_y;
		dfs(temp_x,temp_y,step+1,left);
	}
	if(can_tui(x_r,y_r,down))
	{
		tui(x_r,y_r,down);
		int temp_x=tui_x;
		int temp_y=tui_y;
		dfs(temp_x,temp_y,step+1,down);
	}
	if(can_tui(x_r,y_r,right))
	{
		tui(x_r,y_r,right);
		int temp_x=tui_x;
		int temp_y=tui_y;
		dfs(temp_x,temp_y,step+1,right);
	}

	if(dir==up)
	{
		value[x_r-1][y_r]=1;
	}
	else if(dir==down)
	{
		value[x_r+1][y_r]=1;
	}
	else if(dir==left)
	{
		value[x_r][y_r-1]=1;
	}
	else if(dir==right)
	{
		value[x_r][y_r+1]=1;
	}
}

void solve()
{	
	int i,j;
	for(i=row;i>=1;i--)
	{
		for(j=col;j>=1;j--)
		{
			if(value[i][j]==2)
			{
				value[i][j]=0;
				result=11;
				dfs(i,j,0,-1);
				if(flag)
				{
					result_zuizhong =min(result,result_zuizhong);
				}
				return;
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
		flag=0;
		result_zuizhong=11;
		memset(value,0,sizeof(value));

		for(i=1;i<=row;i++)
		{
			for(j=1;j<=col;j++)
			{
				cin>>value[i][j];
			}
		}
		solve();
		if(result_zuizhong==11)
			cout<<-1<<endl;
		else
			cout<<result_zuizhong<<endl;

	}
	return 0;
}
