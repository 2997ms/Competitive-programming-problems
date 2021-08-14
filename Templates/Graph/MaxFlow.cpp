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
const int maxn = 180;
const double PI = acos(-1.0);
#define mst(x, a) memset(x, a, sizeof(x))
const double eps = 1e-10;
/*************************************************************************/

const int MAX_N = 40005;
const int INF = (1 << 30);
struct Edge{ int from, to, cap, flow; };
vector<Edge> edges;
int cur[MAX_N],d[MAX_N];
vector<int> G[MAX_N];
bool vis[MAX_N];

void add_edge(int from, int to, int cap) {
        edges.push_back(Edge {from, to, cap, 0});
        edges.push_back(Edge {to, from, 0, 0});
        int m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
}

bool bfs(int s,int t) {
        memset(vis,0,sizeof(vis));
        queue<int> q;
        q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!q.empty()) {
                int x = q.front(); q.pop();
                for (int i = 0; i < G[x].size(); ++i) {
                       Edge& e = edges[ G[x][i] ];
                       if (!vis[e.to] && e.cap > e.flow) {
                                d[e.to] = d[x] + 1;
                                vis[e.to] = 1;
                                q.push(e.to);
                       }
                }
        }

        return vis[t];
}

int dfs(int x, int a, int t) {
        if(x == t || a == 0) return a;
        int flow = 0,f;
        for(int& i = cur[x]; i < G[x].size(); ++i) {
                Edge& e = edges[ G[x][i] ];
                if(d[x] + 1 == d[e.to] && (f = dfs(e.to,min(a,e.cap - e.flow),t)) > 0) {
                        e.flow += f;
                        edges[ G[x][i] ^ 1].flow -= f;
                        a -= f;
                        flow += f;
                        if(a == 0) break;
                }
        }
        return flow;
}

int Maxflow(int s, int t) {

        int flow = 0;
        while (bfs(s,t)) {
                memset(cur,0,sizeof(cur));
                flow += dfs(s, INF, t);
        }
        return flow;
}

int n;
double di;
double xx[maxn], yy[maxn];
int cnt[maxn], maxx[maxn];
void solve() {
    SA(n);
    scanf("%lf", &di);
    int sum = 0;
    REPP(i,1,n) {
        // SA(xx[i]);
        // SA(yy[i]);
        scanf("%lf", &xx[i]);
        scanf("%lf", &yy[i]);
        SA(cnt[i]);
        SA(maxx[i]);
        sum += cnt[i];
    }
    int f = 0;
    REPP(i,1,n) {
        edges.clear();
        REPP(k,0,40000) {
            G[k].clear();
            cur[k] = 0;
            vis[k] = false;
            d[k] = 0;
        }
        add_edge(i, 2*n+1, INF);
        REPP(k,1,n) {
            add_edge(k, k+n, maxx[k]);
            add_edge(0,k,cnt[k]);
            REPP(j,k+1,n) {
                double dis = (xx[k] - xx[j])*(xx[k] - xx[j]) + (yy[k] - yy[j])*(yy[k] - yy[j]);
                if(dis <= di*di) {
                    add_edge(k+n, j, INF);
                    add_edge(j+n, k, INF);
                }
            }
        }
        int val = Maxflow(0, n*2+1);
        // DE(val)
        if(val == sum) {
            if(f) {
                printf(" ");
            }
            printf("%d", i-1);
            f = 1;
        }
    }
    if(!f)
        printf("-1\n");
    else
        printf("\n");
}

int main() {   
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
#endif
     // ios::sync_with_stdio(false);
     // cin.tie();
    int t = 1;
    SA(t);
    REPP(i,1,t) {
            solve();
    }

    // std::vector<std::vector<int> > v = {{0,5},{1,2},{0,2},{0,5},{1,3}};
    // std::vector<int> q = {2,3};
    return 0;
}
