#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[15][15*9];

int main()
{
	int n,i,k,j,result;
	cin>>n;

	memset(dp,0,sizeof(dp));
	for(k=0;k<=9;k++)
	{
		dp[1][k]=1;
	}

	for(j=2;j<=n;j++)
	{
		for(i=0;i<=n*9;i++)
		{
			for(k=0;k<=9;k++)
			{
				dp[j][i] += dp[j-1][i-k] ;
			}
		}
	}
	result=0;
	for(j=0;j<=(n/2)*9;j++)
		result += dp[n/2][j]*dp[n/2][j];
	cout<<result<<endl;

	return 0;
}