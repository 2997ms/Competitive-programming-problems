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

const int maxn = 1e5+5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}

int n;
char val[maxn];
int v[maxn];
int v1[maxn],v2[maxn];

void solve()
{
    scanf("%d",&n);
    scanf("%s",val+1);

    v1[0]=1,v2[0]=0;
    for(int i=1;i<=n;i++)
    {
        v[i]=(val[i]=='b');
        v1[i]=!v1[i-1];
        v2[i]=!v2[i-1];
    }
    int res=1e5+5;
    int r1=0,r2=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i]==1)
        {
            if(v[i]!=v1[i])
            {
                r1++;
            }
        }
        else
        {
            if(v[i]!=v1[i])
            {
                r2++;
            }
        }
    }
    res=min(r1,r2)+abs(r1-r2);

    int r3=0,r4=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i]==1)
        {
            if(v[i]!=v2[i])
            {
                r3++;
            }
        }
        else
        {
            if(v[i]!=v2[i])
            {
                r4++;
            }
        }
    }
    int t=min(r3,r4)+abs(r3-r4);
    res=min(res,t);
    printf("%d\n",res);
}

int main()
{
    solve();
    return 0;
}