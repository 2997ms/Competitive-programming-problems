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

const int maxn = 1e3 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

int n, m;
int lo[maxn],val[maxn][maxn],sum[maxn][maxn];
int dp[1001][11][1001][11];

void init_rmq()
{
    lo[0] = -1;
    for (int i = 1; i <= 1000; i++)
    {
        lo[i] = lo[i >> 1] + 1;
    }
    for (int i = 0; (1 << i) <= n; i++)
    {
        for (int j = 0; (1 << j) <= m; j++)
        {
            for (int x = 1; x + (1 << i) - 1 <= n; x++)
            {
                for (int y = 1; y + (1 << j) - 1 <= m; y++)
                {
                    if (!i&&!j)
                    {
                        dp[x][i][y][j] = sum[x][y];
                    }
                    else if (i == 0)
                    {
                        dp[x][i][y][j] = max(dp[x][i][y][j - 1], dp[x][i][y + (1 << (j - 1))][j - 1]);
                    }
                    else if (j == 0)
                    {
                        dp[x][i][y][j] = max(dp[x][i - 1][y][j], dp[x + (1 << (i - 1))][i - 1][y][j]);
                    }
                    else
                    {
                        dp[x][i][y][j] = max(dp[x][i - 1][y][j - 1], dp[x + (1 << (i - 1))][i - 1][y][j - 1]);
                        dp[x][i][y][j] = max(dp[x][i][y][j], max(dp[x][i - 1][y + (1 << (j - 1))][j - 1], dp[x + (1 << (i - 1))][i - 1][y + (1 << (j - 1))][j - 1]));
                    }
                }
            }
        }
    }
}

int check(int x1, int y1, int x2, int y2)
{
    int t1 = lo[x2 - x1 + 1];
    int t2 = lo[y2 - y1 + 1];
    x2 = x2 - (1 << (t1)) + 1;
    y2 = y2 - (1 << (t2)) + 1;
    int res = max(dp[x1][t1][y1][t2], dp[x1][t1][y2][t2]);
    res = max(res, max(dp[x2][t1][y1][t2], dp[x2][t1][y2][t2]));
    return res;
}

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &val[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (val[i][j])
            {
                sum[i][j] = min(min(sum[i - 1][j], sum[i][j - 1]), sum[i - 1][j - 1]) + 1;
            }
            else
            {
                sum[i][j] = 0;
            }
        }
    }
    init_rmq();
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int xx1, yy1;
        int xx2, yy2;
        scanf("%d%d%d%d", &xx1, &yy1, &xx2, &yy2);

        int le = 0;
        int ri = min(xx2 - xx1 + 1, yy2 - yy1 + 1);
        while (le < ri)
        {
            int mid = (le + ri + 1) >> 1;
            if (check(xx1 + mid - 1, yy1 + mid - 1, xx2, yy2) >= mid)
            {
                le = mid;
            }
            else
            {
                ri = mid - 1;
            }
        }
        printf("%d\n", le);
    }
}

int main()
{
    solve();
    return 0;
}