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
 
int n, k, res;
int val[maxn];
vector<int>edge[maxn];
 
int dfs(int x)
{
    int ans = 0;
    int sz = edge[x].size();
    for (int i = 0; i<sz; i++)
    {
        int y = edge[x][i];
        ans = max(ans, dfs(y));
    }
    ans++;
    if (ans >= k&&val[x] != 1)
    {
        ans = 0;
        res++;
    }
    return ans;
}
 
void solve()
{
    scanf("%d%d", &n, &k);
    scanf("%d", &val[1]);
    res = 0;
    if (val[1] != 1)
    {
        res++;
        val[1] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &val[i]);
        edge[val[i]].push_back(i);
    }
    dfs(1);
    printf("%d", res);
}
 
 
int main()
{
    solve();
    return 0;
}