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

const int maxn = 4e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

int n, m;
int s, t, ds, dt;
int u[maxn], v[maxn];
int fa[maxn], val[maxn], toS[maxn], toT[maxn], cnt[5];
vector< pair<int,int> >res;

int getfa(int x)
{
    return x == fa[x] ? fa[x] : fa[x] = getfa(fa[x]);
}

void solve()
{
    scanf("%d%d", &n, &m);
    repp(i, 1, m)
    {
        scanf("%d%d", &u[i], &v[i]);
    }
    scanf("%d%d%d%d", &s, &t, &ds, &dt);

    repp(i, 1, n)
    {
        fa[i] = i;
    }
    repp(i, 1, m)
    {
        if (u[i] == s || u[i] == t || v[i] == s || v[i] == t)continue;
        int x = getfa(u[i]);
        int y = getfa(v[i]);
        if (x == y)continue;
        fa[x] = y;
        res.push_back(mp(u[i], v[i]));
    }

    repp(i, 1, m)
    {
        if (u[i] == s || u[i] == t || v[i] == s || v[i] == t)
        {
            if (u[i] == s&&v[i] != t)
            {
                int k = getfa(v[i]);
                val[k] |= 1;
                toS[k] = v[i];
            }
            if (u[i] == t&&v[i] != s)
            {
                int k = getfa(v[i]);
                val[k] |= 2;
                toT[k] = v[i];
            }
            if (u[i] != s&&v[i] == t)
            {
                int k = getfa(u[i]);
                val[k] |= 2;
                toT[k] = u[i];
            }
            if (u[i] != t&&v[i] == s)
            {
                int k = getfa(u[i]);
                val[k] |= 1;
                toS[k] = u[i];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == s || i == t || getfa(i) != i)continue;
        cnt[val[i]]++;
    }
    if (cnt[3] == 0)
    {
        if (cnt[1] + 1 > ds || cnt[2] + 1 > dt)
        {
            puts("No");
            return;
        }
        puts("Yes");
        printf("%d %d\n", s, t);
        int sz = res.size();
        rep(i, 0, sz)
        {
            printf("%d %d\n", res[i].first, res[i].second);
        }
        repp(i, 1, n)
        {
            if (val[i] == 0)continue;
            if (val[i] == 1)
            {
                printf("%d %d\n", toS[i], s);
            }
            else
            {
                printf("%d %d\n", toT[i], t);
            }
        }
    }
    else
    {
        if (cnt[1] + 1 > ds || cnt[2] + 1 > dt || cnt[1] + cnt[2] + cnt[3] + 1 > ds + dt)
        {
            puts("No");
            return;
        }
        puts("Yes");
        rep(i, 0, res.size())
        {
            printf("%d %d\n", res[i].first, res[i].second);
        }
        int fl = 0;
        ds -= (cnt[1] + 1);
        repp(i, 1, n)
        {
            if (val[i] == 0)continue;
            if (val[i] == 1)
            {
                printf("%d %d\n", s, toS[i]);
            }
            else if(val[i]==2)
            {
                printf("%d %d\n", t, toT[i]);
            }
            else if (!fl)
            {
                fl = 1;
                printf("%d %d\n", t, toT[i]);
                printf("%d %d\n", s, toS[i]);
            }
            else
            {
                if (ds)
                {
                    ds--;
                    printf("%d %d\n", s, toS[i]);
                }
                else
                {
                    printf("%d %d\n", t, toT[i]);
                }
            }
        }
    }

}

int main()
{
    solve();
    return 0;
}