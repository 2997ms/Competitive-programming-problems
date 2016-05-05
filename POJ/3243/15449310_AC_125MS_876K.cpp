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

const int MOD = 76543;

int hs[MOD], head[MOD], nex[MOD], id[MOD], top;

void insert(int x, int y)
{
	int k = x%MOD;
	hs[top] = x; id[top] = y;
	nex[top] = head[k]; head[k] = top++;
}

int find(int x)
{
	int k = x%MOD;
	for (int i = head[k]; ~i; i = nex[i])
		if (hs[i] == x) return id[i];
	return -1;
}

ll x, z, k;
void solve()
{
	ll i, j, m;
	memset(head, -1, sizeof(head));
	top = 1;
	m = sqrt(1.0*z);
	if (k == 1)
	{
		printf("0\n");
		return;
	}
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