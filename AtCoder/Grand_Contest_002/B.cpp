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
 
const int maxn = 2e6 + 10;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
 
int n, m;
int x[maxn], y[maxn];
int num[maxn], vis[maxn];
 
void solve()
{
    sa(n), sa(m);
    repp(i, 1, m)
    {
        sa(x[i]), sa(y[i]);
    }
    repp(i, 1, n)
    {
        num[i] = 1;
    }
    vis[1] = 1;
    repp(i, 1, m)
    {
        int s = x[i];
        int e = y[i];
 
        num[s]--;
        num[e]++;
        if (vis[s])
        {
            vis[e] = 1;
        }
        if (num[s] == 0)
        {
            if (vis[s])
            {
                vis[s] = 0;
            }
        }
    }
    int res = 0;
    repp(i, 1, n)
    {
        if (vis[i])
        {
            res++;
        }
    }
    printf("%d\n", res);
}
 
 
int main()
{
    solve();
    return 0;
}