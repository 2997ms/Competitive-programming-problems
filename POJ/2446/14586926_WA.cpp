#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#pragma warning(disable:4996)
using namespace std;

map <int,int> node;
int height,weight;
int value[50][50];

int grid[1025][1025];  
int link[1025];  
int visit[1025];  
int m,n,k,num,V1,V2;  
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
		if(dfs(i))  
			result++;  
	}  
	if(result==(m*n-k))
		return true;
	else
		return false;
} 

int main()
{

	int i,j,temp1,temp2;
	
	memset(value,0,sizeof(value));
	memset(grid,0,sizeof(grid));

	cin>>m>>n>>k;

	for(i=1;i<=k;i++)
	{
		scanf("%d%d",&temp1,&temp2);
		value[temp1][temp2]=-1;
	}

	num=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(value[i][j]!=-1)
			{
				value[i][j] = ++num;
			}
		}
	}
	V1=V2=num;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(value[i][j]!=-1)
			{
				if(value[i+1][j]>0)
				{
					grid[value[i][j]][value[i+1][j]]=1;
				}
				if(value[i][j+1]>0)
				{
					grid[value[i][j]][value[i][j+1]]=1;
				}
				if(value[i-1][j]>0)
				{
					grid[value[i][j]][value[i-1][j]]=1;
				}
				if(value[i][j-1]>0)
				{
					grid[value[i][j]][value[i][j-1]]=1;
				}
			}
		}
	}
	if(Magyarors())
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}
