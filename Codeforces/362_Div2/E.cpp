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

const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);

ll n;
ll val[maxn];

ll po(ll a, ll x, ll m)
{
    ll res = 1;
    while (x)
    {
        if (x & 1)
        {
            res = res*a%m;
        }
        a = a*a%m;
        x >>= 1;
    }
    return res;
}

void solve()
{
    ll i, j, k;
    scanf("%lld", &n);

    int f = 1;
    ll two = 1;
    repp(i, 1, n)
    {
        scanf("%lld", &val[i]);
        if (val[i] > 1)
        {
            f = 0;
        }
        val[i] %= (mod - 1);
        two = two*val[i] % (mod - 1);
    }
    two = (two - 1 + mod - 1) % (mod - 1);
    if (f)
    {
        puts("0/1");
        return;
    }
    ll p, q;
    if (two & 1)
    {
        p = ((po(2, two, mod) + 1)) % mod*po(3, mod - 2, mod) % mod;
    }
    else
    {
        p = ((po(2, two, mod) - 1 + mod) % mod)*po(3, mod - 2, mod) % mod;
    }
    q = po(2, two, mod);
    printf("%lld/%lld", p, q);
}

int main()
{
     solve();
     return 0;
}