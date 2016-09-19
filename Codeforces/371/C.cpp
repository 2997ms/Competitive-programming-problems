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

const int maxn = 5005;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

int n;
ll val[maxn], siz[maxn], le[maxn], ri[maxn], root[maxn], num[maxn];

struct no
{
    ll v;
    int dis, le, ri;
    no() :v(0), dis(0), le(0), ri(0) {};
    no(ll val) :v(val), dis(0), le(0), ri(0) {};
}node[maxn];

int merge(int x, int y)
{
    if (x == 0 || y == 0)return x + y;
    if (node[x].v < node[y].v)
    {
        swap(x, y);
    }
    node[x].ri = merge(node[x].ri, y);
    if (node[node[x].le].dis < node[node[x].ri].dis)
    {
        swap(node[x].le, node[x].ri);
    }
    node[x].dis = node[node[x].ri].dis + 1;
    return x;
}

ll top(int x)
{
    return node[x].v;
}

ll pop(int x)
{
    return merge(node[x].le, node[x].ri);
}

void solve()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%I64d", &val[i]);
        val[i] -= i;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        ++cnt;
        siz[cnt] = 1, root[cnt] = i;
        num[cnt] = 1;
        le[cnt] = i, ri[cnt] = i;
        node[i].v = val[i];

        while (cnt > 1 && node[root[cnt]].v <= node[root[cnt - 1]].v)
        {
            --cnt;
            root[cnt] = merge(root[cnt], root[cnt + 1]);
            siz[cnt] += siz[cnt + 1];
            ri[cnt] = ri[cnt + 1];
            num[cnt] += num[cnt + 1];
            for (; siz[cnt] * 2 > num[cnt] + 1; --siz[cnt])
            {
                root[cnt] = pop(root[cnt]);
            }
        }
    }
    ll ans = 0;

    for (int i = 1; i <= cnt; i++)
    {
        for (int j = le[i]; j <= ri[i]; j++)
        {
            ans += abs(node[root[i]].v - val[j]);
        }
    }
    printf("%lld\n", ans);
}

int main()
{   
    solve();
    return 0;
}
