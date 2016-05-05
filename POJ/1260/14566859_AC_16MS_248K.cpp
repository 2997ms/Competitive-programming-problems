#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int dp1[105];//前i种珍珠的数量
int sum[105];
int dp2[105];//搞到第i种珍珠为止，花的钱
int value[105];//第i中珍珠的单价
int num;

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int Test,i,j;
	cin>>Test;
	
	while(Test--)
	{
		cin>>num;

		memset(dp1,0,sizeof(dp1));
		memset(sum,0,sizeof(sum));
		for(i=1;i<=num;i++)
		{
			dp2[i]=0x3f3f3f3f;
		}

		for(i=1;i<=num;i++)
		{
			cin>>dp1[i]>>value[i];
			sum[i]=sum[i-1]+dp1[i];
		}
		dp2[1]=(dp1[1]+10)*value[1];
		for(i=1;i<=num;i++)
		{
			for(j=0;j<i;j++)
			{
				dp2[i]=min(dp2[i],dp2[j]+(sum[i]-sum[j]+10)*value[i]);
			}
		}
		cout<<dp2[num]<<endl;
	}
	return 0;
}