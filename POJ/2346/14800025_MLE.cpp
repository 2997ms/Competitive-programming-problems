#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

const int mod = 1e9+7;
int n;
long long sum1[1005][9005];//带0 表示i位数字和为j的数量
long long sum2[1005][9005];//不带0

void init()
{
	memset(sum1,0,sizeof(sum1));
	memset(sum2,0,sizeof(sum2));

	int i,j;
	for(i=0;i<=9;i++)
	{
		sum1[1][i]=1;
		sum2[1][i]=1;
	}
	
	for(i=1;i<=1000;i++)
	{
		sum2[i][1]=1;
		sum1[i][0]=1;
	}

	for(i=2;i<=1000;i++)
	{
		for(j=1;j<=9*i;j++)
		{
			if(j<=9)
			{
				sum1[i][j]=(sum1[i][j-1]+sum1[i-1][j])%mod;
				if(j!=1)
					sum2[i][j]=(sum2[i][j-1]+sum2[i-1][j-1])%mod;
			}
			else
			{
				sum1[i][j]=(sum1[i][j-1]+sum1[i-1][j]-sum1[i-1][j-10])%mod;
				sum2[i][j]=(sum2[i][j-1]+sum2[i-1][j-1]-sum2[i-1][j-10])%mod;
			}
		}
	}
}

int main()
{	
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	
	int i;
	long long sum=0;
	
	init();
	cin>>n;
	
	for(i=0;i<=n*9;i++)
	{
		sum = (sum + sum1[n/2][i]*sum1[n/2][i])%mod;
	}
	cout<<sum<<endl;

	//system("pause");
	return 0;
}
