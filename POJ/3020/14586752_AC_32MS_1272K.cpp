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
char value[50][20];

int grid[505][505];  
int link[505];  
int visit[505];  
int n,k,V1,V2,num;  
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
	cout<<num-result/2<<endl;  
} 

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int Test,i,j;
	cin>>Test;

	while(Test--)
	{
		num=0;
		node.clear();
		memset(grid,0,sizeof(grid));
		memset(value,0,sizeof(value));

		scanf("%d%d",&height,&weight);

		for(i=1;i<=height;i++)
		{
			cin>>value[i]+1;
			for(j=1;j<=weight;j++)
			{
				if(value[i][j]=='*')
				{
					node[(i-1)*weight+j] = ++num;
				}
			}
		}

		V1=V2=num;

		for(i=1;i<=height;i++)
		{
			for(j=1;j<=weight;j++)
			{
				if(value[i][j]=='*')
				{
					if(value[i+1][j]=='*')
					{
						grid[node[(i-1)*weight+j]][node[(i)*weight+j]]=1;
						//grid[node[(i)*weight+j]][node[(i-1)*weight+j]]=1;
					}
					if(value[i][j+1]=='*')
					{
						grid[node[(i-1)*weight+j]][node[(i-1)*weight+j+1]]=1;
						//grid[node[(i-1)*weight+j+1]][node[(i-1)*weight+j]]=1;
					}
					if(value[i-1][j]=='*')
					{
						grid[node[(i-1)*weight+j]][node[(i-2)*weight+j]]=1;
						//grid[node[(i-2)*weight+j]][node[(i-1)*weight+j]]=1;
					}
					if(value[i][j-1]=='*')
					{
						//grid[node[(i-1)*weight+j-1]][node[(i-1)*weight+j]]=1;
						grid[node[(i-1)*weight+j]][node[(i-1)*weight+j-1]]=1;
					}
				}
			}
		}
		Magyarors();
	}
	return 0;
}
