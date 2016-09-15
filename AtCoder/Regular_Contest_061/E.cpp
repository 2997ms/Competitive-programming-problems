#include <fstream>
#include <iostream>
#include <functional>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
 
typedef long long ll;
#define eps 1e-10
#define LL_INF 0x33ffffffffffffff
#define INF 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define pper(i,n,m) for(int i = n;i >= m; i--)
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
 
const int maxn = 2e5 + 5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}
 
struct ed
{
    int to;
    int val;
    int next;
}edge[maxn*4];
 
int n,m,cnt;
int head[maxn],res[maxn],vis[maxn];
set<int>con[maxn];
 
void init()
{
    cnt=0;
    memset(edge,-1,sizeof(edge));
    memset(head,-1,sizeof(head));
}
 
void add(int u,int v,int c)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=c;
    edge[cnt].next=head[u];
 
    head[u]=cnt;
}
 
void solve()
{
    scanf("%d%d",&n,&m);
 
    for(int i=0;i<m;i++)
    {
        int p,q,c;
        scanf("%d%d%d",&p,&q,&c);
        add(p,q,c);
        add(q,p,c);
    }
    for(int i=1;i<=n;i++)
    {
        res[i]=INF;
    }
    priority_queue< pair<int,int> >que;
    que.push(make_pair(0,1));
 
    int cnt=0;
    res[1]=0;
    while(!que.empty())
    {
        /*
        cnt++;
        if(cnt>100)
        {
            return;
        }
        */
        int dis = -que.top().first;
        int x=que.top().second;
        //cout<<dis<<" "<<x<<endl;
        que.pop();
        if(dis>res[x])
        {
            //cout<<"continue"<<endl;
            continue;
        }
        for(int i=head[x];i!=-1;i=edge[i].next)
        {
            int to = edge[i].to;
            int c = edge[i].val;
            int d = dis + (!con[x].count(c));
 
            //cout<<x<<" "<<to<<" "<<c<<" "<<d<<endl;
            if(d<res[to])
            {
                res[to]=d;
                con[to].clear();
                con[to].insert(c);
                que.push(make_pair(-d,to));
            }
            else if(d==res[to])
            {
                con[to].insert(c);
            }
        }
        //cout<<endl<<endl;
    }
    if(res[n]==INF)
    {
        puts("-1");
    }
    else
    {
        printf("%d\n",res[n]);
    }
}
 
int main()
{
    init();
    solve();
    return 0;
}
