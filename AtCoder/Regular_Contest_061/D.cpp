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
const ll mod = 1e9 + 7;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}
 
int h,w,n;
ll ans[maxn];
map< pair<int,int>, ll >num;
 
void solve()
{
    scanf("%d%d%d",&h,&w,&n);
 
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        for(int le=0;le<=2;le++)
        {
            for(int ri=0;ri<=2;ri++)
            {
                int x=a-le;
                int y=b-ri;
                if(x>=1&&x<=h-2&&y>=1&&y<=w-2)
                {
                    num[make_pair(x,y)]++;
                }
            }
        }
    }
    ll all = 1LL*(h-2)*(w-2);
    ans[0]=all-num.size();
 
    map< pair<int,int>, ll > ::iterator it;
    for(it = num.begin();it!=num.end();it++)
    {
        ans[it->second]++;
        //cout<<it->first.first<<" "<<it->first.second<<" "<<it->second<<endl;
    }
    for(int i=0;i<=9;i++)
    {
        printf("%lld\n",ans[i]);
    }
}
 
int main()
{
    solve();
    return 0;
}