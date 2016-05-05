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

	cin>>value[1];
	value[1]=abs(value[1])%mod;
	for(i=2;i<=num;i++)
	{
		cin>>temp;
		value[i]=abs(temp);
		value[i]=value[i]%mod;
	}
	memset(dp,0,sizeof(dp));
	dp[1][value[1]]=1;

	for(i=2;i<=num;i++)
	{
		for(j=0;j<mod;j++)
		{
			if(dp[i-1][j])
			{
				dp[i][(j+value[i])%mod] += dp[i-1][j] ;
				dp[i][(j-value[i]+mod)%mod] +=dp[i-1][j] ;
			}
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
