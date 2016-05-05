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

const int maxn = 1e6 + 7;
const double PI = acos(-1.0);

ll has[maxn], ep[maxn];

bool insert(ll x, ll k)
{
	ll p = x % maxn;
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

ll find(ll x)
{
	ll p = (x) % maxn;
	if (p < 0)
		p += maxn;
	while (has[p] != x&&~ep[p])
		p = (p + 1) % maxn;
	return ep[p];
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
		ll pos = find(xx = p*xx%z);
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
	while (scanf("%lld%lld%lld", &x, &z, &k) != EOF)
	{
		if (x == 0 && z == 0 && k == 0)
			break;
		solve();
	}
	return 0;
}