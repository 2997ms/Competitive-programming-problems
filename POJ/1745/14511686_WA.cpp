#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int num,mod;
int dp[10005][102];
int value[10005];

int main()
{

	int temp,i,j;
	cin>>num>>mod;

	for(i=1;i<=num;i++)
	{
		cin>>temp;
		value[i]=abs(temp);
	}
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(i=1;i<=num;i++)
	{
		for(j=0;j<mod;j++)
		{
			dp[i][j] += dp[i-1][(j+value[i])%mod];// 7   2 5 0
			dp[i][j] += dp[i-1][(j-value[i]+value[i]*mod)%mod];
		}
	}
	if(dp[num][0])
	{
		cout<<"Divisible"<<endl;
	}
	else
	{
		cout<<"Not divisible"<<endl;
	}
	return 0;
}
