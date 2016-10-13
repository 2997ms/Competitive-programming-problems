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
#define LL_INF 0x3fffffffffffffff
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
 
const int maxn = 1e5 + 10;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}
int n;
int val[maxn];
void solve()
{
    sa(n);
    repp(i,1,n)
    {
        sa(val[i]);
    }
    ll res = val[1]-1;
    int maxx=2;
    repp(i,2,n)
    {
        if(val[i]>maxx)
        {
            int k=val[i]/maxx-(val[i]%maxx==0);
            res+=k;
            maxx=max(val[i]%maxx+1,maxx);
        }
        else if(val[i]==maxx)
        {
            maxx++;
        }
    }
    cout<<res<<endl;
}
int main()
{
    solve();
    return 0;
}