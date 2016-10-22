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
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)

const int maxn = 2e5 + 2;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

ll n;
ll val[maxn], sum[maxn];

void solve()
{
    scanf("%lld", &n);
    repp(i, 1, n)
    {
        scanf("%lld", &val[i]);
        sum[i] = sum[i - 1] + val[i];
    }
    ll res = 0;
    for (int i = n; i >= 2; i--)
    {
        if (i == n)res = sum[i];
        else if (res < sum[i] - res)
        {
            res = sum[i] - res;
        }
    }
    printf("%lld\n", res);
}

int main()
{
#ifndef ONLINE_JUDGE  
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif
    solve();
    return 0;
}