#include <iostream>
using namespace std;

int value[1005];
int dp[1005];

int main()
{
	int num;
	int i,j,max=1;

	cin>>num;

	memset(dp,0,sizeof(dp));

	for(i=0;i<num;i++)
	{
		cin>>value[i];
		dp[i]=1;
		for(j=0;j<i;j++)
		{
			if(value[i]>value[j])
			{
				if(dp[j]+1>max)
				{
					max=dp[j]+1;
				}
			}
		}
		dp[i]=max;
		max=1;
	}
	
	max=1;
	for(i=0;i<num;i++)
	{
		if(dp[i]>max)
		{
			max=dp[i];
		}
	}
	cout<<max<<endl;

	return 0;
}