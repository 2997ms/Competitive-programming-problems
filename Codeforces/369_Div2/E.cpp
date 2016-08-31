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

const int maxn = 2e5 + 5;
const double PI = acos(-1.0);
const ll mod = 1e6 + 3;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}

ll n,k;

void solve()
{
    scanf("%lld%lld",&n,&k);
    if(n<=63 && k>(1LL<<n))
    {
        puts("1 1");
        return;
    }
    
    ll up = 1;
    if(k-1>=mod)
    {
        up=0;
    }
    else
    {
        for(ll x=1;x<=k-1;x++)
        {
            up=up*((po(2,n,mod)-x+mod)%mod)%mod;
        }
    }
    ll down = (k-1)%(mod-1)*(n%(mod-1))%(mod-1);
    down = po(2,down,mod);
    ll com=0;
    ll res = 1;
    while(true)
    {
        res=res*2;
        if(res>k-1)break;
        com+=(k-1)/res;
    }
    com = po(2,com,mod);
    com = po(com,mod-2,mod);
    down = (down*com)%mod;
    up = up*com%mod;
    printf("%lld %lld\n", ((down - up)%mod+mod)%mod,down);
    
}

int main()
{

    solve();
    return 0;
}