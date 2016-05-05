#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
int n,a[10001][2],p,dp[1001],sum,ans;

int main()
{
    while(scanf("%d%d",&n,&p)==2)
    {
         int i,j,right;
         for(i=1;i<=p;i++)
         {
              scanf("%d%d",&a[i][0],&a[i][1]);
              if(a[i][0]>a[i][1]) swap(a[i][0],a[i][1]);
         }
         ans=1000000;
         for(i=1;i<=n;i++)
         {
              memset(dp,0,sizeof(dp));
              for(j=1;j<=p;j++)
              {
                  if(a[j][0]<i&&a[j][1]>=i)
                  {
                       if(dp[1]<a[j][0]) dp[1]=a[j][0]; 
                       if(dp[a[j][1]]<n+1) dp[a[j][1]]=n+1;
                  }
                  else
                       if(dp[a[j][0]]<a[j][1]) dp[a[j][0]]=a[j][1];
              }
              sum=right=0;
              for(j=1;j<=n;j++)
              {
                   if(!dp[j])  continue;
                   if(j>right)
                   {
                         sum+=dp[j]-j;right=dp[j];
                   }
                   else  if(dp[j]>right)
                         {
                               sum+=dp[j]-right;
                               right=dp[j];
                         }
                   if(sum>ans)  break;
              }
              if(sum<ans)  ans=sum;
         }
         printf("%d/n",ans);
    }  
    return 0;
}   
