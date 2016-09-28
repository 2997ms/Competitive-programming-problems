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

const int maxn = 2e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

void gcdex(ll a, ll b, ll &d, ll &x, ll &y)
{
    if (!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        gcdex(b, a%b, d, y, x);
        y -= x*(a / b);
    }
}

ll inv(ll a, ll b)
{
    ll d, x, y;
    gcdex(a, b, d, x, y);
    return d == 1 ? (x%b + b) % b : -1;
}

ll n, m;
int cnt, son_cnt;
int head[maxn], vis[maxn];
int num[maxn], num_m[maxn], lt[maxn];//每个节点的子节点数量，最大节点数量，子节点标记
ll res, r2;
ll po10[maxn], inv10[maxn];
struct ed
{
    int val;
    int to;
    int next;
}edge[maxn];

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(edge, -1, sizeof(edge));
    memset(vis, 0, sizeof(vis));

    po10[0] = 1, inv10[0] = 1;
    int tem = inv(10, m);

    for (int i = 1; i <= n; i++)
    {
        po10[i] = po10[i - 1] * 10 % m;
        inv10[i] = inv10[i - 1] * tem%m;
    }
    res = 0;
    r2 = 0;
}

void dfs_son(int x, int fa)
{
    son_cnt++;
    lt[son_cnt] = x;
    num[x] = 1;
    num_m[x] = 0;
    for (int i = head[x]; i != -1; i = edge[i].next)
    {
        int k = edge[i].to;
        if (k == fa || vis[k])continue;
        dfs_son(k, x);
        num[x] += num[k];
        num_m[x] = max(num_m[x], num[k]);
    }
}

int getroot(int x)
{
    son_cnt = 0;
    dfs_son(x, -1);

    int min_sz = INF;
    int res = x;
    for (int i = 1; i <= son_cnt; i++)
    {
        int tem = max(son_cnt - num[lt[i]], num_m[lt[i]]);//找出最大节点数量最少的那个 就是树根
        if (tem < min_sz)
        {
            min_sz = tem;
            res = lt[i];
        }
    }
    return res;
}

map<ll, ll>hax;
vector<int>node_son;

void dfs1(int x, int fa, int dis,int w)
{
    if (w == 0)
    {
        r2++;
    }
    res += hax[1LL*(m - w)*inv10[dis] % m];

    for (int i = head[x]; i != -1; i = edge[i].next)
    {
        int k = edge[i].to;
        if (vis[k] || k == fa)continue;
        dfs1(k, x, dis + 1, (w * 10LL %m + edge[i].val) % m);
    }
}

void dfs2(int x, int fa, int dis, int w)
{
    if (w == 0)
    {
        r2++;
    }
    hax[w]++;

    for (int i = head[x]; i != -1; i = edge[i].next)
    {
        int k = edge[i].to;
        if (vis[k] || k == fa)continue;
        dfs2(k, x, dis + 1, (1LL*w + 1LL*edge[i].val*po10[dis]%m) % m);
    }
}

void cal(int x)
{
    node_son.clear();
    hax.clear();
    for (int i = head[x]; i != -1; i = edge[i].next)
    {
        int k = edge[i].to;
        if (vis[k])continue;
        node_son.emplace_back(i);
        dfs1(k, x, 1, edge[i].val%m);
        dfs2(k, x, 1, edge[i].val%m);
    }

    reverse(node_son.begin(), node_son.end());
    hax.clear();
    for (int i = 0; i < node_son.size(); i++)
    {
        int k = edge[node_son[i]].to;
        dfs1(k, x, 1, edge[node_son[i]].val%m);
        dfs2(k, x, 1, edge[node_son[i]].val%m);
    }
}

void dfs(int x)
{
    int root = getroot(x);
    cal(root);

    vis[root] = 1;
    for (int i = head[root]; i != -1; i = edge[i].next)
    {
        int k = edge[i].to;
        if (vis[k])continue;
        dfs(k);
    }
}

void add(int u, int v, int w)
{
    edge[cnt].to = v;
    edge[cnt].val = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void solve()
{
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    dfs(0);
    printf("%lld\n", res + r2 / 2);
}


int main()
{
    scanf("%lld%lld", &n, &m);
    init();
    solve();
    return 0;
}