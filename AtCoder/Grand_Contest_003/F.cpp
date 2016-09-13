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
 
int h,w;
ll k;
char x[1005][1005];
struct ma
{
	ll val[3][3];
};
 
ma mul(ma a,ma b)
{
	ma t;
	memset(t.val,0,sizeof(t.val));
 
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
		{
			for(int k=1;k<=2;k++)
			{
				if(!a.val[i][k]||!b.val[k][j])continue;
				t.val[i][j]+=(a.val[i][k]*b.val[k][j])%mod;
				t.val[i][j]=(t.val[i][j]+mod)%mod;
			}
		}
	}
	return t;
}
 
ma po(ma x,ll y)
{
	ma t;
	memset(t.val,0,sizeof(t.val));
	for(int i=1;i<=2;i++)
	{
		t.val[i][i]=1;
	}
	while(y)
	{
		if(y&1)
		{
			t=mul(t,x);
		}
		x=mul(x,x);
		y>>=1;
	}
	return t;
}
 
void solve()
{
	scanf("%d%d%lld",&h,&w,&k);
 
	int a=0,b=0,c=0;
	for(int i=1;i<=h;i++)
	{
		scanf("%s",x[i]+1);
		for(int j=1;j<=w;j++)
		{
			a+=(x[i][j]=='#');
		}
	}
	int ud=0,lr=0;
	for(int i=1;i<=h;i++)
	{
		lr+=(x[i][1]=='#'&&x[i][w]=='#');
	}
	for(int i=1;i<=w;i++)
	{
		ud+=(x[1][i]=='#'&&x[h][i]=='#');
	}
	if((lr&&ud)||(k==1))
	{
		puts("1");
		return;
	}
	if(!lr&&!ud)
	{
		ll res = po(a,k-1,mod);
		printf("%lld",res);
		return;
	}
	c=ud+lr;
	if(ud)
	{
		for(int i=1;i<=w;i++)
		{
			for(int j=2;j<=h;j++)
			{
				b+=(x[j][i]=='#'&&x[j-1][i]=='#');
			}
		}
	}
	else
	{
		for(int i=1;i<=h;i++)
		{
			for(int j=2;j<=w;j++)
			{
				b+=(x[i][j]=='#'&&x[i][j-1]=='#');
			}
		}
	}
	ma t;
	t.val[1][1]=a;
	t.val[1][2]=-b;
	t.val[2][1]=0;
	t.val[2][2]=c;
	//cout<<a<<" "<<b<<" "<<c<<endl;
	t=po(t,k-1);
	ll res = ((t.val[1][1]+t.val[1][2])%mod+mod)%mod;
	printf("%lld",res);
}
 
 
int main()
{
    solve();
	return 0;
}