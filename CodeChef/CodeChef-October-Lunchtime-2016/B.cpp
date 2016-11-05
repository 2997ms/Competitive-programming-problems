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
#include <unordered_set>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
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
 
const int maxn = (1 << 18) + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
 
ll n, m;
ll val[20], dp1[maxn], dp2[maxn];
 
void solve()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < 1 << n; ++i)
    {
        dp1[i] = 1LL << 60;
        dp2[i] = 1LL << 60;
    }
    rep(i, 0, n)
    {
        scanf("%lld", &val[i]);
        dp1[1 << i] = val[i];
    }
    dp1[0] = dp2[0] = 0;
    repp(i, 1, m)
    {
        ll mask = 0;
        ll p, q;
        scanf("%lld%lld", &p, &q);
        rep(j, 0, q)
        {
            int x; scanf("%d", &x);
            x--;
            mask |= (1 << x);
        }
        dp1[mask] = min(dp1[mask], (ll)p);
    }
    for (int i = (1 << n) - 1; i >= 0; i--)
    {
        for (int k = 0; k < n; k++)
        {
            if ((i >> k) & 1)
            {
                dp1[i ^ (1 << k)] = min(dp1[i ^ (1 << k)], dp1[i]);
            }
        }
    }
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int submask = (mask - 1)&mask;
        dp2[mask] = dp1[mask];
        do
        {
            dp2[mask] = min(dp2[mask], dp2[submask] + dp1[mask^submask]);
            submask = (submask - 1)&mask;
        }while (submask > 0);
    }
    printf("%lld\n", dp2[(1 << n) - 1]);
}
 
int main()
{
 
    int t;
    sa(t);
    while (t--)
    {
        solve();
    }
    return 0;
}