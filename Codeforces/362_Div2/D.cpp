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

const int maxn = 400005;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);

double dp[maxn];

struct no
{
    int to;
    int nex;
}edge[maxn];

int cnt, n;
int head[maxn], num[maxn], vis[maxn];

void added(int u, int v)
{
    cnt++;
    edge[cnt].to = v;
    edge[cnt].nex = head[u];
    head[u] = cnt;
}

void init()
{
    cnt = 0;
    mem(edge, -1);
    mem(head, -1);
}

void dfs1(int x)
{
    num[x] = 1;
    vis[x] = 1;
    int i, j, k;
    for (i = head[x]; i != -1; i = edge[i].nex)
    {
        k = edge[i].to;
        if (vis[k])continue;
        dfs1(k);
        num[x] += num[k];
    }
}

void dfs2(int x,int fa)
{
    vis[x] = 1;
    int i, j, k;
    int res = 0;
    for (i = head[x]; i != -1; i = edge[i].nex)
    {
        k = edge[i].to;
        if (vis[k])continue;
        res++;
    }

    for (i = head[x]; i != -1; i = edge[i].nex)
    {
        k = edge[i].to;
        if (vis[k])continue;
        dp[k] = dp[x] + 1.0 + (num[x] - num[k] - 1) / 2.0;
        dfs2(k, x);
    }
}

void solve()
{
    int i, j, k;
    sa(n);
    for (i = 2; i <= n; i++)
    {
        sa(k);
        added(k, i);
        added(i, k);
    }

    mem(vis, 0);
    dfs1(1);

    dp[1] = 1.0;
    mem(vis, 0);
    dfs2(1, 1);

    for (i = 1; i <= n - 1; i++)
    {
        printf("%.8lf ", dp[i]);
    }
    printf("%.8lf", dp[n]);
    printf("\n");
}

int main()
{
     init();
     solve();
     return 0;
}