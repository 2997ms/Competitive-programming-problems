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
 
const int maxn = 20;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const ll hax = 1e6 + 7;
 
const int MOD = 1e9 + 7;
 
int n, x, y, z;
ll dp[44][1 << 18];
 
void solve()
{
    int i, j, k;
    int mask = 0;
    sa(n), sa(x), sa(y), sa(z);
 
    mask |= (1 << z);
    mask |= (1 << (y + z));
    mask |= (1 << (x + y + z));
    int s = (1 << (x + y + z + 1));
    s--;
    ll res = 10;
    for (i = 2; i <= n; i++)
    {
        res = res * 10 % mod;
    }
    mem(dp, 0);
    dp[0][1] = 1;
    for (i = 1; i <= n; i++)
    {
        for (int sta = 0; sta <= s; sta++)
        {
            for (k = 1; k <= 10; k++)
            {
                int state = ((sta << k)&s) + 1;
                if ((state&mask) == mask)continue;
                dp[i][state] += dp[i - 1][sta];
                dp[i][state] %= mod;
            }
        }
    }
    for (int sta = 0; sta < s; sta++)
    {
        res = res - dp[n][sta];
        res %= mod;
    }
    res = (res%mod + mod) % mod;
    printf("%lld\n", res);
}
 
int main()
{
    solve();
    return 0;
}