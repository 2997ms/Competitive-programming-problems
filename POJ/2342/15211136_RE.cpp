#include <iostream>
#include <string.h>
int n;
bool vis[10005];
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
int find(int x)
{
    int r=x;
    while(r!=pre[r])
        r=pre[r];
    return r;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int a,b,q;
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        for(int i=1;i<=n;i++)
            {
                scanf("%d",&dp[i][1]);
                pre[i]=i;
            }
            while(cin>>a>>b)
            {
                //cin>>a>>b;
                if(a==0||b==0)
                    break;
                pre[a]=b;
                 q=a;
            }
            int t=find(q);
            tree_dp(t);
			printf("%d\n",max(dp[t][0],dp[t][1]));

    }
    return 0;
}