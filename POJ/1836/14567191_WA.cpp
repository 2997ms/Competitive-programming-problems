#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int num;
int l_dp[2000];
int r_dp[2000];
double value[2000];

int main()
{
	int i,j,max_v;
	scanf("%d",&num);

	for(i=1;i<=num;i++)
	{
		cin>>value[i];
		l_dp[i]=1;
		r_dp[i]=1;
	}
	max_v=0;
	for(i=1;i<=num;i++)
	{
		max_v=0;
		for(j=1;j<i;j++)
		{
			if(value[i]>value[j])
			{
				max_v=max(l_dp[j],max_v);
			}
		}
		l_dp[j]=max_v+1;
	}

	for(i=num;i>=1;i--)
	{
		max_v=0;
		for (j = num; j > i; j--)
		{
			if(value[i]>value[j])
			{
				max_v=max(r_dp[j],max_v);
			}
		}
		r_dp[j]=max_v+1;
	}
	max_v=0;
	for(i=1;i<=num;i++)
	{
		max_v = max(l_dp[i]+r_dp[i+1],max_v);
	}

	cout<<num-max_v<<endl;
	return 0;
}
