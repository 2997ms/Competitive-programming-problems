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
typedef long double ld;

#define INF 0x333f3f3f
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))

const ll mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const double PI = acos(-1.0);


ll n, yue;
ll mi[maxn], ri[maxn];

void ex_gcd(ll a, ll b, ll &xx, ll &yy)
{
	if (b == 0)
	{
		xx = 1;
		yy = 0;
		yue = a;
	}
	else
	{
		ex_gcd(b, a%b, xx, yy);

		ll t = xx;
		xx = yy;
		yy = t - (a / b)*yy;
	}
}

void solve()
{
	ll i, j, k;
	repp(i, 1, n)
	{
		scanf("%lld", &mi[i]);
		scanf("%lld", &ri[i]);
	}
	ll cur_m = mi[1], cur_r = ri[1];
	ll f = 0;
	repp(i, 2, n)
	{
		ll xx, yy;
		ex_gcd(cur_m, mi[i], xx, yy);
		ll c = ri[i] - cur_r;
		if (c % yue != 0)
		{
			puts("-1");
			return;
		}
		else
		{
			xx = ((xx* (c / yue)) % (mi[i] / yue) + (mi[i] / yue)) % (mi[i] / yue);
			cur_r = xx*cur_m + cur_r;
			cur_m = mi[i] / yue*cur_m;
		}
	}	
	printf("%lld\n", cur_r > 0 ? cur_r : cur_m);
}

int main()
{

	while (scanf("%lld", &n) != EOF)
	{
		solve();
	}
	
	return 0;
}
