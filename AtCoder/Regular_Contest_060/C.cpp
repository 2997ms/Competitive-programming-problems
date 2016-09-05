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

const int maxn = 505;
const double PI = acos(-1.0);
const ll mod = 1e6 + 3;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}

int n,x;
int val[55];
ll dp[51][51][2505];//dp[i][j][k]表示前i个数里面，j个数组成和为k的种类数

void solve()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&val[i]);
	}
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			for(int k=0;k<=2500;k++)
			{
				dp[i][j][k]+=dp[i-1][j][k];
			}
		}
		for(int j=1;j<=i;j++)
		{
			for(int k=0;k<=2500-val[i];k++)
			{
				dp[i][j][k+val[i]]+=dp[i-1][j-1][k];
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i*x<=2500)
		{
			ans+=dp[n][i][i*x];
		}
	}
	printf("%lld",ans);
}

int main()
{
    solve();
	return 0;
}