#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int grid[505][505];
int link[505];
int visit[505];
int n,k,V1,V2;
int result;

bool dfs(int x)
{
	int i;
	for(i=1;i<=V2;i++)
	{
		if(grid[x][i]==1&&visit[i]==0)
		{
			visit[i]=1;
			if(link[i]==0||dfs(link[i]))
			{
				link[i]=x;
				return true;
			}
		}
	}
	return false;
}

void Magyarors()
{
	int i;
	
	result=0;
	memset(link,0,sizeof(link));

	for(i=1;i<=V1;i++)
	{
		memset(visit,0,sizeof(visit));
		if(dfs(i))
			result++;
	}
	cout<<result<<endl;
}

int main()
{

	int i,x,y;
	cin>>n>>k;

	V1=V2=n;

	memset(grid,0,sizeof(grid));
	for(i=1;i<=k;i++)
	{
		cin>>x>>y;
		grid[x][y]=1;
	}
	Magyarors();
	return 0;
}

