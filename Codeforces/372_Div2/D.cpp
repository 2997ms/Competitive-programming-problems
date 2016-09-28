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

int n, m, L, s, t;
int u[maxn], v[maxn], w[maxn];
vector<int>w0;
vector< pair<int, int> >ed[maxn];
set< pair<int, int> >hs;
int vis[maxn];
ll dis[maxn];

void dijkstra(int s, int n)
{
    for (int i = 0; i < n; i++)
    {
        dis[i] = 1e9 + 7;
        vis[i] = 0;
    }
    dis[s] = 0;
    for (int i = 0; i < n; i++)
    {
        hs.insert(make_pair(dis[i], i));
    }
    for (int i = 0; i < n; i++)
    {
        int u = hs.begin()->second;
        hs.erase(hs.begin());

        vis[u] = 1;
        for (int j = 0; j < ed[u].size(); j++)
        {
            int v = ed[u][j].first;
            if (dis[v] > dis[u] + ed[u][j].second)
            {
                hs.erase(make_pair(dis[v], v));
                dis[v] = dis[u] + ed[u][j].second;
                hs.insert(make_pair(dis[v], v));
            }
        }
    }
}

ll check(ll x)
{
    for (int i = 0; i < w0.size(); i++)
    {
        w[w0[i]] = 1 + min(x, (ll)L);
        x -= (w[w0[i]] - 1);
    }
    for (int i = 0; i < n; i++)
    {
        ed[i].clear();
    }
    for (int i = 1; i <= m; i++)
    {
        ed[u[i]].emplace_back(make_pair(v[i], w[i]));
        ed[v[i]].emplace_back(make_pair(u[i], w[i]));
    }
    dijkstra(s, n);
    return dis[t];
}

void solve()
{
    scanf("%d%d%d%d%d", &n, &m, &L, &s, &t);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        if (w[i] == 0)
        {
            w0.emplace_back(i);
        }
    }
    ll le = 0, ri = 1LL*(1e9 + 1)*L;
    if (check(le) > L||check(ri) < L)
    {
        puts("NO");
        return;
    }
    while (le < ri)
    {
        ll mid = (le + ri) >> 1;
        if (check(mid) >= L)
        {
            ri = mid;
        }
        else
        {
            le = mid + 1;
        }
    }
    check(ri);
    puts("YES");
    for (int i = 1; i <= m; i++)
    {
        printf("%d %d %d\n", u[i], v[i], w[i]);
    }
}

int main()
{
    solve();
    return 0;
}