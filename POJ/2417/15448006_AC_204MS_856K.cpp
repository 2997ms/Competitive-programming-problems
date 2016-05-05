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

struct ba
{
	ll val;
	ll ind;
}baby[maxn];

ll p, b, n;

ll po(ll x, ll y, ll mo)
{
	ll res = 1;
	x %= mo;
	while (y)
	{
		if (y & 1)
			res = (res*x)%mo;
		x = (x*x)%mo;
		y >>= 1;
	}
	return res;
}

bool cmp(ba a, ba b)
{
	if (a.val == b.val)
		return a.ind < b.ind;
	else
		return a.val < b.val;
}

int search(int r, ll k)
{
	int le = 1, ri = r, mid;
	while (le <= ri)
	{
		mid = (le + ri) >> 1;
		if (baby[mid].val == k)
		{
			return baby[mid].ind - 1;
		}
		else if (baby[mid].val > k)
		{
			ri = mid - 1;
		}
		else
		{
			le = mid + 1;
		}
	}
	return -1;
}

void solve()
{
	ll i, j, k;
	ll m = ceil(sqrt(1.0*(p - 1)));

	baby[1].ind = 1, baby[1].val = 1;
	for (i = 2; i <= m; i++)
	{
		baby[i].ind = i;
		baby[i].val = (baby[i - 1].val* b)%p;
	}
	sort(baby + 1, baby + m + 1, cmp);
	
	
	ll tmp = n;
	ll gaint = po(po(b, p - 2, p), m, p);
	for (i = 0; i < m; i++)
	{
		int pos = search(m, tmp);
		if (pos != -1)
		{
			printf("%lld\n", i*m + pos);
			return;
		}
		tmp = (tmp*gaint)%p;
	}
	printf("no solution\n");
}

int main()
{
#ifndef ONLINE_JUDGE  
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
	while (scanf("%lld%lld%lld", &p, &b, &n) != EOF)
	{
		solve();
	}
	return 0;
}