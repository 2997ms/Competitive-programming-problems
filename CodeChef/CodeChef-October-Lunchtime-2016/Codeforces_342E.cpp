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

const int maxn = 2e5 + 5;
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

int cnt, c;
int head[maxn], dep[maxn], red[maxn], dis[maxn];
int fa[maxn][20];

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

void go_up(int &x, int d)
{
    for (int de = 19; de >= 0; de--)
    {
        if (d == 0)break;
        if (d >= (1 << de))
        {
            x = fa[x][de];
            d -= (1 << de);
        }
    }
}

int lca(int u,int v)
{
    if (dep[u] > dep[v])
    {
        go_up(u, dep[u] - dep[v]);
    }
    else if (dep[u] < dep[v])
    {
        go_up(v, dep[v] - dep[u]);
    }
    if (u == v)return u;
    for (int i = 19; i >= 0; i--)
    {
        if (fa[u][i] != fa[v][i])
        {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

void dfs(int x, int f,int d)
{
    dep[x] = d;
    for (int i = head[x]; i != -1; i = edge[i].next)
    {
        int k = edge[i].to;
        if (k == f)continue;
        fa[k][0] = x;
        for (int j = 1; (1 << j) <= d+1; j++)
        {
            fa[k][j] = fa[fa[k][j - 1]][j - 1];
        }
        dfs(k, x, d + 1);
    }
}

void bfs()
{
    queue<int>que;
    for (int i = 1; i <= c; i++)
    {
        que.push(red[i]);
        dis[red[i]] = 0;
    }
    while (!que.empty())
    {
        int x = que.front();
        que.pop();
        for (int h = head[x]; h != -1; h = edge[h].next)
        {
            int g = edge[h].to;
            if (dis[g] > dis[x] + 1)
            {
                dis[g] = dis[x] + 1;
                que.push(g);
            }
        }
    }
}

void solve()
{
    sa(n), sa(m);
    repp(i, 1, n - 1)
    {
        int u, v;
        sa(u), sa(v);
        add(u, v);
        add(v, u);
    }
    dfs(1, -1, 1);
    c++;
    red[c] = 1;
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    repp(i, 1, m)
    {
        int t, v;
        sa(t), sa(v);
        if (t == 1)
        {
            c++;
            red[c] = v;
            if (c == 100)
            {
                bfs();
                c = 0;
            }
        }
        else
        {
            int ans = dis[v];
            for (int h = 1; h <= c; h++)
            {
                int lc = lca(v, red[h]);
                ans = min(ans, dep[v] + dep[red[h]] - 2*dep[lc]);
            }
            printf("%d\n", ans);
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE  
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif
    init();
    solve();
    return 0;
}