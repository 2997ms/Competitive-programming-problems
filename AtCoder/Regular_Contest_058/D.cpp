#pragma comment(linker, "/STACK:102400000,102400000") 
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
 
const int maxn = 2e5 + 1;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
 
ll po(ll x, ll y)
{ 
    ll res = 1; 
    x %= mod;
    while (y)
    {
        if (y & 1)
            res = res*x%mod;
        x = x*x%mod;
        y >>= 1;
    }
    return res;
}
 
ll fac[maxn], inv[maxn];
void init()
{
    int i, j, k;
    fac[0] = 1;
    inv[0] = 1;
    int up = 2e5;
    for (i = 1; i <= up; i++)
    {
        fac[i] = fac[i - 1] * i%mod;
        inv[i] = po(fac[i], mod - 2);
    }
}
 
int h, w, x, y;
ll c(ll x, ll y)
{
    return fac[x] * inv[y] % mod*inv[x - y] % mod;
}
 
void solve()
{
    sa(h), sa(w), sa(x), sa(y);
    int i, j, k;
    int row = h - x;
    ll res = 0;
    int u, v;
    for (i = y + 1; i <= w; i++)
    {
        u = row, v = i;
        res = res + (c(u + v - 2, u - 1)*c(h + w - (u + 1 + v), h - u - 1)) % mod;
        res %= mod;
    }
    printf("%lld\n", res);
}
 
int main()
{
 
    init();
    solve();
    return 0;
}