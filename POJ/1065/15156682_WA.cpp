#include<stdio.h>
#include<algorithm>
using namespace std;
#define Max 5005
struct node{
    int l,w;
}n[Max];

int an[Max];
bool cmp(node x,node y)
{
    if(x.w==y.w) return x.l<y.l;
    return x.w>y.w;
}

int main()
{
    int t,m,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%d%d",&n[i].l,&n[i].w);
        sort(n,n+m,cmp);
        int num=0;
        for(i=0;i<m;i++)
        {
            int flag=0;
            for(j=0;j<num;j++)
              if(n[i].l>=an[j])
              {
                  an[j]=n[i].l;
                  flag=1;
                  break;
              }
            if(!flag)     an[num++]=n[i].l;
        }
        printf("%d\n",num);
    }
    return 0;
}