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
 
const int maxn = 1500;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
 
int n, m;
int st, en;
struct ed
{
    int u;
    int v;
    int w;
}val[maxn];
int cnt[maxn], vis[maxn];
double dis[maxn];
vector< pair <int, double> > edge[maxn];
 
void init()
{
    for (int i = 1; i <= n; i++)
    {
        edge[i].clear();
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        double w;
        u = val[i].u;
        v = val[i].v;
        w = val[i].w;
        edge[u].push_back(make_pair(v, w));
    }
}
 
bool check(int st, int en,double va)
{
    queue<int>que;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e9;
        cnt[i] = 0;
        vis[i] = 0;
    }
    que.push(st);
    dis[st] = 0;
    vis[st] = 1;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        cnt[cur]++;
        vis[cur] = 0;
        if (cnt[cur] > n)
        {
            dis[cur] = -1e9;
        }
        for (int x = 0; x < edge[cur].size(); x++)
        {
            int v = edge[cur][x].first;
            if (dis[v] > dis[cur] + edge[cur][x].second - va)
            {
                dis[v] = dis[cur] + edge[cur][x].second - va;
                if (!vis[v] && cnt[v] <= n)
                {
                    vis[v] = 1;
                    que.push(v);
                }
            }
        }
    }
    return dis[en] < 0;
}
 
void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        val[i].u = u;
        val[i].v = v;
        val[i].w = w;
    }
    init();
    scanf("%d%d", &st, &en);
    double le = 0, ri = 100;
    if (!check(st, en, 1000))
    {
        puts("-1");
        return;
    }
    double mid = 0;
    while (ri - le > (1e-8))
    {
        mid = (ri + le) / 2.0;
        if (check(st, en, mid))
        {
            ri = mid;
        }
        else
        {
            le = mid;
        }
    }
    printf("%.7lf\n", (ri + le) / 2.0);
}
 
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}