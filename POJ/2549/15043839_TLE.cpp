#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>
#include <cstring>
#include <cstring>
#include <vector>  
#include <string>  
#include <time.h>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

#define INF 0x3fffffffffffffff
const int maxn = 1002;

int n, k;
ll val[maxn];

void input()
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &val[i]);
	}
}

void solve()
{
	sort(val, val + n);
	k = unique(val, val + n) - val;

	int d, f;
	int lef, rig;
	for (d = k - 1; d >= 0; d--)
	{
		for (f = d - 1; f >= 0; f--)
		{
			lef = 0;
			rig = f - 1;

			ll t = val[d] - val[f];
			while (lef < rig)
			{
				ll s = val[rig] + val[lef];
				if (s == t)
				{
					printf("%lld\n", val[d]);
					return;
				}
				else if (s > t)
				{
					rig--;
				}
				else
				{
					lef++;
				}
			}
		}
	}
	ll maxn = -INF;
	for (d = 0; d < k; d++)
	{
		for (f = d + 1; f < k; f++)
		{
			lef = 0;
			rig = f + 1;

			ll t = val[d] - val[f];
			while (lef < rig)
			{
				ll s = val[rig] + val[lef];
				if (s == t)
				{
					maxn = max(maxn, val[d]);
				}
				else if (s + val[lef] > t)
				{
					rig--;
				}
				else
				{
					lef++;
				}
			}
		}
	}
	if (maxn == INF)
	{
		printf("no solution\n");
	}
	else
	{
		printf("%lld\n", maxn);
	}
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;
		input();
		solve();
	}
	system("pause");
	return 0;
}