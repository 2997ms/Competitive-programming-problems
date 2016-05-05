#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
char s1[5010];
char s2[5010];
int n;
short dp[5010][5010];
int main()
{
     int i,j,k;
  while(scanf("%d",&n)!=EOF)
  {

       scanf("%s",s1+1);
    for(i=1;i<=n;i++)
    s2[n-i+1]=s1[i];
    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
       if(s1[i]==s2[j])
    dp[i][j]=dp[i-1][j-1]+1;
    else
    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
   }
   printf("%d\n",n-dp[n][n]);
}
}