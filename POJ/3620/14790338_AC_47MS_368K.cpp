#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;

int n,m,k;
int visit[105][105];
int map_m[105][105];

void dfs(int i,int j)
{
	k++;
	map_m[i][j]=1;
	if(i<n&&visit[i+1][j]==1&&map_m[i+1][j]==0)
	{
		dfs(i+1,j);
	}
	if(j<m&&visit[i][j+1]==1&&map_m[i][j+1]==0)
	{
		dfs(i,j+1);
	}
	if(i>1&&visit[i-1][j]==1&&map_m[i-1][j]==0)
	{
		dfs(i-1,j);
	}
	if(j>1&&visit[i][j-1]==1&&map_m[i][j-1]==0)
	{
		dfs(i,j-1);
	}
}

int main()
{
	int i,j,temp1,temp2,ans;
	cin>>n>>m>>k;

	memset(visit,0,sizeof(visit));
	memset(map_m,0,sizeof(map_m));
	for(i=1;i<=k;i++)
	{
		cin>>temp1>>temp2;
		visit[temp1][temp2]=1;
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(map_m[i][j]==0&&visit[i][j]==1)
			{
				k=0;
				dfs(i,j);
				ans=max(ans,k);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}