#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int grid[205][205];
int link[205];
int visit[205];
int n,m,k,V1,V2;
int result;

bool dfs(int x)
{
	int i;
	for(i=1;i<=V2;i++)
	{
		if(grid[x][i]==0&&visit[i]==0)
		{
			visit[i]=1;
			if(link[i]==-1||dfs(link[i]))
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
	memset(link,-1,sizeof(link));//！！这里不能是0

	for(i=1;i<=V1;i++)
	{
		memset(visit,0,sizeof(visit));
		if(dfs(i))
			result++;
	}
	cout<<V1+V2-result<<endl;
}

int main()
{
	int i,j,pair,temp1,temp2;

	for(i=1;;i++)
	{
		scanf("%d%d%d",&n,&m,&pair);
		V1=n;
		V2=m;
		if(n==0&&m==0&&pair==0)
			break;

		cout<<"Case "<<i<<": ";
		memset(grid,0,sizeof(grid));

		for(j=1;j<=pair;j++)
		{
			scanf("%d%d",&temp1,&temp2);
			grid[temp1][temp2]=grid[temp2][temp1]=1;
		}
		Magyarors();
	}
	return 0;
}
