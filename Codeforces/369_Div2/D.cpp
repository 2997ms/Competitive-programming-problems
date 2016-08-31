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

const int maxn = 3e5+5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

ll res;
int n, ter, cir, cir_num, all;
int cnt;
int head[maxn], vis[maxn], val[maxn], v[maxn];

void dfs(int x, int d, int c)
{
    c++;
    vis[x] = d;
    if (vis[val[x]] == 0)
    {
        dfs(val[x], d, c);
    }
    else
    {
        if (vis[val[x]] == d)
        {
            cir = 1;
            ter = val[x];
            all = c;
        }
        else
        {
            all = c;
        }
    }
}

void dfs2(int x,int c)
{
    c++;
    v[x] = 1;
    if (v[val[x]] == 0)
    {
        dfs2(val[x], c);
    }
    else
    {
        cir_num = c;
    }
}

void solve()
{
    res = 1;
    sa(n);
    repp(i, 1, n)
    {
        scanf("%d", &val[i]);
    }
    int no = 0;
    int yes = 0;
    repp(i, 1, n)
    {
        if (!vis[i])
        {
            cir = 0;
            all = 0;
            ter = 0;
            cir_num = 0;
            dfs(i, i, 0);
            if (cir)
            {
                dfs2(ter, 0);
                res *= (po(2, cir_num, mod) - 2 + mod) % mod;
                res = (res) % mod;
            }
            if (all - cir_num)
            {
                res *= po(2, all - cir_num, mod);
                res %= mod;
            }
        }
    }
    printf("%lld", res);
}

int main()
{
    solve();
    return 0;
}