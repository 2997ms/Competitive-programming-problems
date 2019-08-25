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
const int maxn = 1e6 + 5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
/*************************************************************************/

ll Test[10] = {2, 3, 5, 7, 11, 13, 17};
bool Query(ll P) {
    if(P == 1) return 0;
    ll t = P - 1, k = 0;
    while(!(t & 1)) k++, t >>= 1;
    for(int i = 0; i < 7; i++) {
        if(P == Test[i]) return 1;
        ll a = po(Test[i], t, P), nxt = a;
        for(ll j = 1; j <= k; j++) {
            nxt = (a * a) % P;
            if(nxt == 1 && a != 1 && a != P - 1) return 0;
            a = nxt;
        }
        if(a != 1) return 0;
    }
    return 1;
}
void solve() {
    ll le, ri;
    slla(le);
    slla(ri);
    ll ans = 0;
    for(ll i = le; i <= ri; i++) {
        if(i==1) continue;
        if(i%2==1) {
            if(!Query(i)) {
                ans++;
            }
        } else {
            if(i%4) {
                continue;
            }
            ll k = i/4;
            if(k==1) continue;
            if(!Query(k)) {
                ans++;
            }
        }
    }
    printf("%lld\n", (ri-le+1)-ans);
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

