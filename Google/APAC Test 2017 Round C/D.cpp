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

const int maxn = 4005;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}

int n;
int mxa,mxb;
pair<int,int>AD[maxn],DA[maxn];

bool cmp(pair<int,int>a)
{
    return a.first==mxa || a.second==mxb;
}

bool x(int a)
{
    return a==0;
}

void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        AD[i].first=u,AD[i].second=v;
        DA[i].first=v,DA[i].second=u;
    }
    sort(AD+1,AD+n+1);
    sort(DA+1,DA+n+1);
    
    /*
    int num[3]={0,0,0};
    int b = remove_if(num+1,num+3,x)-num;
    cout<<b<<endl;
    */
    while(n)
    {
        if(AD[n].second == DA[n].first)
        {
            //cout<<n<<endl;
            //cout<<AD[n].second<<endl;
            puts("YES");
            return;
        }
        mxa = AD[n].first;
        mxb = DA[n].first;
        //cout<<mxa<<" "<<mxb<<endl;
        remove_if(AD+1,AD+n+1,cmp);

        mxa = DA[n].first;
        mxb = AD[n].first;
        n = remove_if(DA+1,DA+n+1,cmp) - DA - 1;
    }
    puts("NO");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/2997ms/Desktop/eve/algorithm/algorithm/D-large-practice.in", "r", stdin);
    freopen("/Users/2997ms/Desktop/eve/algorithm/algorithm/o.txt", "w", stdout);
#endif
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}