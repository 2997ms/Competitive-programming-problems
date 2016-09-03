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
 
const int maxn = 5000 + 5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
 
int n;
char x[maxn];
int dp[maxn][maxn];
 
void add(int &x, int y)
{
    x += y;
    if (x >= mod)
    {
        x -= mod;
    }
}
 
void solve()
{
    scanf("%d", &n);
    scanf("%s", x);
    int len = strlen(x);
    ll ans = 1;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            add(dp[i][max(j - 1, 0)], dp[i - 1][j]);
            add(dp[i][j + 1], 2 * dp[i - 1][j] % mod);
        }
    }
    ans = dp[n][len];
    int inv2 = po(2, mod - 2);
    for (int i = 1; i <= len; i++)
    {
        ans *= inv2;
        ans %= mod;
    }
    printf("%lld", ans);
}
 
int main()
{
 
    solve();
    return 0;
}