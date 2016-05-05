#include <iostream>
#include <string.h>
#include <stdio.h>
#pragma comment(linker, "/STACK:10240000,10240000")
int n;
int vis[10005];
int dp[10005][2],pre[10005];
using namespace std;
void tree_dp(int x)
{
    vis[x]=1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&pre[i]==x)
        {
            tree_dp(i);
            dp[x][1]+=dp[i][0];
            dp[x][0]+=max(dp[i][0],dp[i][1]);
        }
    }
}
/*int find(int x)
{
    int r=x;
    while(r!=pre[r])
        r=pre[r];
    int i=x,j;
    while(pre[i]!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}*/
int main()
{
    while(scanf("%d",&n)!=EOF)
    //while(cin>>n)
    {
        int a,b,q=0;
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        for(int i=1;i<=n;i++)
            {
                //cin>>dp[i][1];
                scanf("%d",&dp[i][1]);
    
            }
 for(int i=1;i<=6000;i++)
{
pre[i]=i;
}
           // while(cin>>a>>b)
           while(scanf("%d%d",&a,&b)!=EOF)
            {
                //cin>>a>>b;
                if(a==0&&b==0)
                    break;
                pre[a]=b;
                 q=b;
            }
            while(q!=pre[q])
            {
                q=pre[q];
            }
           // cout<<q<<endl;
          // int t=find(q);
          // cout<<t<<endl;
           //for(int i=1;i<=n;i++)
            //cout<<pre[i]<<endl;
            tree_dp(q);
            //cout<<max(dp[q][0],dp[q][1])<<endl;
            printf("%d\n",max(dp[q][0],dp[q][1]));

    }



    return 0;
}