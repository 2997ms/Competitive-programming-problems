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

int L, n, p, T;
int dp[maxn], en[maxn];

void upd(int x, int presum, int s, int e)
{
    ll t = presum + (e - s) / p;
    if (t > dp[x])
    {
        dp[x] = t;
        en[x] = s + (e - s) / p*p;
    }
    else if (t == dp[x])
    {
        en[x]=min(en[x], s + (e - s) / p*p);
    }
}

void solve()
{
    scanf("%d%d%d%d", &L, &n, &p, &T);
    
    int pre = 0;
    en[pre] = -T;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if (pre)
        {
            pre--;
        }
        for (; pre < i&&en[pre] + T <= v; pre++)
        {
            if (en[pre] + T >= u)
            {
                upd(i, dp[pre], en[pre]+T, v);
            }
            else
            {
                upd(i, dp[pre], u, v);
            }
        }
        res = max(res, dp[i]);
        if (dp[i] < dp[i - 1])
        {
            dp[i] = dp[i - 1];
            en[i] = en[i - 1];
        }
        else if(dp[i]==dp[i-1])
        {
            en[i] = min(en[i], en[i - 1]);
        }
    }
    printf("%d", dp[n]);
}

int main()
{
    solve();
    return 0;
}