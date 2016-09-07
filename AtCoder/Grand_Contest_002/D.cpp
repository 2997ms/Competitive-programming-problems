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
 
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
 
int n, m, q;
int fa[maxn];
int x[maxn], y[maxn];
 
int cnt;
int sz[maxn];
vector<int>ans[maxn];
 
void init()
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        sz[i] = 1;
    }
}
 
int getfa(int x)
{
    return fa[x] == x ? x : getfa(fa[x]);
}
 
int L[maxn], R[maxn];
int qx[maxn], qy[maxn], qz[maxn];
 
void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d%d", &qx[i], &qy[i], &qz[i]);
        L[i] = 1;
        R[i] = m;
    }
    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= q; j++)
        {
            if (R[j] > L[j])
            {
                int mid = (R[j] + L[j]) / 2;
                ans[mid].push_back(j);
            }
        }
        init();
        for (int j = 1; j <= m; j++)
        {
            int xx = x[j];
            int yy = y[j];
 
            xx = getfa(xx);
            yy = getfa(yy);
 
            if (sz[xx] < sz[yy])
            {
                swap(xx, yy);
            }
            if (xx != yy)
            {
                sz[xx] += sz[yy];
                fa[yy] = xx;
            }
            for (int k = 0; k < ans[j].size(); k++)
            {
                int id = ans[j][k];
                int tx = getfa(qx[id]);
                int ty = getfa(qy[id]);
                int sum = 0;
                if (tx != ty)
                {
                    sum += sz[tx];
                    sum += sz[ty];
                }
                else
                {
                    sum += sz[tx];
                }
                if (sum < qz[id])
                {
                    L[id] = j + 1;
                }
                else
                {
                    R[id] = j;
                }
 
            }
        }
        for (int j = 1; j <= m; j++)
        {
            ans[j].clear();
        }
    }
    for (int i = 1; i <= q; i++)
    {
        printf("%d\n", L[i]);
    }
}
 
int main()
{
    solve();
    return 0;
}