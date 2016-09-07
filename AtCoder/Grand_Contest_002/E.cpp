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
const ll mod = 1e6 + 3;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}
 
int n;
int val[maxn];
 
void solve()
{
	scanf("%d", &n);
	int maxx=0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);
		val[i]++;
		maxx=max(maxx,val[i]);
	}
	n++;
	val[n]=maxx;
	sort(val + 1, val + n + 1);
	reverse(val + 1, val + n + 1);
	int i, j;
	for (i = 1; i <= n; i++)
	{
		if (val[i] < i)
		{
			break;
		}
	}
	int up =val[i-1]-(i-1);
	int right=0;
	//cout<<i<<endl;
	//cout<<n<<endl;
	for (j = i; j <= n; j++)
	{
		if (val[j] < (i-1))
		{
			break;
		}
		else
		{
			right++;
		}
	}
	//cout<<val[i-1]-i<<endl;
	//cout<<j-i<<endl;
	//cout<<i<<endl;
	//cout<<val[1]<<" "<<val[2]<<" "<<val[3]<<" "<<val[4]<<endl;
	int res=0;
	//cout<<up<<" "<<right<<endl;
	if(up%2!=right%2)
	{
		res=1;
	}
	else
	{
		res=up%2;
	}
	if(res)
	{
		puts("First");
	}
	else
	{
		puts("Second");
	}
}
int main()
{
    solve();
	return 0;
}