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

const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

ll n;
ll val[maxn], op[maxn], vis[maxn];
ll fa[maxn], sz[maxn];
ll num[maxn], res[maxn];

int getfa(int x)
{
    return x == fa[x] ? x : getfa(fa[x]);
}

void solve()
{
    scanf("%lld", &n);
    repp(i, 1, n)
    {
        scanf("%lld", &val[i]);
    }
    repp(i, 1, n)
    {
        scanf("%lld", &op[i]);
    }
    repp(i, 1, n)
    {
        sz[i] = 1;
        fa[i] = i;
        num[i] = 0;
    }
    ll maxx = 0;
    for (int i = n; i >= 1; i--)
    {
        res[i] = maxx;

        vis[op[i]] = 1;
        num[op[i]] = val[op[i]];
        if (vis[op[i] - 1])
        {
            int x = getfa(op[i]);
            int f = getfa(op[i] - 1);
            if (num[x] < num[f])
            {
                num[f] += num[x];
                fa[x] = f;
            }
            else
            {
                num[x] += num[f];
                fa[f] = x;
            }
        }
        if (vis[op[i] + 1])
        {
            int x = getfa(op[i]);
            int f = getfa(op[i] + 1);
            if (num[x] < num[f])
            {
                num[f] += num[x];
                fa[x] = f;
            }
            else
            {
                num[x] += num[f];
                fa[f] = x;
            }
        }
        int f = getfa(op[i]);
        if (num[f] > maxx)
        {
            maxx = num[f];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld\n", res[i]);
    }
}


int main()
{
    solve();
    return 0;
}