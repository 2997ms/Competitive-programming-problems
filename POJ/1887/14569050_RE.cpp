#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int num[1005];
int dp[1005];

int main()
{
	int Test=1,i,j,sum,max_v;
	while(cin>>num[1])
	{
		if(num[1]==-1)
			break;
		cout<<"Test #"<<Test<<":"<<endl;
		cout<<"  maximum possible interceptions: ";
		Test++;
		dp[1]=1;
		i=2;

		while(cin>>num[i])
		{
			if(num[i]==-1)
				break;
			dp[i]=1;
			i++;
		}
		sum=i;
		for(i=1;i<=sum;i++)
		{
			max_v=0;
			for(j=1;j<i;j++)
			{
				if(num[i]<=num[j])
				{
					max_v=max(max_v,dp[j]);
				}
			}
			dp[i]=max_v+1;
		}
		cout<<dp[sum]-1;
		cout<<endl<<endl;
	}
	return 0;
}
