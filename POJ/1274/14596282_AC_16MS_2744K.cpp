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
	cout<<result<<endl;  
}  

int main()  
{  
	int i,j,temp,temp2,temp3;  
	while(scanf("%d %d",&V1,&V2)!=EOF)  
	{  
		memset(grid,0,sizeof(grid));

		for(i=1;i<=V1;i++)
		{
			scanf("%d",&temp);
			for(j=1;j<=temp;j++)  
			{  
				scanf("%d",&temp2);  
				grid[i][temp2]=1;  
			}
		}
		Magyarors();  
	}  
	return 0;  
}  