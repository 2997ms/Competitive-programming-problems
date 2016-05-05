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
	ll maxn = -INF;
	for (d = k - 1; d >= 0; d--)
	{
		for (f = k - 1; f >= 0; f--)
		{
			if (val[d] == val[f])continue;
			lef = 0;
			rig = k - 1;

			ll t = val[d] - val[f];
			while (lef < rig)
			{
				ll s = val[rig] + val[lef];
				if (s == t)
				{
					if (val[rig] != val[d] && val[rig] != val[f] && val[lef] != val[d] && val[lef] != val[f])
					{
						maxn = max(maxn, val[d]);
					}
					rig--;
					lef++;
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

	if (maxn == -INF)
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
	//system("pause");
	return 0;
}