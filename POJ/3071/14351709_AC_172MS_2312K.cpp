#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double value[1<<9][1<<9];
double dp[10][1<<9];

int main()
{
	int N,i,j,m;
	while(cin>>N)
	{
		if(N == -1)
			break;

		memset(value,0,sizeof(value));
		memset(dp,0,sizeof(dp));

		for(i=0;i<(1<<N);i++)
		{
			for(j=0;j<(1<<N);j++)
			{
				cin>>value[i][j];
			}
		}

		for(i=0;i<(1<<N);i++)
		{
			dp[0][i]=1;
		}

		for(i=1;i<=N;i++)
		{
			for(j=0;j<(1<<N);j++)
			{
				int temp=j;
				int pend= (temp>>(i-1))&1;
				int temp2=(temp>>(i))<<i;
				if(!pend)
				{
					temp2=temp2+(1<<(i-1));
				}
				
				int k;
				for(k=0;k<(1<<(i-1));k++)
				{
					if(j!=temp2)
					{
						dp[i][j] += dp[i-1][j]*dp[i-1][temp2]*value[j][temp2];
					}
					temp2++;
				}
			}
		}
		double max=0;
		int max_v=-1;
		for(i=0;i<(1<<N);i++)
		{
			if(dp[N][i]>=max)
			{
				max=dp[N][i];
				max_v=i+1;
			}
		}
		cout<<max_v<<endl;
	}

	return 0;
}