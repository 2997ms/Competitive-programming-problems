#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
//最大的状态也就是所有的砝码都放在了最端点的位置
//即20*25*15=7500 即-7500~7500

int dp[21][15001];
int weizhi[21];
int weight[21];

int main()
{

	memset(dp,0,sizeof(dp));
	dp[0][7500]=1;
	int C,G,i,j,k;
	cin>>C>>G;

	for(i=1;i<=C;i++)
		cin>>weizhi[i];
	for(i=1;i<=G;i++)
		cin>>weight[i];
	
	for(i=1;i<=G;i++)
	{
		for(j=0;j<=15000;j++)
		{
			for(k=1;k<=C;k++)
			{
				dp[i][j] += dp[i-1][j-weight[i]*weizhi[k]];
			}
		}
	}
	
	cout<<dp[G][7500]<<endl;
	return 0;
}
