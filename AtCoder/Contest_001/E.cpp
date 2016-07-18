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
typedef pair<int, ll> pill;

#define eps 1e-10
#define LL_INF 0x3fffffffffffffff
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

const int maxn = 4e3 + 5;
const ll mod = 1e9+7;
const double PI = acos(-1.0);

int n;
int u[200005],v[200005];
ll fac[2*maxn],infac[2*maxn];
ll cnt[maxn][maxn];

ll po(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)
		{
			res =(res*x)%mod;
		}
		x=x*x%mod;
		y=y>>1;
	}
	return res;
}

void init()
{
	int i,j,k;
	
	fac[0]=1;
	
	repp(i,1,8000)
	{
		fac[i]=(fac[i-1]*i)%mod;
		infac[i]=po(fac[i],mod-2);
	}
}

ll cal(int x,int y)
{
	return ((fac[x+y]*infac[x])%mod*infac[y])%mod;
}

void solve()
{
	int i,j,k;
	
	memset(cnt,0,sizeof(cnt));

	repp(i,1,n)
	{
		sa(u[i]),sa(v[i]);
		cnt[2000-u[i]][2000-v[i]]++;
	}
	for(i=0;i<=4000;i++)
	{
		for(j=0;j<=4000;j++)
		{
			if(i>0)
			{
				cnt[i][j] = (cnt[i][j]+cnt[i-1][j])%mod;
			}
			if(j>0)
			{
				cnt[i][j] = (cnt[i][j]+cnt[i][j-1])%mod;
			}
		}
	}
	ll r=0;
	repp(i,1,n)
	{
		r = (r+cnt[2000+u[i]][2000+v[i]])%mod;
		r = ((r-cal(2*u[i],2*v[i]))%mod+mod)%mod;
	}
	r = (r*po(2,mod-2))%mod;
	printf("%lld\n",r);
}

int main()
{
    init();
    while(scanf("%d",&n)!=EOF)
    {
    	solve();
    }
    return 0;
}
