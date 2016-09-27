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
 
const int maxn = 2e5+5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}
 
char x[maxn];
int k;
 
void solve()
{
    scanf("%s",x+1);
    sa(k);
 
    int len=strlen(x+1);
    repp(i,1,len)
    {
        int t = (26-(x[i]-'a'))%26;
        //cout<<t<<endl;
        if(t<=k)
        {
            x[i]='a';
            k-=t;
        }
    }
    if(k)
    {
        x[len]= (x[len]-'a' + k)%26+'a'; 
    }
    cout<<x+1<<endl;
}
 
int main()
{
    solve();
    return 0;
}