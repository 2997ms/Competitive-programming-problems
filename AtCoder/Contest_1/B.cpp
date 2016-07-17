/*
 反应快一点啦，就是在平行四边形里面递归啊。。。
 */
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
typedef pair<int, ll> pill;

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

const int maxn = 405;
const ll mod = 1000000007;
const double PI = acos(-1.0);

ll n, x;

ll cal(ll n, ll x)
{
    if (x <= 0)
    {
        return 3 * n;
    }
    if (n % x == 0 )
    {
        return n * 3LL;
    }
    else
    {
        return n / x*x * 3LL + cal(x, n%x);
    }
}

void solve()
{
    ll res = 0;
    if (x * 2LL >= n)
    {
        res = cal(x, n - x);
    }
    else
    {
        res = cal(n - x, x);
    }
    printf("%lld\n", res);
}
int main()
{
    while (cin >> n >> x)
    {
        solve();
    }
    return 0;
}