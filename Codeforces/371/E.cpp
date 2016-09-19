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

ll m, n;
ll val[maxn], dp[maxn];

bool cal(int st, ll x)
{
    if (val[st] > x)
    {
        return false;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -INF;
    }
    for (int i = 1; i < st; i++)
    {
        dp[st] = val[i] + x;
    }
    if (st == 1)
    {
        dp[1] = val[1];
    }
    for (int i = st + 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        if (dp[i - 1] >= val[i] - 1)
        {
            dp[i] = max(dp[i], val[i] + x);
        }
        if (dp[i - 1] >= val[i] - x - 1)
        {
            dp[i] = max(dp[i], val[i]);
        }
        if (i >= 3 && dp[i - 2] >= val[i] - x - 1)
        {
            dp[i] = max(dp[i], val[i - 1] + x);
        }
    }
    if (dp[n] >= min(m, m - (x - (val[st] - 1))))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check(int x)
{
    return cal(1, x) || cal(2, x);

}

void solve()
{
    scanf("%lld%lld", &m, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &val[i]);
    }
    sort(val + 1, val + n + 1);
    pair<ll, ll>bes(val[1] + m - val[n], 1);
    for (int i = 2; i <= n; i++)
    {
        pair<ll, ll>r(val[i] - val[i - 1], i);
        bes = max(bes, r);
    }
    rotate(val + 1, val + bes.second, val + 1 + n);
    for (int i = n; i >= 1; i--)
    {
        val[i] -= val[1];
        while (val[i] < 0)
        {
            val[i] += m;
        }
    }
    int le = 0;
    int ri = val[1] + m - val[n] - 1;
    while (le < ri)
    {
        int mid = (le + ri) >> 1;
        if (check(mid))
        {
            ri = mid;
        }
        else
        {
            le = mid + 1;
        }
    }
    printf("%d\n", le);
}

int main()
{
    solve();

    return 0;
}