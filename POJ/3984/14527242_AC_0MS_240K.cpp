#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

int value[7][7];
int pre[7][7];
int flag[7][7];

void bfs()
{
	memset(flag,0,sizeof(flag));
	memset(pre,-1,sizeof(pre));

	queue<int>x;
	queue<int>y;

	while(x.size())x.pop();
	while(y.size())y.pop();

	x.push(0);
	y.push(0);

	int a;
	int b;
	while(x.size())
	{
		a=x.front();
		b=y.front();

		x.pop();
		y.pop();

		flag[a][b]=1;

		if(a>0&&flag[a-1][b]==0&&value[a-1][b]==0)
		{
			pre[a-1][b]=a*10+b;
			x.push(a-1);
			y.push(b);
		}
		if(b<4&&flag[a][b+1]==0&&value[a][b+1]==0)
		{
			pre[a][b+1]=a*10+b;
			x.push(a);
			y.push(b+1);
		}
		if(b>0&&flag[a][b-1]==0&&value[a][b-1]==0)
		{
			pre[a][b-1]=a*10+b;
			x.push(a);
			y.push(b-1);
		}
		if(a<4&&flag[a+1][b]==0&&value[a+1][b]==0)
		{
			pre[a+1][b]=a*10+b;
			x.push(a+1);
			y.push(b);
		}
	}

}

void prin(int x,int y)
{
	if(pre[x][y]!=-1)
	{
		int y_pr=pre[x][y]%10;
		int x_pr=pre[x][y]/10;
		prin(x_pr,y_pr);
	}
	cout<<"("<<x<<", "<<y<<")"<<endl;
}

int main()
{
	int i,j;
	for(i=0;i<=4;i++)
	{
		for(j=0;j<=4;j++)
		{
			cin>>value[i][j];
		}
	}
	
	bfs();
	prin(4,4);

	return 0;
}
