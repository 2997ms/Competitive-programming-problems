#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int grid[305][305];
int link[305];
int visit[305];
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
			if(link[i]==-1||dfs(link[i]))
			{
				link[i]=x;
				return true;
			}
		}
	}
	return false;
}

bool Magyarors()
{
	int i;
	
	result=0;
	memset(link,-1,sizeof(link));//！！这里不能是0

	for(i=1;i<=V1;i++)
	{
		memset(visit,0,sizeof(visit));
		if(!dfs(i))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int Test,i,j,num,temp;
	cin>>Test;
	
	while(Test--)
	{
		memset(grid,0,sizeof(grid));
		cin>>V1>>V2;
		
		for(i=1;i<=V1;i++)
		{
			scanf("%d",&num);
			for(j=1;j<=num;j++)
			{
				scanf("%d",&temp);
				grid[i][temp]=1;
			}
		}
		if(V1>V2)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			if(Magyarors())
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
