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
 
int n,cnt;
int vis[maxn],pri[maxn];
ll val[maxn],two[maxn],tri[maxn];
map<ll,int>num;
map<ll,ll>con;
 
void init()
{
    cnt=0;
    int up=1e5;
    memset(vis,0,sizeof(vis));
 
    for(int i=2;i<=up;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            cnt++;
            pri[cnt]=i;
        }
        for(int j=i+i;j<=up;j+=i)
        {
            vis[j]=1;
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        two[i] = 1LL*pri[i]*pri[i];
        tri[i] = 1LL*two[i]*pri[i];
    }
}
 
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&val[i]);
        
        ll tmp = val[i];
        ll rev=1;
        ll ori=1;
        for(int j=1;j<=cnt&&pri[j]<=tmp;j++)
        {
            if(pri[j]>1200)break;
            if(tmp%pri[j]==0)
            {
                int c=0;
                while(tmp%pri[j]==0)
                {
                    c++;
                    tmp/=pri[j];
                }
                if(c%3==1)
                {
                    rev*=two[j];
                    ori*=pri[j];
                }
                else if(c%3==2)
                {
                    rev*=pri[j];
                    ori*=two[j];
                }
            }
        }
        //cout<<rev<<endl;
        //cout<<tmp*tmp<<endl;
        //cout<<1e18/rev<<endl;
        if(sqrt(1.0*tmp+0.5)*sqrt(1.0*tmp+0.5)==tmp)
        {
            rev*=sqrt(1.0*tmp);
            ori*=tmp;
        }
        else if(tmp*tmp<(1e18/rev))
        {
            ori*=tmp;
            rev*=tmp*tmp;
        }
        else
        {
            ori*=tmp;
            rev=-1;
        }
        con[ori]=rev;
        num[ori]++;
 
    }
    map<ll,int>::iterator it;
    int ans=0;
    /*
    for(it=num.begin(); it!=num.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<" "<<con[it->first]<<endl;
    }
    */
    for(it=num.begin(); it!=num.end(); it++)
    {
        if(it->first==1)continue;
        if(it->second==0)continue;
        ll tmp = it->first;
        ll s = con[tmp];
 
        //cout<<s<<" "<<num[s]<<endl;
        //cout<<it->second<<endl;
        ans+=max(it->second,num[s]);
        //cout<<"ans: "<<ans<<endl;
        it->second=0;
        num[s]=0;
    }
    if(num[1])ans++;
    printf("%d\n",ans);
}
 
int main()
{
    init();
    solve();
    return 0;
}