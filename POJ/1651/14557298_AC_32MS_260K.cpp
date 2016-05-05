#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#define INF 0x3f3f3f3f

int dp[105][105];
int value[105];
int num;

int main()
{
	int i,j,k,len;
	scanf("%d",&num);

	for(i=1;i<=num;i++)
	{
		scanf("%d",&value[i]);
		dp[i][i]=0;
	}

	for(i=1;i<=num;i++)
	{
		dp[i][i+1] = 0;
		dp[i][i+2] = value[i]*value[i+1]*value[i+2];
	}

	for(len=3;len<=num;len++)
	{
		for(i=1,j=len+i;j<=num;i++)
		{
			j=len+i;
			dp[i][j]=INF;
			for(k=i+1;k<j;k++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+value[k]*value[i]*value[j]);
			}
		}
	}
	cout<<dp[1][num]<<endl;
	return 0;
}
