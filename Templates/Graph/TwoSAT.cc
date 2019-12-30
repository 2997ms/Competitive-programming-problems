//CF 228E
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
#include <iomanip>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define EPS 1e-8
#define LL_INF 0x3fffffffffffffff
#define INF 0x3f3f3f3f3f3f3f3f
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
 
const int dx44[6] = {0, -1, -1, 1, 1};
const int dy44[6] = {0, -1, 1, -1, 1};
const int dx4[6] = {0, 1, 0,-1};
const int dy4[6] = {1, 0, -1,0};
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
const int maxn = 2e5 + 15;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
/*************************************************************************/

const int MAXN = 110;
const int MAXV = 210;
const int MAXE = MAXV * MAXV;
struct TopoLogic {
    // from index 1 as the start
    int stk[MAXV], top;
    int n, ecnt, cnt;
    int head[MAXV], order[MAXV], indeg[MAXV];
    int to[MAXE], nxt[MAXE];

    void init(int n) {
        this->n = n;
        this->ecnt = 0;
        memset(head, -1, sizeof(head));
        memset(indeg, 0, sizeof(indeg));
    }

    void add_edge(int u, int v) {
        to[ecnt] = v;
        nxt[ecnt] = head[u];
        head[u] = ecnt++;
        ++indeg[v];
    }

    void build() {
        top = cnt = 0;
        REPP(i,1,n) {
            if(indeg[i] == 0) {
                stk[++top] = i;
            }
        }
        while(top) {
            int u = stk[top--];
            order[cnt++] = u;
            for(int p = head[u]; p != -1; p = nxt[p]) {
                int t = to[p];
                if(--indeg[t] == 0) {
                    stk[++top] = t;
                }
            }
        }
    }
}tp;

struct twoSAT {
    int stk[MAXV], top;
    int n, ecnt, dfs_clock, scc_cnt;
    int head[MAXV], sccno[MAXV], pre[MAXV], lowlink[MAXV];
    int to[MAXE], next[MAXE];
    int select[MAXV], sccnox[MAXV];

    void init(int n) {
        this->n = n;
        ecnt = dfs_clock = scc_cnt = 0;
        memset(head, -1, sizeof(head));
        memset(pre, 0 , sizeof(pre));
        memset(sccno, 0 , sizeof(sccno));
    }

    void add_edge(int x, int y) {//x, y clash
        to[ecnt] = y ^ 1; next[ecnt] = head[x]; head[x] = ecnt++;
        to[ecnt] = x ^ 1; next[ecnt] = head[y]; head[y] = ecnt++;
    }

    void dfs(int u) {
        lowlink[u] = pre[u] = ++dfs_clock;
        stk[++top] = u;
        for(int p = head[u]; p!=-1; p = next[p]) {
            int v = to[p];
            if(!pre[v]) {
                dfs(v);
                if(lowlink[v] < lowlink[u]) lowlink[u] = lowlink[v];
            } else if(!sccno[v]) {
                if(pre[v] < lowlink[u]) lowlink[u] = pre[v];
            }
        }
        if(lowlink[u] == pre[u]) {
            sccnox[++scc_cnt] = u;
            while(true) {
                int x = stk[top--];
                sccno[x] = scc_cnt;
                if(x == u) break;
            }
        }
    }

    bool solve() {
        for(int i = 0; i < n; ++i) if(!pre[i]) dfs(i);
        for(int i = 0; i < n; i += 2)
            if(sccno[i] == sccno[i ^ 1]) return false;
        return true;
    }

    void build_select() {
        tp.init(scc_cnt);
        for(int u = 0; u < n; ++u) {
            for(int p = head[u]; p != -1; p = next[p]) {
                int v = to[p];
                if(sccno[u] == sccno[v]) continue;
                tp.add_edge(sccno[u], sccno[v]);
            }
        }
        tp.build();
        memset(select, -1, sizeof(select));
        for(int i = tp.n - 1; i >= 0; --i) {
            int x = tp.order[i];
            if(select[x] == -1) {
                select[x] = 1;
                select[sccno[sccnox[x] ^ 1]] = 0;
            }
        }
    }
}G;


int n,m;
void solve() {
    SA(n);
    SA(m);
    G.init(n*2);
    REPP(i,1,m) {
        int x,y,z;
        SA(x);
        SA(y);
        SA(z);
        --x;
        --y;
        if(z == 1) {
            G.add_edge(2*x, 2*y + 1);
            G.add_edge(2*x+1, 2*y);
        } else {
            G.add_edge(2*x, 2*y);
            G.add_edge(2*x+1, 2*y+1);
        }
    }
    if(!G.solve()) {
        puts("Impossible");
    } else {
        G.build_select();
        int cnt = 0;
        REP(i,0,n) {
            // DE(G.sccno[2*i])
            if(G.select[G.sccno[2*i]]) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
        REP(i,0,n) {
            if(G.select[G.sccno[2*i]]) {
                printf("%d ", i+1);
            }
        }
    }
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
#endif
    solve();
    return 0;
 
}
 