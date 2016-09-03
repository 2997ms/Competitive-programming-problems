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
ll po(ll a, ll b) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}
 
int n;
vector <int> app[30];
char val[maxn];
 
int idx(char x)
{
    return x-'a'+1;
}
 
void solve()
{
    scanf("%s",val+1);
    int len=strlen(val+1);
    repp(i,1,len)
    {
        app[idx(val[i])].push_back(i);
    }
    int flag=0;
    int x=0,y=0;
    repp(i,1,26)
    {
        int sz=app[i].size();
        if(sz<=1)
        {
            continue;
        }
        for(int j=1;j<sz;j++)
        {
            if(app[i][j]-app[i][j-1]<3)
            {
                flag=1;
                x=app[i][j-1];
                y=app[i][j];
                break;
            }
        }
        if(flag)
        {
            break;
        }
    }
    if(!flag)
    {
        puts("-1 -1");
    }
    else
    {
        printf("%d %d",x,y);
    }
}
 
int main()
{
 
    solve();
    return 0;
}