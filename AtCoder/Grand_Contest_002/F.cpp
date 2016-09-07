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
 
const int maxn = 4e6 + 5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}
 
ll n,k;
ll fac[maxn],inv[maxn];
ll dp[2005][2005];
ll C(ll n,ll x)
{
	return fac[n]*inv[x]%mod*inv[n-x]%mod;
}
 
void init()
{
	fac[0]=1;
	inv[0]=1;
	ll up = 4e6;
	for(ll i=1;i <= up;i++)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=po(fac[i],mod-2,mod);
	}
}
 
ll cal(ll i,ll j)
{
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	ll res=0;
	if(i==0&&j==0)
	{
		return 1;
	}
	if(j > i)
	{
		res += C(i+j*(k-1)-1,k-2)*cal(i,j-1)%mod;
	}
	res%=mod;
	if(i)
	{
		res += cal(i-1,j);
	}
	res%=mod;
	dp[i][j]=res;
	return res;
}
 
void solve()
{
	memset(dp,-1,sizeof(dp));
	cin>>n>>k;
	if(k==1)
	{
		cout<<1<<endl;
		return;
	}
	ll res= cal(n,n);
	for(ll i=1;i<=n;i++)
	{
		res=res*i%mod;
	}
	cout<<res<<endl;
}
int main()
{
    init();
    solve();
	return 0;
}