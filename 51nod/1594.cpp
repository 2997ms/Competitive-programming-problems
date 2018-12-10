//#pragma comment(linker,"/STACK:102400000,102400000")
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
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define eps 1e-8
#define LL_INF 0x3fffffffffffffff
#define INF 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define pper(i, n, m) for (int i = n; i >= m; i--)
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))
#define slla(n) scanf("%lld", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define DE(val) cout << #val << ": " << val << endl;
#define CASET             \
    int ___T, case_n = 1; \
    scanf("%d ", &___T);  \
    repp(i, 1, ___T)

const int dx44[5] = {0, -1, -1, 1, 1};
const int dy44[5] = {0, -1, 1, -1, 1};

const int dx4[5] = {0, 1, 0, -1};
const int dy4[5] = {1, 0, -1, 0};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int dx82[9] = {0, -1, -1, 1, 1, 2, 2, -2, -2};
const int dy82[9] = {0, 2, -2, 2, -2, 1, -1, 1, -1};
const int maxn = 2e6 + 100;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const ll mod1 = 1e8 + 7;
const ll mod2 = 1e9 + 7;
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
        y = 0;
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

void YES()
{
    puts("YES");
    exit(0);
}
void Yes() { puts("Yes"); } // exit(0); }
void NO()
{
    puts("NO");
    exit(0);
}
void No() { puts("No"); } // exit(0); }
void one()
{
    puts("-1");
    exit(0);
}

/*************************************************************************/

ll phi[maxn],mu[maxn],pri[maxn],vis[maxn];
void get_phi() {
    phi[1]=mu[1]=1;
    int tot=0;
    for(int i=2;i<=maxn-5;i++)
    {
        if(!vis[i]) pri[++tot]=i,mu[i]=-1,phi[i]=i-1;
        for(int j=1;j<=tot&&pri[j]*i<=maxn-5;j++)
        {
            vis[pri[j]*i]=1;
            if(i%pri[j]==0) {mu[i*pri[j]]=0;phi[i*pri[j]]=phi[i]*pri[j];break;}
            else mu[i*pri[j]]=-mu[i],phi[i*pri[j]]=phi[i]*(pri[j]-1);
        }
    }
}
ll c[maxn],g[maxn],f[maxn];

void solve() {
    int t;
    sa(t);
    get_phi();
    while(t--) {
        memset(c,0,sizeof(c));
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        int n;
        sa(n);
        repp(i,1,n){
            c[phi[i]]++;
        }
        repp(x,1,n) {
            for(int i=1;i<=n/x;i++) {
                g[x]+=c[i*x];
            }
        }
        repp(x,1,n) {
            g[x]=g[x]*g[x];
        }
        ll ans = 0;
        repp(d,1,n) {
            ll tmp = 0;
            repp(d2,1,n/d) {
                tmp+=mu[d2]*g[d2*d];
            }
            ans+=phi[d]*tmp;
        }
        printf("%lld\n",ans);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
#endif
    solve();
    return 0;
}
