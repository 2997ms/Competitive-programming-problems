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
 
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
 
int n, m;
int q;
int val[maxn], app[maxn], idx[maxn], res[maxn];
 
void solve()
{
	scanf("%d%d", &n, &m);
	scanf("%d", &q);
 
	for (int i = 1; i <= q; i++)
	{
		scanf("%d", &val[i]);
	}
	vector<int>pre;
	for (int i = q; i >= 1; i--)
	{
		if (app[val[i]] == 0)
		{
			app[val[i]] = 1;
			idx[val[i]] = pre.size();
			pre.push_back(val[i]);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (!app[i])
		{
			idx[i] = pre.size();
			pre.push_back(i);
		}
	}
	int sz = pre.size();
	while (sz >= 2)
	{
		if (pre[sz - 2] > pre[sz - 1])
		{
			break;
		}
		else
		{
			sz--;
			pre.pop_back();
		}
	}
	pre.pop_back();
	res[0] = n;
	for (int i = q; i >= 1; i--)
	{
		if (res[idx[val[i]]])
		{
			res[idx[val[i]]]--;
			res[idx[val[i]] + 1]++;
		}
	}
	sz = pre.size();
	for (int i = 0; i < sz;i++)
	{
		if (res[i])
		{
			puts("No");
			return;
		}
	 }
	puts("Yes");
}
int main()
{
	solve();
	return 0;
}