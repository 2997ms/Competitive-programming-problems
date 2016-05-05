#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int row,col,i,j,sum,result1,result2;
int value[70][70];
int color[70][70];

int move_x[5]={1,0,-1,0};
int move_y[5]={0,1,0,-1};

void dfs(int a,int b)
{
	color[a][b]=1;
	sum++;
	int a_x,b_x;

	if((value[a][b]&1)==0)
	{
		a_x=a+move_x[3];
		b_x=b+move_y[3];
		if(a>=1 && a<=row && b>=1 && b<=col && color[a_x][b_x]==0)
		{
			dfs(a_x,b_x);
		}
	}
	if((value[a][b]&2)==0)
	{
		a_x=a+move_x[2];
		b_x=b+move_y[2];
		if(a>=1 && a<=row && b>=1 && b<=col && color[a_x][b_x]==0)
		{
			dfs(a_x,b_x);
		}
	}
	if((value[a][b]&4)==0)
	{
		a_x=a+move_x[1];
		b_x=b+move_y[1];
		if(a>=1 && a<=row && b>=1 && b<=col && color[a_x][b_x]==0)
		{
			dfs(a_x,b_x);
		}
	}
	if((value[a][b]&8)==0)
	{
		a_x=a+move_x[0];
		b_x=b+move_y[0];
		if(a>=1 && a<=row && b>=1 && b<=col && color[a_x][b_x]==0)
		{
			dfs(a_x,b_x);
		}
	}

}

int main()
{

	memset(color,0,sizeof(color));

	cin>>row>>col;
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			cin>>value[i][j];
		}
	}
	result1=0;
	result2=0;
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			sum=0;
			if(color[i][j]==0)
			{
				dfs(i,j);
				result2++;
			}
			result1=max(sum,result1);
		}
	}

	cout<<result2<<endl;
	cout<<result1<<endl;

	return 0;
}
