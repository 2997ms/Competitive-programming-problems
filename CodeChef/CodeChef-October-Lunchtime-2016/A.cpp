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
#include <unordered_set>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
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
 
const int maxn = 3e6 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
 
ll v[5][5];
void solve()
{
    ll res = 0;
    for (int i = 1; i <= 3; i++)
    {
        ll t = 0;
        for (int j = 1; j <= 3; j++)
        {
            scanf("%lld", &v[i][j]);
            t += v[i][j];
        }
        res = max(res, t);
    }
    for (int i = 1; i <= 3; i++)
    {
        ll t = 0;
        for (int j = 1; j <= 3; j++)
        {
            t += v[j][i];
        }
        res = max(res, t);
    }
    if (res % 2 == 0)
        res--;
    res = max(res, 0LL);
    printf("%lld\n", res);
}
 
int main()
{
    int t;
    sa(t);
    while (t--)
    {
        solve();
    }
    return 0;
}