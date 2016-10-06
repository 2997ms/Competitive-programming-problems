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
int vis[maxn], num[maxn], fac[maxn][25];

void init()
{
    num[1] = 1;
    fac[1][1] = 1;
    int up = 1e5;
    for (int i = 2; i <= up; i++)
    {
        if (vis[i])continue;
        for (int j = i; j <= up; j += i)
        {
            vis[j] = 1;
            num[j]++;
            fac[j][num[j]] = i;
        }
    }
}

ll dfs(int idx, int up, int x)
{
    ll res = 0;
    for (int i = idx; i <= num[x]; i++)
    {
        res += (up / fac[x][i]) - dfs(i + 1, up / fac[x][i], x);
    }
    return res;
}

void solve()
{
    scanf("%lld", &n);
    ll res = 0;
    for (ll i = 2; i*i <= n; i++)
    {
        ll k = n / i;
        ll ans = k - i;
        ll t = dfs(1, k, i) - dfs(1, i, i);
        res += ans - t;
    }
    printf("%lld\n", res);
}

int main()
{
    init();
    solve();
    return 0;
}