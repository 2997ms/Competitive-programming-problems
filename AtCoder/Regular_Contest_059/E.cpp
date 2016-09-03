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
 
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define pb push_back
 
const int maxn = 400 + 5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
 
int n, c;
int a[maxn], b[maxn];
int dp[maxn][maxn], res[maxn][maxn];
 
void solve()
{
    scanf("%d%d", &n, &c);
 
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }
 
    for (int i = 1; i <= 400; i++)
    {
        for (int j = 0; j <= 400; j++)
        {
            dp[i][j] = (j == 0 ? 1 : 1LL*dp[i][j - 1] * i%mod);
            dp[i][j] %= mod;
        }
    }
    for (int i = 1; i <= 400; i++)
    {
        for (int j = 1; j <= 400; j++)
        {
            dp[i][j] += dp[i - 1][j];
            if (dp[i][j] >= mod)
            {
                dp[i][j] -= mod;
            }
        }
    }
    memset(res, 0, sizeof(res));
    res[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                if (!res[i - 1][j - k])continue;
                int t = 0;
                if (k == 0)
                {
                    t = (b[i] - (a[i] - 1) + mod) % mod;
                }
                else
                {
                    t = (dp[b[i]][k] - dp[a[i] - 1][k] + mod) % mod;
                }
                res[i][j] += 1LL*res[i - 1][j - k] * t%mod;
                res[i][j] = (res[i][j] + mod) % mod;
            }
        }
    }
    printf("%d\n", res[n][c]);
}
 
int main()
{
    solve();
    return 0;
}