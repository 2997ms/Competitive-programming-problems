#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int V,P;
int value[305];

int sum[305][305];
int dp[35][305];

int main()
{
	int i,j,k;
	memset(sum,0,sizeof(sum));
	memset(dp,10000,sizeof(dp));

	cin>>V>>P;

	value[0]=0;
	for(i=1;i<=V;i++)
	{
		cin>>value[i];
	}
	sum[1][2]=value[2]-value[1];
	for(i=1;i<=V;i++)
	{
		for(j=i+1;j<=V;j++)
		{
			sum[i][j]=sum[i][j-1]+value[j]-value[(i+j)/2];
		}
	}

	for(i=1;i<=V;i++)
	{
		dp[1][i]=sum[1][i];
	}

	for(i=2;i<=P;i++)
	{
		for(j=i;j<=V;j++)
		{
			for(k=1;k<=j;k++)
			{   
				dp[i][j]=min(dp[i][j],dp[i-1][k-1]+sum[k][j]);
			}
		}
	}
	cout<<dp[P][V]<<endl;
	return 0;
}
