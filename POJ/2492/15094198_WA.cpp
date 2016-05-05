#include <iostream>
#include <string.h>
using namespace std;
int pre[2000005];
int find(int x)
{
    int r=x;
    while(r!=pre[r])
    {
        r=pre[r];
    }

    return r;
}
void join(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
    pre[fy]=fx;
}
int same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    int t,n,m,a,b;
    while(cin>>t)
    {
        int s=0;
        while(t--)
        {
            s++;
            memset(pre,0,sizeof(pre));
            bool flag=0;
            cin>>n>>m;
            for(int i=1;i<=2*n;i++)
                pre[i]=i;
            for(int i=1;i<=m;i++)
            {
                cin>>a>>b;
                if(flag)
                    continue;
                if(same(a,b))
                {
                    flag=1;
                    continue;
                }
                join(a+n,b);
                join(a,b+n);
            }
            if(flag)
                {
                    cout<<"Scenario #"<<s<<":"<<endl;
                    cout<<"Suspicious bugs found!"<<endl;
                    cout<<endl;
                }
                else
                {
                    cout<<"Scenario #"<<s<<":"<<endl;
                    cout<<"No suspicious bugs found!"<<endl;
                    cout<<endl;
                }
                   //  s++;
        }
    }
    return 0;
}