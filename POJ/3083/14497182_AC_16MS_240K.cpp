#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define up 1
#define down 2
#define left 3
#define right 4

int row,col;
char value[50][50];
int bushu[50][50];

int dfs_left(int i,int j,int dir)
{
	memset(bushu,0,sizeof(bushu));
	queue<int>x;
	queue<int>y;
	queue<int>z;

	x.push(i);
	y.push(j);
	z.push(dir);

	int temp1,temp2,temp3;
	while(x.size())
	{
		i=x.front();
		j=y.front();
		temp3=z.front();

		x.pop();
		y.pop();
		z.pop();

		if(temp3==up)
		{
			if(value[i][j-1]=='E')
			{
				return bushu[i][j]+1;
			}
			if(value[i][j-1]=='.')
			{			
				x.push(i);
				y.push(j-1);
				z.push(left);
				bushu[i][j-1]=bushu[i][j]+1;

			}
			else if(value[i][j-1]=='#')
			{
				if(value[i-1][j]=='E')
				{
					return bushu[i][j]+1;
				}
				if(value[i-1][j]=='.')
				{
					x.push(i-1);
					y.push(j);
					z.push(up);
					bushu[i-1][j]=bushu[i][j]+1;
				}
				else if(value[i-1][j]=='#')
				{
					if(value[i][j+1]=='E')
						return bushu[i][j]+1;
					if(value[i][j+1]=='.')
					{
						x.push(i);
						y.push(j+1);
						z.push(right);
						bushu[i][j+1]=bushu[i][j]+1;
					}
					else if(value[i][j+1]=='#')
					{
						if(value[i+1][j]=='E')
							return bushu[i][j]+1;
						if(value[i+1][j]=='.')
						{
							x.push(i+1);
							y.push(j);
							z.push(down);
							bushu[i+1][j]=bushu[i][j]+1;
						}
					}
				}
			}

		}
		else if(temp3==down)
		{
			if(value[i][j+1]=='E')
			{
				return bushu[i][j]+1;
			}
			if(value[i][j+1]=='.')
			{			
				x.push(i);
				y.push(j+1);
				z.push(right);
				bushu[i][j+1]=bushu[i][j]+1;

			}
			else if(value[i][j+1]=='#')
			{
				if(value[i+1][j]=='E')
				{
					return bushu[i][j]+1;
				}
				if(value[i+1][j]=='.')
				{
					x.push(i+1);
					y.push(j);
					z.push(down);
					bushu[i+1][j]=bushu[i][j]+1;
				}
				else if(value[i+1][j]=='#')
				{
					if(value[i][j-1]=='E')
						return bushu[i][j]+1;
					if(value[i][j-1]=='.')
					{
						x.push(i);
						y.push(j-1);
						z.push(left);
						bushu[i][j-1]=bushu[i][j]+1;
					}
					else if(value[i][j-1]=='#')
					{
						if(value[i-1][j]=='E')
							return bushu[i][j]+1;
						if(value[i-1][j]=='.')
						{
							x.push(i-1);
							y.push(j);
							z.push(up);
							bushu[i-1][j]=bushu[i][j]+1;
						}
					}
				}
			}
		}
		else if(temp3==left)
		{
			if(value[i+1][j]=='E')
			{
				return bushu[i][j]+1;
			}
			if(value[i+1][j]=='.')
			{			
				x.push(i+1);
				y.push(j);
				z.push(down);
				bushu[i+1][j]=bushu[i][j]+1;

			}
			else if(value[i+1][j]=='#')
			{
				if(value[i][j-1]=='E')
				{
					return bushu[i][j]+1;
				}
				if(value[i][j-1]=='.')
				{
					x.push(i);
					y.push(j-1);
					z.push(left);
					bushu[i][j-1]=bushu[i][j]+1;
				}
				else if(value[i][j-1]=='#')
				{
					if(value[i-1][j]=='E')
						return bushu[i][j]+1;
					if(value[i-1][j]=='.')
					{
						x.push(i-1);
						y.push(j);
						z.push(up);
						bushu[i-1][j]=bushu[i][j]+1;
					}
					else if(value[i-1][j]=='#')
					{
						if(value[i][j+1]=='E')
							return bushu[i][j]+1;
						if(value[i][j+1]=='.')
						{
							x.push(i);
							y.push(j+1);
							z.push(right);
							bushu[i][j+1]=bushu[i][j]+1;
						}
					}
				}
			}
		}
		else if(temp3==right)
		{
			if(value[i-1][j]=='E')
			{
				return bushu[i][j]+1;
			}
			if(value[i-1][j]=='.')
			{			
				x.push(i-1);
				y.push(j);
				z.push(up);
				bushu[i-1][j]=bushu[i][j]+1;

			}
			else if(value[i-1][j]=='#')
			{
				if(value[i][j+1]=='E')
				{
					return bushu[i][j]+1;
				}
				if(value[i][j+1]=='.')
				{
					x.push(i);
					y.push(j+1);
					z.push(right);
					bushu[i][j+1]=bushu[i][j]+1;
				}
				else if(value[i][j+1]=='#')
				{
					if(value[i+1][j]=='E')
						return bushu[i][j]+1;
					if(value[i+1][j]=='.')
					{
						x.push(i+1);
						y.push(j);
						z.push(down);
						bushu[i+1][j]=bushu[i][j]+1;
					}
					else if(value[i+1][j]=='#')
					{
						if(value[i][j-1]=='E')
							return bushu[i][j]+1;
						if(value[i][j-1]=='.')
						{
							x.push(i);
							y.push(j-1);
							z.push(left);
							bushu[i][j-1]=bushu[i][j]+1;
						}
					}
				}
			}
		}
	}
	return 0;
}

int dfs_right(int i,int j,int dir)
{
	memset(bushu,0,sizeof(bushu));
	queue<int>x;
	queue<int>y;
	queue<int>z;

	x.push(i);
	y.push(j);
	z.push(dir);

	int temp1,temp2,temp3;
	while(x.size())
	{
		i=x.front();
		j=y.front();
		temp3=z.front();

		x.pop();
		y.pop();
		z.pop();

		if(temp3==up)
		{
			if(value[i][j+1]=='E')
			{
				return bushu[i][j]+1;
			}
			if(value[i][j+1]=='.')
			{			
				x.push(i);
				y.push(j+1);
				z.push(right);
				bushu[i][j+1]=bushu[i][j]+1;
			}
			else if(value[i][j+1]=='#')
			{
				if(value[i-1][j]=='E')
				{
					return bushu[i][j]+1;
				}
				if(value[i-1][j]=='.')
				{
					x.push(i-1);
					y.push(j);
					z.push(up);
					bushu[i-1][j]=bushu[i][j]+1;
				}
				else if(value[i-1][j]=='#')
				{
					if(value[i][j-1]=='E')
						return bushu[i][j]+1;
					if(value[i][j-1]=='.')
					{
						x.push(i);
						y.push(j-1);
						z.push(left);
						bushu[i][j-1]=bushu[i][j]+1;
					}
					else if(value[i][j-1]=='#')
					{
						if(value[i+1][j]=='E')
							return bushu[i][j]+1;
						if(value[i+1][j]=='.')
						{
							x.push(i+1);
							y.push(j);
							z.push(down);
							bushu[i+1][j]=bushu[i][j]+1;
						}
					}
				}
			}

		}
		else if(temp3==down)
		{
			if(value[i][j-1]=='E')
			{
				return bushu[i][j]+1;
			}
			if(value[i][j-1]=='.')
			{			
				x.push(i);
				y.push(j-1);
				z.push(left);
				bushu[i][j-1]=bushu[i][j]+1;

			}
			else if(value[i][j-1]=='#')
			{
				if(value[i+1][j]=='E')
				{
					return bushu[i][j]+1;
				}
				if(value[i+1][j]=='.')
				{
					x.push(i+1);
					y.push(j);
					z.push(down);
					bushu[i+1][j]=bushu[i][j]+1;
				}
				else if(value[i+1][j]=='#')
				{
					if(value[i][j+1]=='E')
						return bushu[i][j]+1;
					if(value[i][j+1]=='.')
					{
						x.push(i);
						y.push(j+1);
						z.push(right);
						bushu[i][j+1]=bushu[i][j]+1;
					}
					else if(value[i][j+1]=='#')
					{
						if(value[i-1][j]=='E')
							return bushu[i][j]+1;
						if(value[i-1][j]=='.')
						{
							x.push(i-1);
							y.push(j);
							z.push(up);
							bushu[i-1][j]=bushu[i][j]+1;
						}
					}
				}
			}
		}
		else if(temp3==left)
		{
			if(value[i-1][j]=='E')
			{
				return bushu[i][j]+1;
			}
			if(value[i-1][j]=='.')
			{			
				x.push(i-1);
				y.push(j);
				z.push(up);
				bushu[i-1][j]=bushu[i][j]+1;

			}
			else if(value[i-1][j]=='#')
			{
				if(value[i][j-1]=='E')
				{
					return bushu[i][j]+1;
				}
				if(value[i][j-1]=='.')
				{
					x.push(i);
					y.push(j-1);
					z.push(left);
					bushu[i][j-1]=bushu[i][j]+1;
				}
				else if(value[i][j-1]=='#')
				{
					if(value[i+1][j]=='E')
						return bushu[i][j]+1;
					if(value[i+1][j]=='.')
					{
						x.push(i+1);
						y.push(j);
						z.push(down);
						bushu[i+1][j]=bushu[i][j]+1;
					}
					else if(value[i+1][j]=='#')
					{
						if(value[i][j+1]=='E')
							return bushu[i][j]+1;
						if(value[i][j+1]=='.')
						{
							x.push(i);
							y.push(j+1);
							z.push(right);
							bushu[i][j+1]=bushu[i][j]+1;
						}
					}
				}
			}
		}
		else if(temp3==right)
		{
			if(value[i+1][j]=='E')
			{
				return bushu[i][j]+1;
			}
			if(value[i+1][j]=='.')
			{			
				x.push(i+1);
				y.push(j);
				z.push(down);
				bushu[i+1][j]=bushu[i][j]+1;
			}
			else if(value[i+1][j]=='#')
			{
				if(value[i][j+1]=='E')
				{
					return bushu[i][j]+1;
				}
				if(value[i][j+1]=='.')
				{
					x.push(i);
					y.push(j+1);
					z.push(right);
					bushu[i][j+1]=bushu[i][j]+1;
				}
				else if(value[i][j+1]=='#')
				{
					if(value[i-1][j]=='E')
						return bushu[i][j]+1;
					if(value[i-1][j]=='.')
					{
						x.push(i-1);
						y.push(j);
						z.push(up);
						bushu[i-1][j]=bushu[i][j]+1;
					}
					else if(value[i-1][j]=='#')
					{
						if(value[i][j-1]=='E')
							return bushu[i][j]+1;
						if(value[i][j-1]=='.')
						{
							x.push(i);
							y.push(j-1);
							z.push(left);
							bushu[i][j-1]=bushu[i][j]+1;
						}
					}
				}
			}
		}
	}
	return 0;
}

int dfs(int i,int j,int dir)
{
	memset(bushu,0,sizeof(bushu));
	queue<int>x;
	queue<int>y;

	x.push(i);
	y.push(j);

	while(x.size())
	{
		i=x.front();
		j=y.front();

		x.pop();
		y.pop();

		if(value[i+1][j]=='.'&&!bushu[i+1][j])
		{
			x.push(i+1);
			y.push(j);
			bushu[i+1][j]=bushu[i][j]+1;
		}
		if(value[i][j+1]=='.'&&!bushu[i][j+1])
		{
			x.push(i);
			y.push(j+1);
			bushu[i][j+1]=bushu[i][j]+1;
		}
		if(value[i-1][j]=='.'&&!bushu[i-1][j])
		{
			x.push(i-1);
			y.push(j);
			bushu[i-1][j]=bushu[i][j]+1;
		}
		if(value[i][j-1]=='.'&&!bushu[i][j-1])
		{
			x.push(i);
			y.push(j-1);
			bushu[i][j-1]=bushu[i][j]+1;
		}
		if(value[i+1][j]=='E'||value[i][j+1]=='E'||value[i-1][j]=='E'||value[i][j-1]=='E')
			return bushu[i][j]+1;
	}
	return 0;
}

void solve()
{
	int i,j;
	for(i=2;i<col;i++)
	{
		if(value[1][i]=='S')
		{
			cout<<dfs_left(1,i,down)+1<<" ";
			cout<<dfs_right(1,i,down)+1<<" ";
			cout<<dfs(1,i,down)+1<<endl;
			return;
		}
	}

	for(i=2;i<col;i++)
	{
		if(value[row][i]=='S')
		{
			cout<<dfs_left(row,i,up)+1<<" ";
			cout<<dfs_right(row,i,up)+1<<" ";
			cout<<dfs(row,i,up)+1<<endl;
			return;
		}
	}
	for(i=2;i<row;i++)
	{
		if(value[i][1]=='S')
		{
			cout<<dfs_left(i,1,right)+1<<" ";
			cout<<dfs_right(i,1,right)+1<<" ";
			cout<<dfs(i,1,right)+1<<endl;
			return;
		}
	}
	for(i=2;i<row;i++)
	{
		if(value[i][col]=='S')
		{
			cout<<dfs_left(i,col,left)+1<<" ";
			cout<<dfs_right(i,col,left)+1<<" ";
			cout<<dfs(i,col,left)+1<<endl;
			return;
		}
	}

}

int main()
{
	int Test,i,j;
	scanf("%d",&Test);

	while(Test--)
	{
		scanf("%d%d",&col,&row);
		for(i=1;i<=row;i++)
		{
			scanf("%s",value[i]+1);
		}
		solve();
	}
	return 0;
}
