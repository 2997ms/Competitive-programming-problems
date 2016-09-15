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
 
const int maxn = 1e6 + 5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}
 
ll n,m,k;
ll fac[maxn],inv[maxn];
 
void init()
{
    fac[0] = 1;
    inv[0] = 1;
    int up = 1e6;
    for(int i=1;i<=up;i++)
    {
        fac[i] = fac[i-1]*i%mod;
        inv[i] = po(fac[i],mod-2,mod);
    }
}
 
ll C(ll n,ll m)
{
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
 
void solve()
{
    scanf("%lld%lld%lld",&n,&m,&k);
 
    ll res = 0;
    ll fs = 1;
    for(ll i=0;i<=m+k;i++)
    {
        res = res+(C(i+n-1,n-1)*fs%mod*po(3,m+k-i,mod)%mod);
        res %= mod;
        //cout<<res<<" "<<(C(i+n-1,n-1)*fs%mod*po(3,m+k-i,mod)%mod)<<endl;
        //cout<<C(i+n-1,n-1)<<" "<<fs<<" "<<po(3,m+k-i,mod)%mod<<endl<<endl;
        fs = fs*2%mod;
 
        if(i>=m)
        {
            fs = (fs + mod - C(i,m))%mod;
        }
        if(i>=k)
        {
            fs = (fs + mod - C(i,k))%mod;
        }
    }
    printf("%lld\n",res);
}
 
int main()
{
    init();
    solve();
    return 0;
}