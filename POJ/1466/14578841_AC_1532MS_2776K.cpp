#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int grid[805][805];
int link[805];
int visit[805];
int n,k,V1,V2;
int result;

bool dfs(int x)
{
	int i;
	for(i=0;i<V2;i++)
	{
		if(grid[x][i]==1&&visit[i]==0)
		{
			visit[i]=1;
			if(link[i]==-1||dfs(link[i]))
			{
				link[i]=x;
				link[x]=i;//!!!
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
	memset(link,-1,sizeof(link));

	for(i=0;i<V1;i++)
	{
		memset(visit,0,sizeof(visit));
		if(link[i]==-1&&dfs(i))
			result++;
	}
	cout<<n-result<<endl;
}

int main()
{
	int i,j,temp1,temp2,temp3;
	while(scanf("%d",&n)!=EOF)
	{
		memset(grid,0,sizeof(grid));
		V1=V2=n;
		for(i=0;i<n;i++)
		{
			scanf("%d: (%d)",&temp1,&temp2);
			for(j=1;j<=temp2;j++)
			{
				scanf("%d",&temp3);
				grid[temp1][temp3]=1;
			}
		}
		Magyarors();
	}
	return 0;
}
