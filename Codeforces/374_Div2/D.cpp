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

const int maxn = 800005;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

ll n, k, x;
ll num[maxn], p[maxn], val[maxn], v[maxn],sig[maxn];

void build(int root, int le, int ri)
{
    if (le == ri)
    {
        num[root] = val[le];
        p[root] = le;
        return;
    }
    int mid = (le + ri) >> 1;
    build(root << 1, le, mid);
    build(root << 1 | 1, mid + 1, ri);

    if (num[root << 1] < num[root <<1 | 1])
    {
        num[root] = num[root << 1];
        p[root] = p[root << 1];
    }
    else
    {
        num[root] = num[root << 1|1];
        p[root] = p[root << 1 | 1];
    }
}

void update(int root, int ql, int qr, int le, int ri,ll v)
{
    if (ql == le&&qr == ri)
    {
        num[root] += v;
        return;
    }
    int mid = (le +ri) >> 1;
    if (ql <= mid)
    {
        update(root << 1, ql, qr, le, mid, v);
    }
    else
    {
        update(root << 1 | 1, ql, qr, mid + 1, ri, v);
    }
    if (num[root << 1] < num[root << 1 | 1])
    {
        num[root] = num[root << 1];
        p[root] = p[root << 1];
    }
    else
    {
        num[root] = num[root << 1 | 1];
        p[root] = p[root << 1 | 1];
    }
}

int query(int root, int ql, int qr, int le, int ri)
{
    if (ql == le&&qr == ri)
    {
        return p[root];
    }
    int mid = (le + ri) >> 1;
    if (ql <= mid)
    {
        return query(root << 1, ql, qr, le, mid);
    }
    else
    {
        return query(root << 1 | 1, ql, qr, mid + 1, ri);
    }
}

ll query_v(int root, int ql, int qr, int le, int ri)
{
    if (ql == le&&qr == ri)
    {
        return num[root];
    }
    int mid = (le + ri) >> 1;
    if (ql <= mid)
    {
        return query_v(root << 1, ql, qr, le, mid);
    }
    else
    {
        return query_v(root << 1 | 1, ql, qr, mid + 1, ri);
    }
}

void solve()
{
    scanf("%lld%lld%lld", &n, &k, &x);
    ll minn = 1e9 + 7;
    int po = 1;
    int zeros = 0;
    int min0 = 0;
    repp(i, 1, n)
    {
        scanf("%lld", &v[i]);
        if (v[i] == 0)
        {
            zeros++;
        }
        else if (v[i] < 0)
        {
            min0++;
        }
    }
    if (zeros > k)
    {
        repp(i, 1, n)
        {
            printf("%lld ", v[i]);
        }
    }
    else
    {
        if (min0 & 1)
        {
            repp(i, 1, n)
            {
                val[i] = abs(v[i]);
                sig[i] = v[i] >= 0;
            }
            build(1, 1, n);
            for (int i = k; i > 0; i--)
            {
                int p = query(1, 1, n, 1, n);
                update(1, p, p, 1, n, x);
            }
            repp(i, 1, n)
            {
                val[i] = query_v(1, i, i, 1, n);
                if (!sig[i])
                {
                    printf("%lld ", -val[i]);               
                }
                else
                {
                    printf("%lld ", val[i]);
                }
            }
        }
        else
        {
            ll minn = 1e9 + 7;
            int po = 1;
            repp(i, 1, n)
            {
                val[i] = abs(v[i]);
                sig[i] = v[i] >= 0;
                if (v[i] >= 0 && v[i] < minn)
                {
                    minn = v[i];
                    po = i;
                }
            }

            ll minn2 = 1e9 + 7;
            int po2 = 1;
            repp(i, 1, n)
            {
                if (v[i] < 0 && abs(v[i]) < minn2)
                {
                    minn2 = abs(v[i]);
                    po2 = i;
                }
            }
            if (minn > minn2)
            {
                ll t = minn2 - k*x;
                if (t >= 0)
                {
                    v[po2] = -t;
                    repp(i, 1, n)
                    {
                        printf("%lld ", v[i]);
                    }
                    return;
                }

                ll mix = (minn2 + x - 1) / x;
                k -= mix;
                t = minn2 - mix*x;
                val[po2] = abs(t);
                sig[po2] = 1;

                build(1, 1, n);
                for (int i = k; i > 0; i--)
                {
                    int p = query(1, 1, n, 1, n);
                    update(1, p, p, 1, n, x);
                }
                repp(i, 1, n)
                {
                    val[i] = query_v(1, i, i, 1, n);
                    if (!sig[i])
                    {
                        printf("%lld ", -val[i]);
                    }
                    else
                    {
                        printf("%lld ", val[i]);
                    }
                }

            }
            else
            {
                ll t = minn - k*x;
                if (t >= 0)
                {
                    v[po] = t;
                    repp(i, 1, n)
                    {
                        printf("%lld ", v[i]);
                    }
                    return;
                }
                ll mix = (minn + x - 1) / x;
                k -= mix;
                t = minn - mix*x;
                val[po] = abs(t);
                sig[po] = 0;

                build(1, 1, n);
                for (int i = k; i > 0; i--)
                {
                    int p = query(1, 1, n, 1, n);
                    update(1, p, p, 1, n, x);
                }
                repp(i, 1, n)
                {
                    val[i] = query_v(1, i, i, 1, n);
                    if (!sig[i])
                    {
                        printf("%lld ", -val[i]);
                    }
                    else
                    {
                        printf("%lld ", val[i]);
                    }
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