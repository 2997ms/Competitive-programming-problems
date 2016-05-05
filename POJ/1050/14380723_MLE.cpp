#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#pragma warning(disable:4996) 
using namespace std;

int value[105][105];
int dp[105][105][105][105];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int N,i,j,h,k,g,f;
	int ans=-100;
	cin>>N;

	memset(dp,0,sizeof(dp));

	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			cin>>value[i][j];

			dp[i][j][i][j]=value[i][j];

			if(value[i][j]>ans)
				ans=value[i][j];
		}
	}

	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			for(h=i;h<=N;h++)
			{
				for(k=j;k<=N;k++)
				{
					int s=0;
					for(g=i;g<=h;g++)
						s += value[g][k];
					for(f=j;f<=k;f++)
						s += value[h][f];
					s =s-value[h][k];
					dp[i][j][h][k]=dp[i][j][h-1][k-1]+s;

					if(dp[i][j][h][k]>ans)
						ans=dp[i][j][h][k];
				}
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}

