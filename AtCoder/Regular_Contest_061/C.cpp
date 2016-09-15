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
 
string s;
void solve()
{
	cin>>s;
	int len=s.length();
	
	ll ans=0;
	for(int i=0;i<(1<<(len-1));i++)
	{
		vector<int> pos;
		for(int k=0;k<len;k++)
		{
			if((i>>k)&1)
			{
				pos.push_back(k+1);
			}
		}
		/*
		for(int i=0;i<pos.size();i++)
		{
			cout<<" "<<pos[i];
		}
		cout<<endl;
		*/
		int st,k;
		for(st=0,k=0;k<pos.size();k++)
		{
			ll p=0;
			for(int j=st;j<pos[k];j++)
			{
				p=p*10+s[j]-'0';
			}
			ans+=p;
			st=pos[k];
		}
		ll p=0;
		for(;st<len;st++)
		{
			p=p*10+s[st]-'0';
		}
		ans+=p;
		//out<<p<<endl;
	}
	printf("%lld",ans);
}
 
int main()
{
    solve();
	return 0;
}
