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
 
ll res;
int n, m;
int p1, p2;
int num[2], col[maxn], vis[maxn], pre[maxn];
ll st[maxn], en[maxn];
vector<int>edge[maxn];
vector<int>cycle;
 
void dfs(int x, int fa,int co)
{
	vis[x] = 1;
	col[x] = co;
	num[co]++;
	for (int i = 0; i < edge[x].size(); i++)
	{
		int k = edge[x][i];
		if (vis[k])continue;
		if (k == fa)continue;
		if (x == p1 && k == p2)continue;
		if (x == p2 && k == p1)continue;
		dfs(k, x, 1 - co);
	}
}
 
void dfs2(int x, int fa)
{
	vis[x] = 1;
	for (int i = 0; i < edge[x].size(); i++)
	{
		int k = edge[x][i];
		if (vis[k])continue;
		if (k == fa)continue;
		if (x == p1 && k == p2)continue;
		if (x == p2 && k == p1)continue;
		dfs2(k, x);
		res += abs(st[k] - en[k]);
		st[x] += st[k];
		en[x] += en[k];
	}
	if (col[x])
	{
		st[x]++;
	}
	else
	{
		en[x]++;
	}
}
 
void dfs_cycle(int x, int fa)
{
	vis[x] = 1;
	pre[x] = fa;
	for (int i = 0; i < edge[x].size(); i++)
	{
		int k = edge[x][i];
		if (k == fa)continue;
		if (vis[k])
		{
			if (p1 == -1)
			{
				p1 = x;
				p2 = k;
			}
			return;
		}
		dfs_cycle(k, x);
	}
}
 
void build_cycle()
{
	for (int i = p1; i != -1; i = pre[i])
	{
		cycle.push_back(i);
		if (i == p2)
		{
			break;
		}
	}
}
 
ll cal(ll x)
{
	memset(st, 0, sizeof(st));
	memset(en, 0, sizeof(en));
	memset(vis, 0, sizeof(vis));
	st[p1] = x;
	en[p2] = x;
	res = 0;
	dfs2(1, -1);
	return res + abs(x);
}
 
void solve()
{
	scanf("%d%d", &n, &m);
	if (n % 2)
	{
		puts("-1");
		return;
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	p1 = p2 = -1;
	if (m == n - 1)
	{
		dfs(1, -1, 0);
		if (num[0] == num[1])
		{
			memset(vis, 0, sizeof(vis));
			res = 0;
			dfs2(1, -1);
		}
		else
		{
			res = -1;
		}
		printf("%lld\n", res);
	}
	else
	{
		memset(vis, 0, sizeof(vis));
		dfs(1, -1, 0);
		memset(vis, 0, sizeof(vis));
		dfs_cycle(1, -1);
		build_cycle();
		
		if (cycle.size() % 2 == 0)
		{
			if (num[0] != num[1])
			{
				puts("-1");
				return;
			}
			ll le = -(1e6 + 5), ri = 1e6 + 5;
			while (ri - le > 5)
			{
				ll mid = (ri + le) / 2;
				ll t1 = cal(mid);
				ll t2 = cal(mid + 1);
 
				if (t1 < t2)
				{
					ri = mid;
				}
				else
				{
					le = mid;
				}
			}
			ll ans = LL_INF;
			for (ll i = le; i <= ri; i++)
			{
				ans = min(ans, cal(i));
			}
			printf("%lld\n", ans);
		}
		else
		{
			memset(num, 0, sizeof(num));
			memset(vis, 0, sizeof(vis));
			dfs(p1, -1, 0);
			col[p2] = 0;
			if (num[1]>num[0])
			{
				en[p1] = en[p2] = (num[1] - num[0]) / 2;
			}
			else
			{
				st[p1] = st[p2] = (num[0] - num[1]) / 2;
			}
			res = 0;
			memset(vis, 0, sizeof(vis));
			dfs2(1, -1);
			printf("%lld", res + abs((num[0] - num[1]) / 2));
		}
	}
}
 
int main()
{
	solve();
	return 0;
}