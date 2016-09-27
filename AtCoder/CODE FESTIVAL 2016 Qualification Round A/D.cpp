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
 
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
 
int r,c;
int n,res;
int visx[maxn],visy[maxn];
int ri[maxn],ci[maxn],ai[maxn];
vector < int > edger[maxn], edgec[maxn];
 
ll low,up;
ll xmin[maxn],ymax[maxn];
 
void dfsmax(int,int);
void dfsmin(int,int);
 
void dfsmin(int x,int va)
{
    visx[x]=1;
    xmin[x]=va;
    low=max(low,-xmin[x]);
    for(int i=0;i<edger[x].size();i++)
    {
        int v = ai[edger[x][i]];
        int to= ci[edger[x][i]];
 
        if(visy[to])
        {
            res&=(xmin[x]+ymax[to]==v);
        }
        else
        {
            dfsmax(to,v-xmin[x]);
        }
    }
}
 
void dfsmax(int y,int va)
{
    visy[y]=1;
    ymax[y]=va;
    up=min(up,ymax[y]);
    for(int i=0;i<edgec[y].size();i++)
    {
        int v = ai[edgec[y][i]];
        int to= ri[edgec[y][i]];
 
        if(visx[to])
        {
            res&=(xmin[to]+ymax[y]==v);
        }
        else
        {
            dfsmin(to,v-ymax[y]);
        }
    }
}
 
void solve()
{
    scanf("%d%d",&r,&c);
    scanf("%d",&n);
 
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&ri[i],&ci[i],&ai[i]);
        edger[ri[i]].push_back(i);
        edgec[ci[i]].push_back(i);
    }
    res=1;
    for(int i=1;i<=r&&res;i++)
    {
        if(!visx[i])
        {
            low=-1e18;
            up=1e18;
            dfsmin(i,0);
            res &= (low<=up);
        }
    }
    if(res)
    {
        puts("Yes");
    }
    else
    {
        puts("No");
    }
}
int main()
{
 
    solve();
    return 0;
}