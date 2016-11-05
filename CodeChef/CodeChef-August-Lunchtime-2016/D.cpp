#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
 
#define INF 0x3fffffff
typedef long long ll;
 
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define pb push_back
 
const int maxn = 2e5 + 5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
 
ll n, m, ans;
ll val[maxn], w[maxn], res[maxn],v[maxn];
 
int cnt;
int head[maxn], vis[maxn];
int dp[maxn][20], p[maxn][2], sz[maxn], fa[maxn], deep[maxn], qus[maxn];
 
struct e
{
    int to;
    int next;
}EDGE[maxn];
 
void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(EDGE, -1, sizeof(EDGE));
    memset(vis, 0, sizeof(vis));
}
 
void add(int u, int v)
{
    cnt++;
    EDGE[cnt].to = v;
    EDGE[cnt].next = head[u];
    head[u] = cnt;
}
 
void dfs(int x, int f)
{
    deep[x] = deep[f] + 1;
    dp[x][0] = f;
    w[x] = val[x] + w[f];
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = EDGE[i].next)
    {
        int k = EDGE[i].to;
        if (!vis[k])
        {
            dfs(k, x);
        }
    }
}
struct ed
{
    int u;
    int v;
}edge[maxn];
 
int getfa(int x)
{
    return x == fa[x] ? x : getfa(fa[x]);
}
 
int lca(int a, int b)
{
    if (deep[a] < deep[b])
        swap(a, b);
    int dif = deep[a] - deep[b];
    for (int i = 0; i < 20; i++)
    {
        if ((dif >> i) & 1)
        {
            a = dp[a][i];
        }
    }
    if (a != b)
    {
        for (int i = 19; i >= 0; i--)
        {
            if (dp[a][i] != dp[b][i])
            {
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        a = dp[a][0];
    }
    return a;
}
 
ll dist(int a, int b)
{
    ll x = lca(a, b);
    return w[a] + w[b] - w[x] - w[dp[x][0]];
}
 
void uni(int x, int y)
{
    x = getfa(x);
    y = getfa(y);
    if (sz[x] < sz[y])
        swap(x, y);
    sz[x] += sz[y];
    fa[y] = x;
    ans *= po(v[x], mod - 2);
    ans %= mod;
 
    ans *= po(v[y], mod - 2);
    ans %= mod;
 
    ll r = 0;
    int a1 = 0, a2 = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ll d = dist(p[x][i], p[y][j]);
            if (d > r)
            {
                r = d;
                a1 = p[x][i];
                a2 = p[y][j];
            }
        }
    }
    if (v[x] > r)
    {
        r = v[x];
        a1 = p[x][0];
        a2 = p[x][1];
    }
    if (v[y] > r)
    {
        r = v[y];
        a1 = p[y][0];
        a2 = p[y][1];
    }
    v[x] = r;
    p[x][0] = a1;
    p[x][1] = a2;
    ans *= r;
    ans %= mod;
 
}
 
void solve()
{
    scanf("%lld", &n);
    ans = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &val[i]);
        fa[i] = i;
        sz[i] = 1;
        p[i][0] = p[i][1] = i;
        deep[i] = 0;
        v[i] = val[i];
        ans *= val[i] % mod;
        ans %= mod;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d%d", &edge[i].u, &edge[i].v);
        add(edge[i].u, edge[i].v);
        add(edge[i].v, edge[i].u);
    }
    dfs(1, 0);
    for (int i = 0; i < 20; i++)
    {
        for (int k = 1; k <= n; k++)
        {
            if (dp[k][i] != 0)
            {
                dp[k][i + 1] = dp[dp[k][i]][i];
            }
        }
    }
    for (int i = 1; i <= n-1; i++)
    {
        scanf("%d", &qus[i]);
    }
    res[n] = ans;
    for (int i = n - 1; i >= 1; i--)
    {
        uni(edge[qus[i]].u, edge[qus[i]].v);
        res[i] = ans;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld\n", res[i]);
    }
}
 
int main()
{
    init();
    solve();
    return 0;
}