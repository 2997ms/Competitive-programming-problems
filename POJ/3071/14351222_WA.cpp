#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

double value[1<<8][1<<8];
double dp[1<<8][1<<8];

vector<int> match[9][1<<9];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
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
				int pend= temp>>(i-1)&1;

				if(pend)
				{
					if(temp>=(1<<(i-1)))
						temp=temp-(1<<(i-1));
					else
						temp=(1<<(i-1));
				}
				else
				{
					if(temp>=(1<<(i-1)))
						temp=temp+(1<<(i-1));
					else
						temp=(1<<(i-1));
				}
				int k;
				for(k=0;k<(1<<(i-1));k++)
				{
					temp=temp+k;
					if(j!=temp)
						dp[i][j] = dp[i-1][j]*dp[i-1][temp]*value[j][temp]+dp[i][j];
				}
			}
		}
		double max=0,max_v;
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