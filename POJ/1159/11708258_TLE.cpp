#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

int max(int m,int n)
{
	return m>n?m:n;
}
int n;
	
	short dp[5010][5010];
	
	char s1[5010];
	char s2[5010];
int main()
{
int i,j;
	while(scanf("%n",&n)!=EOF)
	{
		scanf("%s",s1+1);
		for(i=1;i<=n;i++)
			s2[n-i+1]=s1[i];
		memset(dp,0,sizeof(dp));

		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				if(s1[i]==s2[j])
				{
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
			printf("%d\n",n-dp[n][n]);
	}
	return 0;
}


	   



