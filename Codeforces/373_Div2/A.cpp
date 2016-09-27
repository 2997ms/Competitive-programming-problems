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

const int maxn = 5005;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}

int n;
int val[maxn];

void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&val[i]);
    }

    if(val[n]==15)
    {
        puts("DOWN");
        return;
    }
    else if(val[n]==0)
    {
        puts("UP");
        return;
    }
    if(n==1)
    {
        puts("-1");
    }
    else
    {
        if(val[n]>val[n-1])
        {
            if(val[n]==15)
            {
                puts("DOWN");
            }
            else
            {
                puts("UP");
            }
        }
        else 
        {
            if(val[n]==0)
            {
                puts("UP");
            }
            else
            {
                puts("DOWN");
            }
        }
    }
}

int main()
{
    solve();
    return 0;
}