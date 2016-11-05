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
 
const int maxn = 2e6 + 5;
const double PI = acos(-1.0);
const ll mod = 1e6 + 3;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}
 
ll n;
ll res[maxn],pos[21];
vector<int>val[21];
 
void solve()
{
    scanf("%lld",&n);
    ll sum=0;
    memset(res,0,sizeof(res));
 
    for(int i=0;i<20;i++)
    {
        val[i].clear();
    }
    for(int i=0;i<n;i++)
    {
        ll len;
        scanf("%lld",&len);
        sum+=len;
        val[i].clear();
        for(int j=0;j<len;j++)
        {
            ll x;
            scanf("%lld",&x);
            val[i].push_back(x);
        }
        pos[i]=len-1;
    }
    if(sum>2e6)while(1);
    for(int i=1;i<=sum;i++)
    {
        scanf("%lld",&res[i]);
    }
    reverse(res+1,res+sum+1);
    for(int i=0;i<n;i++)
    {
        int c=0;
        for(int j=1;j<=sum&&c<val[i].size();j++)
        {
            if(res[j]==val[i][c])
            {
                c++;
            }
        }
        if(c==val[i].size())
        {
            continue;
        }
        else
        {
            //cout<<c<<" "<<i<<endl;
            puts("No");
            return;
        }
    }
    puts("Yes");
}
 
int main()
{
 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
    return 0;
} 