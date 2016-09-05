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
 
const int maxn = 1e5 + 5;
const double PI = acos(-1.0);
const ll mod = 1e6 + 3;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}
 
int n;
int L;
int x[maxn];
int dp[maxn][20];
 
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);
    }
    scanf("%d",&L);
    x[n+1] = 2e9;
    for(int i=1;i<=n;i++)
    {
        dp[i][0] = lower_bound(x+1,x+n+2,x[i]+L+1) - (x+1);
        //cout<<x[i]+L<<" "<<i<<" "<<dp[i][0]<<endl;
    }
    int step = 1;
    for(step =1;(1<<step)<=n;step++)
    {
        for(int k=1;k<=n;k++)
        {
            dp[k][step]=dp[dp[k][step-1]][step-1];
        }
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)
            swap(a,b);
        int ans=0;
        //cout<<"step"<<step<<endl;
 
        for(int i=step-1;i>=0;i--)
        {
            if(dp[a][i] < b)
            {
                ans += (1<<i);
                a = dp[a][i];
            }
            //cout<<ans<<endl;
            //cout<<"a:"<<a<<endl;
            //cout<<"i:"<<i<<endl;
            //cout<<"dp[a][i]:"<<dp[a][i]<<endl;
        }
        while(a<b)
        {
            ans++;
            a=dp[a][0];
        }
        printf("%d\n",ans);
    }
}
 
int main()
{
    solve();
    return 0;
}