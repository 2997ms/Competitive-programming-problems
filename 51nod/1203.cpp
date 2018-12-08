/*质数<230的可以用RMQ，发现就只有50个。
质数>230的发现只有可能0或者1，莫队。
*/
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
const int maxn = 1e5 + 5;
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
int num[maxn];
struct RMQ {
    int f_min[maxn][20],f_max[maxn][20];
     
    void init(int n)
    {
        for(int i = 1; i <= n; i++)
        {
            f_min[i][0] = f_max[i][0] = num[i];
        }

    
        for(int i = 1; (1<<i) <= n; i++)  //按区间长度递增顺序递推
        {
            for(int j = 1; j+(1<<i)-1 <= n; j++)  //区间起点
            {
                f_max[j][i] = max(f_max[j][i-1],f_max[j+(1<<(i-1))][i-1]);
                f_min[j][i] = min(f_min[j][i-1],f_min[j+(1<<(i-1))][i-1]);
            }
        }
    
    }
     
    int query_max(int l,int r)
    {
        int k = (int)(log(double(r-l+1))/log((double)2));
        return max(f_max[l][k], f_max[r-(1<<k)+1][k]);
    }
     
    int query_min(int l,int r)
    {
        int k = (int)(log(double(r-l+1))/log((double)2));
        return min(f_min[l][k], f_min[r-(1<<k)+1][k]);
    }
}rmq;

ll vis[maxn];
vector<int>v;
map<int,int>ind;
map<int,int>an_ind;
ll val[maxn],ni[maxn];

struct Q{
    int le;
    int ri;
    int id;
}q[maxn];

ll ans[maxn];
int pos[maxn];
bool cmp(Q & a, Q & b) {
    return pos[a.le]<pos[b.le] || (pos[a.le]==pos[b.le] && a.ri<b.ri); 
}
int last[maxn];
int v_le[maxn],v_ri[maxn];
vector<int>pri;
void solve() {
    int up = 230;
    int cnt = 0;
    repp(i,2,up) {
        if(vis[i])continue;
        pri.push_back(i);
        for(int j=i;j<=up;j+=i) {
            vis[j]=1;
        }
    }

    int n;
    int h;
    sa(n);    
    sa(h);
    repp(i,1,n){
        int x;
        sa(x);
        vis[i]=x;
    }
    repp(i,1,h) {
        sa(q[i].le);
        sa(q[i].ri);
        q[i].id=i;
        ans[i]=1;
    }
    rep(i,0,pri.size()) {
        memset(num,0,sizeof(num));
        repp(k,1,n) {
            int g = vis[k];
            while(g%pri[i]==0) {
                num[k]++;
                g/=pri[i];
            }
            vis[k]=g;
        }

        rmq.init(n);
        
        repp(j,1,h) {
            int le = q[j].le;
            int ri = q[j].ri;
            int id = q[j].id;
            ll d = rmq.query_max(le,ri);
            ans[id] = ans[id]*po(pri[i],d,mod)%mod;
        } 
    }
    repp(i,1,n) {
        val[i]=vis[i];
    }
    int bk = ceil(sqrt(1.0*n));
    for (int i = 1; i <= n; i++)
    {
        pos[i] = (i - 1) / bk + 1;
    }
    memset(last,0,sizeof(last));
    repp(i,1,n) {
        v_le[i]=last[val[i]];
        last[val[i]]=i;
    }
    memset(last,0,sizeof(last));
    for(int i=n;i>=1;i--) {
        if(last[val[i]]==0) {
            last[val[i]]=n+1;
        }
        v_ri[i]=last[val[i]];
        last[val[i]]=i;
    }
    int pl = 1; 
    int pr = 0;
    int j;
    val[0]=val[n+1]=0;
    sort(q+1,q+h+1,cmp);
    repp(i,1,n) {
        ni[i] = po(val[i],mod-2,mod);
    }
    ll cur = 1;
    for (int i = 1; i <= h; i++)
    {
        while(pl<q[i].le) {
            if(v_ri[pl]>pr) {
                cur = cur%mod*ni[pl]%mod;
            }
            pl++;
        }
        while(pl>q[i].le) {
            pl--;
            if(v_ri[pl]>pr) {
                cur = cur%mod*val[pl]%mod;
            }
        }
        while(pr>q[i].ri) {
            if(v_le[pr]<pl) {
                cur = cur%mod*ni[pr]%mod;
            }
            pr--;
        }
        while(pr<q[i].ri) {
            pr++;
            if(v_le[pr]<pl) {
                cur = cur%mod*val[pr]%mod;
            }
        }
        ans[q[i].id]=ans[q[i].id]*cur%mod;
    }

    repp(i,1,h){
        printf("%lld\n",ans[i]);
    }

}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif
    solve();
    return 0;
}
