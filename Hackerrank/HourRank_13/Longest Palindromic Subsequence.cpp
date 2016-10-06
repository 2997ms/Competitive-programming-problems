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

const int maxn = 3e3 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

int n, k;
char x[maxn], rev[maxn];
int lps[maxn][maxn], lcs[maxn][maxn];
int dp[maxn][30];

int LPS(int s, int t)
{
    if (s > t)
    {
        return 0;
    }
    if (s == t)
    {
        return lps[s][t] = 1;
    }
    if (lps[s][t] != -1)
    {
        return lps[s][t];
    }
    int res = 0;
    if (x[s] == x[t])
    {
        res = max(res, 2 + LPS(s + 1, t - 1));
    }
    res = max(res, LPS(s + 1, t));
    res = max(res, LPS(s, t - 1));
    return lps[s][t] = res;
}

int LCS(int s, int t)
{
    if (s <= 0 || t <= 0)
    {
        return 0;
    }
    if (lcs[s][t] != -1)
    {
        return lcs[s][t];
    }
    int res = 0;
    if (x[s] == rev[t])
    {
        res = max(res, 1 + LCS(s - 1, t - 1));
    }
    res = max(res, LCS(s - 1, t));
    res = max(res, LCS(s, t - 1));
    return lcs[s][t] = res;
}

int idx(char v)
{
    return v - 'a';
}

void solve()
{
    scanf("%d%d", &n, &k);
    scanf("%s", x + 1);
    for (int i = 1; i <= n; i++)
    {
        rev[i] = x[n - i + 1];
    }
    memset(lps, -1, sizeof(lps));
    memset(lcs, -1, sizeof(lps));
    memset(dp, 0, sizeof(dp));

    int cur = LPS(1, n);
    int res = 0;
    if (k == 0)
    {
        cout << (n + 1) * 26 << endl;
        return;
    }
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            dp[i][j] = 1 + 2 * LCS(i - 1, n - i + 1);
        }
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                dp[i][idx(x[j])] = max(dp[i][idx(x[j])], 2 + LPS(i, j - 1) + 2 * LCS(i - 1, n - (j + 1) + 1));
            }
            else
            {
                dp[i][idx(x[j])] = max(dp[i][idx(x[j])], 2 + LPS(j + 1, i-1) + 2 * LCS(j - 1, n - (i) + 1));
            }
        }

        for (int j = 0; j < 26; j++)
        {
            if (dp[i][j] - cur >= k)
            {
                res++;
            }
        }
    }
    printf("%d\n", res);
}

int main()
{
    CASET
    {
        solve();
    }
    return 0;
}