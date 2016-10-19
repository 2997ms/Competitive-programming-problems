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

const int maxn = 2e6 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

ll n, m;
ll a[1005], b[maxn], ans[1005];

int  check(ll x)
{
    priority_queue<int>que;

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        que.push(-a[i]);
        x += a[i];
        if (x <= 0)
        {
            res++;
            int t = que.top();
            que.pop();
            x += t;
        }
    }
    return res;
}

void solve()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld", &b[i]);
    }
    for (int i = 0; i <= n; i++)
    {
        ll le = -1e12;
        ll ri = 1e12;
        while (le < ri)
        {
            ll mid = (le + ri+1) >> 1;
            if (check(mid) >= i)
            {
                le = mid;
            }
            else
            {
                ri = mid - 1;
            }
        }
        ans[i] = le;
    }
    sort(ans, ans + 1 + n);
    for (int i = 1; i <= m; i++)
    {
        int p = upper_bound(ans, ans + n + 1, b[i]) - ans;
        p = n - p;
        printf("%d\n", max(p, 0));
    }
}

int main()
{
    solve();
    return 0;
}