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
const int maxn = 105;
const double PI = acos(-1.0);

ll po(ll x, ll y, ll mo)
{
	ll res = 1;
	while (y)
	{
		if (y & 1)
			res = res*x%mo;
		x = x*x%mo;
		y >>= 1;
	}
	return res;
}

ll a, p;

void solve()
{
	ll i, j, k;
	scanf("%lld%lld", &a, &p);
	a = (a%p + p) % p;

	if (po(a, (p - 1) / 2, p) == 1)
	{
		printf("1\n\n");
	}
	else
	{
		printf("-1\n\n");
	}
}

int main()
{
#ifndef ONLINE_JUDGE  
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif

	int i, t;
	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		printf("Scenario #%d:\n", i);
		solve();
	}

	return 0;
}
