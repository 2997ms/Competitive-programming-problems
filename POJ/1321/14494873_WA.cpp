#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int n,k,result;
char value[15][15];
int flag[15];

void dfs(int i,int j,int num)
{
	flag[j]=1;

	if(num==k)
	{
		result++;
		return;
	}
	if(j>n||i>n)
		return;
	int h,g;
	for(g=i+1;g<=n;g++)
	{
		for(h=1;h<=n;h++)
		{
			if(flag[h]==0&&value[g][h]=='#')
			{
				dfs(g,h,num+1);
			}
		}
	}

	flag[j]=0;
}

int main()
{

	int i,j;

	while(cin>>n>>k)
	{
		if(n+k==-2)
			break;
		for(i=1;i<=n;i++)
			cin>>value[i]+1;
		memset(flag,0,sizeof(flag));
		result=0;

		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(value[j][i]=='#')
					dfs(j,i,1);
			}
		}
		cout<<result<<endl;
	}

	return 0;
}
