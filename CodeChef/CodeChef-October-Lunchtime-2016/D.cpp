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
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
 
const int maxn = 1e6+5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
 
int n, m;
struct ed
{
    int to;
    int next;
}edge[maxn];
 
int cnt, allnum;
int sub[maxn / 2], dep[maxn / 2];
int head[maxn / 2], col[maxn / 2], dis[maxn / 2], ans[maxn / 2], dead[maxn / 2], sz[maxn / 2], val[maxn / 2];
vector<pair<int, int>>qes[maxn / 2];
 
void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(edge, -1, sizeof(edge));
}
 
void add(int u, int v)
{
    cnt++;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
 
int dfs(int x, int fa)
{
    allnum++;
    val[allnum] = x;
    sub[x] = 1;
    for (int i = head[x]; i != -1; i = edge[i].next)
    {
        int k = edge[i].to;
        if (dead[k] || k == fa)continue;
        dfs(k, x);
        sub[x] += sub[k];
    }
    return sub[x];
}
 
int getCentroid()
{
    int res = INF;
    int an = -1;
    for (int i = 1; i <= allnum; i++)
    {
        int k = val[i];
        int maxx = allnum - sub[k];
        for (int j = head[k]; j != -1; j = edge[j].next)
        {
            int t = edge[j].to;
            if (dead[t])continue;
            maxx = max(maxx, sub[t]);
        }
        if (maxx < res)
        {
            res = maxx;
            an = k;
        }
    }
    return an;
}
 
void dfs_dis(int x, int fa, int de)
{
    dep[x] = de;
    dis[col[x]] = min(dis[col[x]], de);
    for (int i = head[x]; i != -1; i = edge[i].next)
    {
        int k = edge[i].to;
        if (k == fa || dead[k])continue;
        dfs_dis(k, x, de + 1);
    }
}
 
void solve(int x)
{
    allnum = 0;
    dfs(x, -1);
    int co = getCentroid();
    for (int i = 1; i <= allnum; i++)
        dis[col[val[i]]] = INF;
    dis[col[co]] = 0;
    dead[co] = 1;
    dfs_dis(co, -1, 0);
    for (int i = 1; i <= allnum; i++)
    {
        int k = val[i];
        for (auto it : qes[k])
        {
            int le = it.first;
            int ri = it.second;
            ans[ri] = min(ans[ri], dep[k] + dis[le]);
        }
    }
    for (int i = 1; i <= allnum; i++)
        dis[col[val[i]]] = INF;
    for (int i = head[co]; i != -1; i = edge[i].next)
    {
        int k = edge[i].to;
        if (!dead[k])
        {
            solve(k);
        }
    }
}
 
void cal()
{
    sa(n), sa(m);
    repp(i, 1, n)
    {
        sa(col[i]);
    }
    repp(i, 1, n - 1)
    {
        int u, v;
        sa(u), sa(v);
        add(u, v);
        add(v, u);
    }
    int q;
    sa(q);
    repp(i, 1, q)
    {
        int v, c;
        sa(v), sa(c);
        qes[v].push_back(mp(c, i));
    }
    memset(ans, 0x3f, sizeof(ans));
    solve(1);
    repp(i, 1, q)
    {
        printf("%d\n", ans[i]);
    }
}
 
int main()
{
 
    init();
    cal();
    return 0;
} 