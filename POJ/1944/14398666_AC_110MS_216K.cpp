#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define N 1005
#define INF 0x3f3f3f3f
#define MAX(a,b) ((a)>(b)?(a):(b))
 
int n,p,to[N];
struct E
{
    int sta,ed;
}e[10005];
 
void swap(int &a,int &b)
{
    int temp=a;
    a=b;b=temp;
}
 
void re(void)
{
    scanf_s("%d%d",&n,&p);
    for(int i=1;i<=p;i++)
    {
        scanf_s("%d%d",&e[i].sta,&e[i].ed);
        if(e[i].sta>e[i].ed) swap(e[i].sta,e[i].ed);
    }
}
 
void run(void)
{
    int ans=INF;
    for(int i=1;i<=n;i++)
    {
        memset(to,0,sizeof(to));
        int sum=0;
        for(int j=1;j<=p;j++)
        {
            if(i>e[j].sta&&i<=e[j].ed)
            {
                to[1]=MAX(to[1],e[j].sta);
                to[e[j].ed]=n+1;
            }
            else
                to[e[j].sta]=MAX(to[e[j].sta],e[j].ed);
        }
        sum=0;
        int ri=0;
        for(int j=1;j<=n;j++)
        {
            if(!to[j])continue;
            if(j>ri)
            {
                sum+=to[j]-j;
                ri=to[j];
            }
            else if(to[j]>ri)
            {
                sum+=to[j]-ri;
                ri=to[j];
            }
        }
        ans=ans<sum?ans:sum;
    }
    printf("%d\n",ans);
}
 
int main()
{
    re();
    run();
    return 0;
}