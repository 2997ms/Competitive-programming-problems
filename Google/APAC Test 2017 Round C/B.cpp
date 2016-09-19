//#pragma comment(linker, "/STACK:102400000,102400000") 
#pragma warning(disable:4996)
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

const int maxn = 3050;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

int r, c, k;
ll res[maxn];
int val[maxn][maxn], dp[maxn][maxn];

void solve()
{
    cin >> r >> c >> k;
    repp(i, 1, r)
    {
        repp(j, 1, c)
        {
            val[i][j] = 1;
        }
    }
    int u, v;
    repp(i, 1, k)
    {
        cin >> u >> v;
        u++, v++;
        val[u][v] = 0;
    }
    mem(dp, 0);

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (val[i][j])
            {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    mem(res, 0);
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (dp[i][j])
            {
                res[dp[i][j]]++;
            }
        }
    }
    for (int i = 3000; i >= 1; i--)
    {
        res[i] += res[i + 1];
    }
    ll sum = 0;
    for (int i = 3000; i >= 1; i--)
    {
        sum += res[i];
    }
    printf("%lld\n", sum);
}
int main()
{
#ifndef ONLINE_JUDGE  
    freopen("B-large.in", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    repp(i, 1, t)
    {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}