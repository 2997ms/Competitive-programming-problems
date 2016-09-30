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

const int maxn = 4e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

struct Matrix
{
    int a[2][2];
    Matrix()
    {
        memset(a, 0, sizeof(a));
    }
    void init()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                a[i][j] = (i == j);
            }
        }
    }
    Matrix operator +(const Matrix &b)const
    {
        Matrix res;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                res.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
            }
        }
        return res;
    }
    Matrix operator *(const Matrix &b)const
    {
        Matrix res;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    res.a[i][j] = res.a[i][j] + (1LL*a[i][k] * b.a[k][j]) % mod;
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    }
    Matrix operator^(const int &t)const
    {
        Matrix A = (*this), res;
        res.init();
        int p = t;
        while (p)
        {
            if (p & 1)
            {
                res = res*A;
            }
            A = A*A;
            p >>= 1;
        }
        return res;
    }
};
Matrix s[maxn], lz[maxn], f;
int n, m;
int val[maxn];

void pushup(int root)
{
    s[root] = s[root << 1] + s[root << 1 | 1];
}

void pushdown(int root)
{
    s[root << 1] = lz[root] * s[root << 1];
    s[root << 1 | 1] = lz[root] * s[root << 1 | 1];

    lz[root << 1] = lz[root] * lz[root << 1];
    lz[root << 1 | 1] = lz[root] * lz[root << 1 | 1];
    lz[root].init();
}

void build(int root, int le, int ri)
{
    lz[root].init();
    if (le == ri)
    {
        s[root] = f ^ (val[le] - 1);
        return;
    }
    int mid = (le + ri) >> 1;
    build(root << 1, le, mid);
    build(root << 1 | 1, mid + 1, ri);
    pushup(root);
}

void update(int root, int ql, int qr, int le, int ri, Matrix val)
{
    if (ql == le&&qr == ri)
    {
        s[root] = val*s[root];
        lz[root] = val*lz[root];
        return;
    }
    pushdown(root);
    int mid = (le + ri) >> 1;
    if (mid >= qr)
    {
        update(root << 1, ql, qr, le, mid, val);
    }
    else if (mid < ql)
    {
        update(root << 1 | 1, ql, qr, mid + 1, ri, val);
    }
    else
    {
        update(root << 1, ql, mid, le, mid, val);
        update(root << 1 | 1, mid + 1, qr, mid + 1, ri, val);
    }
    pushup(root);
}

int query(int root, int ql, int qr, int le, int ri)
{
    if (ql == le&&qr == ri)
    {
        return s[root].a[0][0];
    }
    pushdown(root);
    int mid = (le + ri) >> 1;
    if (mid >= qr)
    {
        return query(root << 1, ql, qr, le, mid);
    }
    else if (mid + 1 <= ql)
    {
        return query(root << 1 | 1, ql, qr, mid + 1, ri);
    }
    else
    {
        return (query(root << 1, ql, mid, le, mid) + query(root << 1 | 1, mid + 1, qr, mid + 1, ri)) % mod;
    }
}

void solve()
{
    f.a[0][0] = 1, f.a[0][1] = 1;
    f.a[1][0] = 1, f.a[1][1] = 0;

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &val[i]);
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int oper;
        scanf("%d", &oper);
        if (oper == 1)
        {
            int le, ri, v;
            scanf("%d%d%d", &le, &ri, &v);
            update(1, le, ri, 1, n, f ^ v);
        }
        else
        {
            int le, ri;
            scanf("%d%d", &le, &ri);
            int r = query(1, le, ri, 1, n);
            printf("%d\n", r);
        }
    }
}

int main()
{
    solve();
    return 0;
}