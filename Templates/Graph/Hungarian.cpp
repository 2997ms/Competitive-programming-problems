// POJ 1422
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
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
// #include <unordered_map>
// #include <bitset>
// #include <iomanip>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define EPS 1e-9
#define LL_INF 0x3fffffffffffffff
#define MEM(a, b) memset(a, b, sizeof(a))
#define PPER(i, n, m) for (int i = n; i >= m; i--)
#define REPP(i, n, m) for (int i = n; i <= m; i++)
#define REP(i, n, m) for (int i = n; i < m; i++)
#define PER(i, n, m) for (int i = n; i > m; i--)
#define SA(n) scanf("%d", &(n))
#define SLLA(n) scanf("%lld", &(n))
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define DE(val) cout << #val << ": " << val << endl;
// #define DBG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
// #else
// #define DBG(...) 42
// #endif
const int dx44[6] = {0, -1, -1, 1, 1};
const int dy44[6] = {0, -1, 1, -1, 1};
const int dx4[8] = {0, 0, 1,-1,1,-1,0};
const int dy4[8] = {1, -1, 0,0,1,-1,0};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int dx82[9] = {0, -1, -1, 1, 1, 2, 2, -2, -2};
const int dy82[9] = {0, 2, -2, 2, -2, 1, -1, 1, -1};

void update(ll& x,ll v){
    if(x==-1)x=v;
    else if(x>v)x=v;
}
 
ll po(ll a, ll b, ll mod)
{
    ll res = 1;
    a %= mod;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll gcd(ll a, ll b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        return gcd(b % a, a);
    }
}
void extgcd(ll a, ll b, ll &d, ll &x, ll &y)
{
    if (!b)
    {
        d = a;
        x = 1;
    }
    else
    {
        extgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}
ll inverse(ll a, ll n)
{
    ll d, x, y;
    extgcd(a, n, d, x, y);
    return d == 1 ? (x + n) % n : -1;
}
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
const int maxn = 3e3 + 15;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
#define mst(x, a) memset(x, a, sizeof(x))
const double eps = 1e-10;
/*************************************************************************/

vector<int>edge[maxn];
int match[maxn];
int vis[maxn];
int Hungarian(int x)
{
    for(int i=0;i<edge[x].size( );i++)
    {
        int v=edge[x][i];
        if(!vis[v])
        {
            vis[v]=1;
            if(match[v]==-1||Hungarian(match[v]))
            {
                match[v]=x;
                return 1;
            }
        }
    }
    return 0;
}

int n,m;
void solve() {
    SA(n);
    SA(m);
    REPP(i,0,n) {
        edge[i].clear();
    }
    REP(i,0,m) {
        int xx, yy;
        SA(xx);
        SA(yy);
        edge[xx].push_back(yy);
    }
    memset(match,-1,sizeof(match));

    int ans = 0;
    REPP(i,1,n) {
        memset(vis,0,sizeof(vis));
        if(Hungarian(i)) {
            ans++;
        }
    }
    printf("%d\n", n-ans);
}

int main() {   
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
#endif
     // ios::sync_with_stdio(false);
     // cin.tie();
    // init();
    int t = 1;
    int cnt = 0;
    SA(t);
    REPP(i,1,t) {
       
        solve();
    }

    // std::vector<std::vector<int> > v = {{0,5},{1,2},{0,2},{0,5},{1,3}};
    // std::vector<int> q = {2,3};
    return 0;
}
