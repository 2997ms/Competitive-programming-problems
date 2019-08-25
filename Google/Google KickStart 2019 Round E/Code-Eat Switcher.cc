#include <bits/stdc++.h>
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
 
const int dx44[6] = {0, -1, -1, 1, 1};
const int dy44[6] = {0, -1, 1, -1, 1};
const int dx4[6] = {0, 1, 0,-1};
const int dy4[6] = {-1, 0, 1,0};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int dx82[9] = {0, -1, -1, 1, 1, 2, 2, -2, -2};
const int dy82[9] = {0, 2, -2, 2, -2, 1, -1, 1, -1};
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
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
const int maxn = 1e5 + 5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
/*************************************************************************/

int d,s;
struct no {
    double dc;
    double de;
    double dce;
}node[maxn];

double pre[maxn];
double suf[maxn];

bool cmp(no a, no b) {
    return a.dce > b.dce;
}

char ans[maxn];
void solve() {
    sa(d),sa(s);
    repp(i,1,s) {
        scanf("%lf", &node[i].dc);
        scanf("%lf", &node[i].de);
        if( abs(node[i].de - 0) < eps) {
            node[i].dce = 1e9;
        } else {
            node[i].dce = node[i].dc / node[i].de;
        }
    }
    memset(pre,0,sizeof(pre));
    memset(suf,0,sizeof(suf));
    sort(node+1,node+s+1,cmp);
    repp(i,1,s) {
        pre[i] = pre[i-1] + node[i].dc;
    }
    for(int i=s;i>=1;i--) {
        suf[i] = suf[i+1] + node[i].de;
    }
    repp(i,1,d) {
        double na, nb;
        scanf("%lf", &na);
        scanf("%lf", &nb);
        int le = 1;
        int ri = s;
        int cnt = 0;
        while(le<ri) {
            int mid = (le + ri)/2;
            if(pre[mid] > na) {
                ri = mid;
            } else {
                le = mid+1;
            }
         
        }
        if(pre[le] >= na) {
            double need = na - pre[le-1];
            double percent = need / node[le].dc;
            double have = (1-percent) * node[le].de + suf[le+1];
            if(have >= nb) {
                ans[i] = 'Y';
            } else {
                ans[i] = 'N';
            }
        } else {
            ans[i] = 'N';
        }
    }
    repp(i,1,d) {
        printf("%c", ans[i]);
    }
    printf("\n");
}

int main()
{
    int t;
    sa(t);
    repp(i,1,t) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

