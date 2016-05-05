#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

int L,R,C;
char value[50][50][50];
int bushu[50][50][50];

int bfs(int i,int j,int k)
{
	int flag=0;

	queue<int>x;
	queue<int>y;
	queue<int>z;

	x.push(i);
	y.push(j);
	z.push(k);

	while(x.size())
	{
		int temp1=x.front();
		int temp2=y.front();
		int temp3=z.front();

		x.pop();
		y.pop();
		z.pop();

		if(temp1-1>=1&&value[temp1-1][temp2][temp3]=='.'&&!bushu[temp1-1][temp2][temp3])
		{
			x.push(temp1-1);
			y.push(temp2);
			z.push(temp3);
			bushu[temp1-1][temp2][temp3]=bushu[temp1][temp2][temp3]+1;
		}

		if(temp1+1<=L&&value[temp1+1][temp2][temp3]=='.'&&!bushu[temp1+1][temp2][temp3])
		{
			x.push(temp1+1);
			y.push(temp2);
			z.push(temp3);
			bushu[temp1+1][temp2][temp3]=bushu[temp1][temp2][temp3]+1;
		}
		if(temp2-1>=1&&value[temp1][temp2-1][temp3]=='.'&&!bushu[temp1][temp2-1][temp3])
		{
			x.push(temp1);
			y.push(temp2-1);
			z.push(temp3);
			bushu[temp1][temp2-1][temp3]=bushu[temp1][temp2][temp3]+1;
		}
		if(temp2+1<=R&&value[temp1][temp2+1][temp3]=='.'&&!bushu[temp1][temp2+1][temp3])
		{
			x.push(temp1);
			y.push(temp2+1);
			z.push(temp3);
			bushu[temp1][temp2+1][temp3]=bushu[temp1][temp2][temp3]+1;
		}
		if(temp3-1>=1&&value[temp1][temp2][temp3-1]=='.'&&!bushu[temp1][temp2][temp3-1])
		{
			x.push(temp1);
			y.push(temp2);
			z.push(temp3-1);
			bushu[temp1][temp2][temp3-1]=bushu[temp1][temp2][temp3]+1;
		}
		if(temp3+1<=C&&value[temp1][temp2][temp3+1]=='.'&&!bushu[temp1][temp2][temp3+1])
		{
			x.push(temp1);
			y.push(temp2);
			z.push(temp3+1);
			bushu[temp1][temp2][temp3+1]=bushu[temp1][temp2][temp3]+1;
		}
		if(value[temp1-1][temp2][temp3]=='E'||value[temp1+1][temp2][temp3]=='E'||value[temp1][temp2-1][temp3]=='E'||
			value[temp1][temp2+1][temp3]=='E'||value[temp1][temp2][temp3-1]=='E'||value[temp1][temp2][temp3+1]=='E')
		{
			flag=1;
			return bushu[temp1][temp2][temp3]+1;
		}
	}
	return 0;
}

void solve()
{
	int i,j,k;
	for(i=L;i>=1;i--)
	{
		for(j=R;j>=1;j--)
		{
			for(k=C;k>=1;k--)
			{
				if(value[i][j][k]=='S')
				{
					int temp=bfs(i,j,k);
					if(temp==0)
						cout<<"Trapped!"<<endl;
					else
						cout<<"Escaped in "<<temp<<" minute(s)."<<endl;
					return;
				}
			}
		}
	}
}

int main()
{
	int i,j,k;
	while(scanf("%d%d%d",&L,&R,&C))
	{
		if(L+R+C==0)
			break;
		for(i=1;i<=L;i++)
		{
			for(j=1;j<=R;j++)
			{
				scanf("%s",value[i][j]+1);
			}
		}
		memset(bushu,0,sizeof(bushu));
		solve();
	}
	return 0;
}
