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

const int maxn = 2e3 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

ll n, m, k, s;
pair<ll, ll>val[maxn];
ll fac[200005], inv[200005];
ll dp[21][maxn];

void init()
{
    fac[0] = 1;
    fac[1] = 1;
    inv[0] = 1;
    inv[1] = 1;
    for (ll i = 2; i <= 2e5; i++)
    {
        fac[i] = 1LL*fac[i - 1] * i%mod;
        inv[i] = 1LL*(mod - mod / i)*inv[mod%i] % mod;
    }
    for (ll i = 1; i <= 2e5; i++)
    {
        inv[i] = 1LL*inv[i] * inv[i - 1] % mod;
    }
}

ll c(ll x, ll y)
{
    if (y > x)return 0;
    return 1LL*fac[x] * inv[x-y] % mod*inv[y] % mod;
}

void solve()
{

    scanf("%I64d%I64d%I64d%I64d", &n, &m, &k, &s);

    for (int i = 1; i <= k; i++)
    {
        scanf("%I64d%I64d", &val[i].first, &val[i].second);

    }

    k++;
    val[k].first = 1, val[k].second = 1;
    sort(val + 1, val + k + 1);

    ll res = 0;
    for (int d = 0; d <= 20; d++)
    {
        for (int i = k; i >= 1; i--)
        {
            dp[d][i] = c(n + m - val[i].first - val[i].second, n - val[i].first);
            for (int j = i + 1; j <= k; j++)
            {
                dp[d][i] -= 1LL*c(val[j].first + val[j].second - val[i].first - val[i].second, val[j].first - val[i].first) * dp[d][j] % mod;
                if (dp[d][i] < 0)
                {
                    dp[d][i] += mod;
                }
            }
            for (int xd = 0; xd < d; xd++)
            {
                dp[d][i] -= dp[xd][i];
                if (dp[d][i] < 0)
                {
                    dp[d][i] += mod;
                }
            }
        }
        res = res + 1LL*s*dp[d][1] % mod;
        if (res >= mod)
        {
            res -= mod;
        }
        s = (s + 1) >> 1;
    }
    ll sum = c(n + m - 2, n - 1);
    ll t = po(sum, mod - 2, mod);
    ll par = 0;
    for (int d = 0; d <= 20; d++)
    {
        par += dp[d][1];
        if (par >= mod)
        {
            par -= mod;
        }
    }
    res = (res + sum - par + mod) % mod;
    res = res*t%mod;
    printf("%I64d\n", res);

}

int main()
{

    init();
    solve();
    return 0;
}