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
 
int n,q;
std::vector<ll> val;
ll ans[maxn];
 
void solve()
{
	scanf("%d%d",&n,&q);
	val.push_back(n);
 
	for(int i=1;i<=q;i++)
	{
		ll x;
		scanf("%lld",&x);
 
		while(val.size()&&val.back()>=x)
		{
			val.pop_back();
		}
		val.push_back(x);
	}
	map<ll,ll>app;
	app[val.back()]=1;
 
	while(val.size())
	{
		ll k=val.back();
		val.pop_back();
 
		map<ll,ll>::iterator var = app.upper_bound(k);
		map<ll,ll>::iterator it;
		for(it=var;it!=app.end();it++)
		{
			ll x= it->first;
			ll y= it->second;
 
			ll p1 = x/k;
			ll p2 = x%k;
 
			app[p2]+=y;
			app[k]+=y*p1;
		}
		app.erase(var,app.end());
	}
	for(int i=n;i>=1;i--)
	{
		ans[i]=app[i]+ans[i+1];
	}
	for(int i=1;i<=n;i++)
	{
		printf("%lld\n", ans[i]);
	}
}
 
 
int main()
{
    solve();
	return 0;
}