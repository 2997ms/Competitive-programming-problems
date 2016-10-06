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
#include <ctime>
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

const int maxn = 205;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

int n, m;
set<int>ed[maxn];
int out[maxn], in[maxn];
vector<pair<int, int>>res;

void dfs(int x)
{
    while (ed[x].size())
    {
        auto it = ed[x].begin();
        int p = *it;
        res.push_back(mp(x, *it));
        ed[x].erase(it);
        ed[p].erase(x);
        dfs(p);
    }
}

void solve()
{
    scanf("%d%d", &n, &m);
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    for (int i = 1; i <= n + 1; i++)
    {
        ed[i].clear();
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        out[x]++;
        in[y]++;
        ed[x].insert(y);
        ed[y].insert(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((out[i] + in[i]) % 2)
        {
            ed[i].insert(n + 1);
            ed[n + 1].insert(i);
        }
        else
        {
            ans++;
        }
    }
    res.clear();
    for (int i = 1; i <= n; i++)
    {
        dfs(i);
    }
    printf("%d\n", ans);
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i].first == n + 1 || res[i].second == n + 1)continue;       
        printf("%d %d\n", res[i].first, res[i].second);     
    }
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