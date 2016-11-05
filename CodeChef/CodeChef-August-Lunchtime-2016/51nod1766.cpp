#pragma comment(linker, "/STACK:102400000,102400000") 
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
#include <set>
#include <map>
using namespace std;
typedef long long ll;

#define LL_INF 0x3fffffffffffffff
#define INT_INF 0x3fffffff
#define mem(a, b) memset(a, b, sizeof(a))
#define pper(i,n,m) for(int i = n;i >= m; i--)
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int maxn = 5e5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);

struct ed
{
    int to;
    int next;
    int w;
}edge[2 * maxn];

int n, edgen, num;
int vis[maxn], head[maxn], seq[2 * maxn], deep[maxn], dis[maxn], pos[maxn], lo[2 * maxn], st[maxn][30];

inline void gn(int &x)
{
    int sg = 1; char c;
    while (((c = getchar())<'0' || c>'9') && c != '-');
    c == '-' ? (sg = -1, x = 0) : (x = c - '0');
    while ((c = getchar()) >= '0'&&c <= '9')
        x = x * 10 + c - '0';
    x *= sg;
}

void init()
{
    edgen = 0;
    num = 0;
    memset(head, -1, sizeof(head));
    memset(edge, -1, sizeof(edge));
}

void addedge(int u, int v, int w)
{
    edgen++;
    edge[edgen].to = v;
    edge[edgen].w = w;
    edge[edgen].next = head[u];
    head[u] = edgen;
}

void dfs(int x, int fa)
{
    int i, j, k, w;
    seq[++num] = x;
    pos[x] = num;
    vis[x] = 1;
    for (i = head[x]; i != -1; i = edge[i].next)
    {
        k = edge[i].to;
        w = edge[i].w;
        if (vis[k])
            continue;
        deep[k] = deep[x] + 1;
        dis[k] = dis[x] + w;

        dfs(k, x);
        seq[++num] = x;
    }
}

int dep(int x, int y)
{
    return deep[seq[x]] < deep[seq[y]] ? x : y;
}

int lca(int x, int y)
{
    int k1 = pos[x];
    int k2 = pos[y];
    if (k1 > k2)
        swap(k1, k2);
    int k = lo[k2 - k1 + 1];
    int res = seq[dep(st[k1][k], st[k2 - (1 << k) + 1][k])];
    return res;
}

int dist(int x, int y)
{
    return dis[x] + dis[y] - 2 * dis[(lca(x, y))];
}

void init_st()
{
    int i, j, k;
    
    lo[0] = -1;
    lo[1] = 0;
    for (i = 2; i <= num; i++)
    {
        lo[i] = lo[i >> 1] + 1;
    }
    for (i = 1; i <= num; i++)
    {
        st[i][0] = i;
    }
    for (k = 1; k <= lo[num]; k++)
    {
        for (i = 1; i + (1 << k) - 1 <= num; i++)
        {
            st[i][k] = dep(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
        }
    }
}

pair<int, int>merge(pair<int, int>x, pair<int, int>y, int f)
{
    int r = -1;
    pair<int, int>res = mp(0, 0);
    int a = x.ff, b = x.ss, c = y.ff, d = y.ss;
    if (r < dist(a, c))
    {
        r = dist(a, c);
        res = mp(a, c);
    }
    if (r < dist(a, d))
    {
        r = dist(a, d);
        res = mp(a, d);
    }
    if (r < dist(b, c))
    {
        r = dist(b, c);
        res = mp(b, c);
    }
    if (r < dist(b, d))
    {
        r = dist(b, d);
        res = mp(b, d);
    }
    if (f)
    {
        if (r < dist(a, b))
        {
            r = dist(a, b);
            res = mp(a, b);
        }
        if (r < dist(c, d))
        {
            r = dist(c, d);
            res = mp(c, d);
        }
    }
    return res;
}

struct no
{
    int le;
    int ri;
    pair<int, int>val;
}node[4 * maxn];

void build(int root, int le, int ri)
{
    node[root].le = le;
    node[root].ri = ri;
    if (le == ri)
    {
        node[root].val = mp(le, le);
        return;
    }
    int mid = (le + ri) >> 1;
    build(root * 2, le, mid);
    build(root * 2 + 1, mid + 1, ri);

    node[root].val = merge(node[root * 2].val, node[root * 2 + 1].val, 1);
}

pair<int, int> query(int root, int le, int ri)
{
    if (node[root].le == le&&node[root].ri == ri)
    {
        return node[root].val;
    }
    int mid = (node[root].le + node[root].ri) >> 1;
    if (ri <= mid)
    {
        return query(root * 2, le, ri);
    }
    else if (le >= mid + 1)
    {
        return query(root * 2 + 1, le, ri);
    }
    else
    {
        pair<int, int>t1 = query(root * 2, le, mid);
        pair<int, int>t2 = query(root * 2 + 1, mid + 1, ri);
        return merge(t1, t2, 1);
    }
}

void solve()
{
    int q;
    int i, j, k;
    int x, y, z;

    gn(n);
    repp(i, 1, n - 1)
    {
        gn(x), gn(y), gn(z);
        addedge(x, y, z);
        addedge(y, x, z);
    }

    dfs(1, -1);

    init_st();
    lca(3, 5);
    build(1, 1, n);

    gn(q);
    pair<int, int>t1, t2, res;
    repp(i, 1, q)
    {
        int a, b, c, d;
        gn(a), gn(b), gn(c), gn(d);
        t1 = query(1, a, b);
        t2 = query(1, c, d);
        res = merge(t1, t2, 0);
        printf("%d\n", dist(res.ff, res.ss));
    }
}

int main()
{
    init();
    solve();
    return 0;
}