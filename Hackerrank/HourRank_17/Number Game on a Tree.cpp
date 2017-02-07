//#pragma comment(linker, "/STACK:102400000,102400000")
#include <fstream>
#include <iostream>
#include <functional>
#include <algorithm>
#include <sstream>
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
#include <bitset>
#include <cassert>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;

typedef long long ll;
#define eps 1e-8
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

const int dx4[5] = { 0,-1,0,1,0 };
const int dy4[5] = { 0,0,1,0,-1 };
const int dx8[9] = { 0,-1,0,1,0,1,1,-1,-1 };
const int dy8[9] = { 0,0,1,0,-1,1,-1,1,-1 };
const int maxn = 5e5 + 50;
const double PI = acos(-1.0);
const ll mod = (ll)1e18 + 7;
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

ll mul(ll a, ll b, ll mod)
{
    ll q = a*b;
    q = (q%mod + mod) % mod;
    return q;
}

ll mulpow(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a, mod);
        b >>= 1;
        a = mul(a, a, mod);
    }
    return res;
}

const int base = 233;
int n;
ll ch = 0;
set<int>num;
map<ll, int>hax;
vector<pair<int,int>>edge[maxn];

void add_delete(int w)
{
    if (num.count(w))
    {
        num.erase(w);
        ch -= mulpow(base, w, mod);
    }
    else
    {
        num.insert(w);
        ch += mulpow(base, w, mod);
    }
    if (ch < 0)ch += mod;
    if (ch >= mod)ch -= mod;
}

void dfs(int x, int fa)
{
    hax[ch]++;
    for (int i = 0; i < edge[x].size(); i++)
    {
        int k = edge[x][i].first;
        int w = edge[x][i].second;
        if (k == fa)continue;
        add_delete(w);
        dfs(k, x);
        add_delete(w);
    }
}

void solve()
{
    sa(n);
    ch = 0;
    num.clear();
    hax.clear();
    repp(i, 1, n)
    {
        edge[i].clear();
    }
    repp(i, 1, n-1)
    {
        int x, y, z;
        sa(x), sa(y), sa(z);
        edge[x].push_back(mp(y, z));
        edge[y].push_back(mp(x, z));
    }
    dfs(1, -1);
    ll res = 0;
    for (auto it : hax)
    {
        res += 1LL * it.second*(it.second - 1) / 2;
    }
    ll ans = 1LL * n*(n - 1) / 2 - res;
    printf("%lld\n", ans);
}

int main()
{

    int t;
    sa(t);
    while(t--)
        solve();
    //system("pause");
    return 0;
}