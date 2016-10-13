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
 
const int maxn = 4e4 + 10;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}
 
int w,h;
void solve()
{
    sa(w),sa(h);
    priority_queue< pair<int,int> > que;
    int ca=0,cb=0;
 
    repp(i,1,w)
    {
        int x;
        scanf("%d",&x);
        que.push( make_pair(-x,0) );
    }
    repp(i,1,h)
    {
        int x;
        scanf("%d",&x);
        que.push( make_pair(-x,1) );
    }
    w++,h++;
    ll res=0;
    while(!que.empty())
    {
        pair<int,int>t=que.top();
        que.pop();
 
        int k=-t.first;
        int g=t.second;
        if(g==0)
        {
            res+=1LL*k*(h-cb);
            ca++;
        }
        else
        {
            res+=1LL*k*(w-ca);
            cb++;
        }
        //cout<<res<<endl;
    }
    printf("%lld\n",res);
}
 
int main()
{
    solve();
    return 0;
}