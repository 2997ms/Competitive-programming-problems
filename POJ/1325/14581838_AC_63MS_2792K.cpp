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
int n,V1,V2;
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

	for(i=0;i<V1;i++)
	{
		memset(visit,0,sizeof(visit));
		if(dfs(i))
			result++;
	}
	cout<<result<<endl;
}

int main()
{
	int i,temp,temp1,temp2;
	while(cin>>V1&&V1)
	{
		memset(grid,0,sizeof(grid));
		cin>>V2>>n;

		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&temp,&temp1,&temp2);
			if(temp1*temp2!=0)
				grid[temp1][temp2]=1;
		}
		Magyarors();
	}
	return 0;
}
