#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>
#include <windows.h>
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

#define INF 0x3fffffff
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
				if (val[rig] + val[lef] == t)
				{
					printf("%lld\n", val[d]);
					return;
				}
				else if (val[rig] + val[lef] > t)
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

	printf("no solution");
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