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
#define LL_INF 0x33ffffffffffffff
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

const int maxn = 505;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

ll n, m, k;
int col[maxn];
ll val[maxn][maxn];
ll dp[105][105][105];//dp[k][m]分成k段,当前的颜色为m的种类数

ll mx(ll x, ll y)
{
    if (x == -1)
    {
        return y;
    }
    else
    {
        return min(x, y);
    }
}

void solve()
{
    scanf("%lld%lld%lld", &n, &m, &k);
    repp(i, 1, n)
    {
        scanf("%d", &col[i]);
    }
    repp(i, 1, n)
    {
        repp(j, 1, m)
        {
            scanf("%lld", &val[i][j]);
        }
    }
    int sum = 1;
    int pre = col[1];   
    ll i, j;
    memset(dp, -1, sizeof(dp));
    if (col[1])
    {
        dp[1][1][col[1]] = 0;
    }
    else
    {
        for (i = 1; i <= m; i++)
        {
            dp[1][1][i] = val[1][i];
        }
    }

    for (i = 2; i <= n; i++)
    {
        for (pre = 1; pre <= m; pre++)
        {
            for (int duan = 1; duan <= k; duan++)
            {
                if (dp[i - 1][duan][pre] == -1)continue;
                if (col[i])
                {
                    if (col[i] == pre)
                    {
                        dp[i][duan][col[i]] = mx(dp[i][duan][col[i]], dp[i - 1][duan][col[i]]);
                    }
                    else
                    {
                        dp[i][duan + 1][col[i]] = mx(dp[i][duan + 1][col[i]], dp[i - 1][duan][pre]);
                    }
                }
                else
                {
                    for (int j = 1; j <= m; j++)
                    {
                        if (j == pre)
                        {
                            dp[i][duan][pre] = mx(dp[i][duan][pre], dp[i - 1][duan][pre] + val[i][j]);
                        }
                        else
                        {
                            dp[i][duan + 1][j] = mx(dp[i][duan + 1][j], dp[i - 1][duan][pre] + val[i][j]);
                        }
                    }
                }
            }

        }
    }
    ll ans = -1;
    for (i = 1; i <= m; i++)
    {
        if (dp[n][k][i] == -1)continue;
        ans = mx(ans, dp[n][k][i]);
    }
    printf("%lld", ans);
}
int main()
{
    solve();
    return 0;
}