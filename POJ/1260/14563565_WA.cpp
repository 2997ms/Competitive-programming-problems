#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int dp1[105];//前i种珍珠的数量
int dp2[105];//搞到第i种珍珠为止，花的钱
int value[105];//第i中珍珠的单价
int num;

int main()
{


	int Test,i;
	cin>>Test;
	
	while(Test--)
	{
		cin>>num;
		for(i=1;i<=num;i++)
		{
			cin>>dp1[i]>>value[i];
			if(i==1)
			{
			  dp2[i]=(dp1[i]+10)*value[i];	
			}
			else
			{
				if(dp2[i-1]+(dp1[i]+10)*value[i]>
					(dp1[i-1]+dp1[i]+10)*value[i])
				{
					dp2[i]=(dp1[i-1]+dp1[i]+10)*value[i];
					dp1[i]=dp1[i]+dp1[i-1];

				}
				else
				{
					dp2[i]=dp2[i-1]+(dp1[i]+10)*value[i];
					dp1[i]=dp1[i]+dp1[i-1];
				}
			}
		}
		cout<<dp2[num]<<endl;
	}
	return 0;
}
