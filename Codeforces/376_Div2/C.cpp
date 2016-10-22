#include <fstream>
#include <iostream>
#include <functional>
#include <algorithm>
#include <sstream>
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
#define LL_INF 0x3fffffffffffffff
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

const int maxn = 200005;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}

int n,m,k;
int u[maxn],v[maxn],val[maxn],fa[maxn];
vector<int>col[maxn];

int getfa(int x)
{
    return x==fa[x]?x:fa[x]=getfa(fa[x]);
}

void solve()
{
    sa(n),sa(m),sa(k);
    repp(i,1,n)
    {
        sa(val[i]);
        fa[i]=i;
    }
    repp(i,1,m)
    {
        sa(u[i]),sa(v[i]);
        int x=getfa(u[i]);
        int y=getfa(v[i]);
        if(x==y)
        {
            continue;
        }
        else
        {
            fa[x]=y;
        }
    }
    repp(i,1,n)
    {
        int x=getfa(i);
        col[x].push_back(i);
    }
    int res = 0;
    for(int i=1;i<=n;i++)
    {
        int maxx=0;
        map<int,int>t;
        for(int j=0;j<col[i].size();j++)
        {
            t[val[col[i][j]]]++;
            int k=t[val[col[i][j]]];
            if(k>maxx)
            {
                maxx=k;
            }
        }
        res+=col[i].size()-maxx;
    }
    cout<<res<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/2997ms/Desktop/eve/algorithm/algorithm/i.txt", "r", stdin);
    //freopen("/Users/2997ms/Desktop/eve/algorithm/algorithm/o.txt", "w", stdout);
#endif
    solve();
    return 0;
}