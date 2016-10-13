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
 
const int maxn = 4e5 + 5;
const ll mod = 1000;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
 
int n, q,cnt;
char val[maxn];
int ch[maxn][30];
int pre[maxn], num[maxn], is[maxn], res[maxn], v[maxn];
 
char x[100005][30];
int nu[30][30], id[30];
vector<int>p[100005];
map<int, int>hax;
 
void init()
{
	cnt = 0;
}
 
void insert(char *x, int len, int id)
{
	int now = 0;
	for (int i = 1; i <= len; i++)
	{
		int k = x[i] - 'a' + 1;
		if (!ch[now][k])
		{
			++cnt;
			ch[now][k] = cnt;
		}
		pre[ch[now][k]] = now;
		now = ch[now][k];
		v[now] = k;
		num[now]++;
	}
	is[now]++;
	hax[id] = now;
}
 
void cal(int x)
{
	while (x)
	{
		for (int i = 1; i <= 26; i++)
		{
			if (i != v[x] && ch[pre[x]][i])
			{
				nu[i][v[x]] += num[ch[pre[x]][i]];
			}
		}
		nu[v[x]][v[x]] += is[x];
		x = pre[x];
	}
}
 
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", val + 1);
		insert(val, strlen(val + 1), i);
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		int op;
		scanf("%d%s", &op, x[i] + 1);
		p[op].push_back(i);
	}
 
	for (int i = 1; i <= n; i++)
	{
		memset(nu, 0, sizeof(nu));
		int o = hax[i];
		cal(o);
		for (int j = 0; j < p[i].size(); j++)
		{
			int k = p[i][j];
 
			for (int g = 1; g <= 26; g++)
			{
				id[g] = x[k][g] - 'a' + 1;
			}
			int f = 0;
			for (int g = 1; g <= 26; g++)
			{
				for (int d = g; d <= 26; d++)
				{
					f += nu[id[g]][id[d]];
				}
			}
			res[k] = f;
		}
	}
	for (int i = 1; i <= q; i++)
	{
		printf("%d\n", res[i]);
	}
}
 
 
int main()
{
 
	solve();
	return 0;
}