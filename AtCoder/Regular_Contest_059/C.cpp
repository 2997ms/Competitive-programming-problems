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
 
const int maxn = 1e3 + 5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}
 
int n;
int val[maxn];
 
void solve()
{
	sa(n);
	int minn=INF,maxx=-INF;
	repp(i,1,n)
	{
		sa(val[i]);
		minn=min(minn,val[i]);
		maxx=max(maxx,val[i]);
	}
	int res = INF;
	for(int i=minn;i<=maxx;i++)
	{
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			ans+=(val[j]-i)*(val[j]-i);
		}
		res=min(res,ans);
	}
	cout<<res<<endl;
}
 
int main()
{
    solve();
	return 0;
}