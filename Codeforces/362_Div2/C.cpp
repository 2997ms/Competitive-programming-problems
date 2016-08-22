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

const int maxn = 100005;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);

map<pair<int, ll>, ll>hax;

int q;
void solve()
{
    int i, j, k;
    ll u, v, w;
    repp(i, 1, q)
    {
        int oper;
        sa(oper);

        if (oper == 1)
        {
            scanf("%lld%lld%lld", &u, &v, &w);
            while (v != u)
            {
                if (v > u)
                {
                    hax[mp(v % 2, v / 2)] += w;
                    v = v / 2;
                }
                else
                {
                    hax[mp(u % 2, u / 2)] += w;
                    u = u / 2;
                }
            }
        }
        else
        {
            ll res=0;
            scanf("%lld%lld", &u, &v);
            while (v != u)
            {
                if (v > u)
                {
                    res += hax[mp(v % 2, v / 2)];
                    v = v / 2;
                }
                else
                {
                    res += hax[mp(u % 2, u / 2)];
                    u = u / 2;
                }
            }
            printf("%lld\n", res);
        }
    }
}

int main()
{
     sa(q);
     solve();
     return 0;
}