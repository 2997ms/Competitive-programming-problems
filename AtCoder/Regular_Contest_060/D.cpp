//#pragma comment(linker, "/STACK:102400000,102400000")
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

const int maxn = 505;
const double PI = acos(-1.0);
const ll mod = 1e6 + 3;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}

ll n,s;
ll f(ll b,ll n)
{
    if(n<b)
    {
        return n;
    }
    else
    {
        return f(b,n/b) + n%b;
    }
}

void solve()
{
    scanf("%lld%lld",&n,&s);
    ll up = sqrt(1.0*n)+1;
    for(int i=2;i<=up;i++)
    {
        if(f(i,n)==s)
        {
            printf("%d",i);
            return;
        }
    }
    ll t = n-s;
    if(t < 0)
    {
        puts("-1");
        return;
    }
    if(t==0)
    {
        printf("%lld",n+1);
        return;
    }
    ll b = -1;
    for(int i=1;i<=up;i++)
    {
        if(t%i==0)
        {
            ll x = t/i+1;
            ll p = i;
            ll q = s-p;
            if(q >= x)continue;
            if(p >= x)continue;
            if(q < 0)continue;
            if(p*x+q == n)
            {
                b = x;
            }
        }
    }
    printf("%lld",b);
}

int main()
{
    solve();
    return 0;
}