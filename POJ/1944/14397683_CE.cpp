#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn=10000+10,maxm=1001,inf=11111;
struct
{
    int x,y;
}que[maxn];

int d[maxm];
int main()
{
    int n,p;
    scanf("%d %d",&n,&p);
    for(int i=1;i<=p;i++)
    {
        scanf("%d %d",&que[i].x,&que[i].y);
        if(que[i].x>que[i].y)
        swap(que[i].x,que[i].y);
        if(que[i].x==que[i].y)
        {
            i--,p--;
        }
    }
    int ans=inf;
    for(int k=1;k<=n;k++)
    {
        memset(d,0,sizeof(d));
        int ret=0;
        for(int i=1;i<=p;i++)
        {
            if(k+1<=que[i].x||k>=que[i].y)
            d[que[i].x]=max(que[i].y,d[que[i].x]);
            else
            {
                d[que[i].y]=n+1;
                d[1]=max(que[i].x,d[1]);
            }
        }

        int k=0;
        for(int i=1;i<=n;i++)
        {
            if(d[i]>k)
            {
                ret+=d[i]-max(i,k);
                k=d[i];
            }
        }
        ans=min(ans,ret);
    }
    printf("%d\n",ans);
    return 0;
}