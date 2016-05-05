#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#pragma warning(disable:4996) 
using namespace std;

int value[250][250];
int value2[250];
int dp[250];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,i,j,h,k,g,f;
	int ans=-100;
	scanf("%d",&N);

	memset(dp,0,sizeof(dp));
	memset(value2,0,sizeof(value2));

	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			scanf("%d",&value[i][j]);
			ans=max(ans,value[i][j]);
		}
	}

	for(i=1;i<=N;i++)
	{

			for(h=i;h<=N;h++)
			{
				for(k=1;k<=N;k++)
				{	
					value2[k] += value[h][k];
					dp[k] = max(dp[k-1]+value2[k],value2[k]);
					ans = max(ans,dp[k]);
				}
				memset(dp,0,sizeof(dp));
			}
			memset(value2,0,sizeof(value2));
		
	}

	cout<<ans<<endl;
	return 0;
}