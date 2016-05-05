#pragma warning(disable:4996)
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
#include <set>
#include <map>
using namespace std;
typedef long long ll;

#define INF 0x333f3f3f
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))

const ll mod = 100000007;
const int maxn = 1e6 + 5;
const double PI = acos(-1.0);

int n;
bool vis[maxn];
int mobi[maxn], cnt[maxn];

void mob() 
{
	int i, j;
	for (i = 1; i <= 1e5 + 5; i++)
		mobi[i] = 1, vis[i] = false;

	for (i = 2; i <= 1e5 + 5; i++)
	{
		if (vis[i]) continue;
		for (j = i; j <= 1e5 + 5; j += i)
		{
			vis[j] = true;
			if ((j / i) % i == 0)
			{
				mobi[j] = 0; continue;
			}
			mobi[j] = -mobi[j];
		}
	}
}

ll c(ll x)
{
	if (x < 4)
		return 0;
	else
		return x*(x - 1) * (x - 2) * (x - 3) / 24;
}

void solve()
{
	ll i, j, k;
	int u, v;
	int maxx = 0;
	
	memset(cnt, 0, sizeof(cnt));

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &v);
		cnt[v]++;
		maxx = max(maxx, v);
	}
	for (i = 1; i <= maxx; i++)
	{
		for (j = i + i; j <= maxx; j += i)
		{
			cnt[i] += cnt[j];
		}
	}

	ll ans = 0;
	for (i = 1; i <= maxx; i++)
	{
		ans += ((ll)mobi[i] * c(cnt[i]));
	}
	printf("%lld\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE  
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif

	mob();
	while (scanf("%d", &n) != EOF)
	{
		solve();
	}
	return 0;
}
