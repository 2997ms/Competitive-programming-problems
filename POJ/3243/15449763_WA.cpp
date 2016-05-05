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
const int mod = 1e9 + 7;

struct ed
{
	ll next;
	ll val;
	ll id;
}edge[maxn];

int num;
int head[maxn];

void insert(ll x, ll y)
{
	ll k = x%maxn;
	num++;
	edge[num].val = x;
	edge[num].id = y;
	edge[num].next = head[k];
	head[k] = num;
}

ll find(ll x)
{
	int k = x%maxn;
	for (int i = head[k]; i != -1; i = edge[i].next)
		if (edge[i].val == x)
			return edge[i].id;
	return -1;
}

ll x, z, k;
void solve()
{
	ll i, j, m;

	num = 0;
	memset(edge, -1, sizeof(edge));
	memset(head, -1, sizeof(head));

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

	while (scanf("%lld%lld%lld", &z, &x, &k) != EOF)
	{
		if (x == 0 && z == 0 && k == 0)
			break;
		solve();
	}
	return 0;
}