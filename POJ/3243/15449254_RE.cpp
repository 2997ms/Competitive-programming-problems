//#pragma comment(linker, "/STACK:655360000")  
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

const int maxn = 1e6+ 5;
const double PI = acos(-1.0);

int has[maxn], ep[maxn];

bool insert(int x, int k)
{
	int p = (x << 6) % maxn;
	if (p < 0)
		p += maxn;
	while (has[p] != x&&~ep[x])
	{
		p = (p + 1) % maxn;
	}
	if (has[p] == x&&~ep[p])
		return false;
	has[p] = x;
	ep[p] = k;
	return true;
}

int find(int x)
{
	int p = (x << 6) % maxn;
	if (p < 0)
		p += maxn;
	while (has[p] != x&&~ep[p])
		p = (p + 1) % maxn;
	return ep[p];
}

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

void exgcd(int a, int b, ll &x, ll &y)
{
	if (b)
	{
		exgcd(b, a%b, y, x);
		y = y - (a / b)*x;
	}
	else
	{
		x = 1;
		y = 0;
	}
}

ll mul(ll x, ll y, ll mo)
{
	ll res = 0;
	while (y)
	{
		if (y & 1)
		{
			res = (res + x) % mo;
		}
		y >>= 1;
		x = (x + x) % mo;
	}
	return res;
}

ll po(ll x, ll y, ll mo)
{
	ll res = 1;
	while (y)
	{
		if (y & 1)
		{
			res = mul(res, x, mo);
		}
		x = mul(x, x, mo);
		y >>= 1;
	}
	return res;
}

ll x, z, k;
void solve()
{
	ll i, j, m;
	memset(ep, -1, sizeof(ep));
	m = sqrt(1.0*z);

	ll p = 1;
	for (i = 0; i < m; i++, p = p*x%z)
	{
		insert(p*k%z, i);
	}
	ll xx = 1;
	for (i = m;; i += m)
	{
		int pos = find(xx = p*xx%z);
		if (pos != -1)
		{
			printf("%lld\n", i - pos);
			return;
		}
		if (i > z)
			break;
	}
	printf("No Solution\n");
}

int main()
{
#ifndef ONLINE_JUDGE  
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif

	while (scanf("%lld%lld%lld", &x, &z, &k) != EOF)
	{
		if (x == 0 && z == 0 && k == 0)
			break;
		solve();
	}
	return 0;
}