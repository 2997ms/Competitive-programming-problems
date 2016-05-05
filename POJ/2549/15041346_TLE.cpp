#pragma warning(disable:4996)
#include <algorithm>
#include <iostream>
#include <utility>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

#define INF 0x3fffffff
typedef long long ll;

int n, k, num;
const int mod = 1e9 + 7;
const int maxn = 1005;

ll val[maxn];
map<ll, int>has;
vector<pair<int, int>>a[300005];

void input()
{
	for (k = 1; k <= n; k++)
	{
		scanf("%lld", val + k);
	}
}

void solve()
{
	num = 0;

	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (val[i] == val[j])continue;
			ll sum = val[i] + val[j];

			if (has[sum] == 0)
			{
				has[sum] = ++num;
				a[num].push_back(make_pair(i, j));
			}
			else
			{
				a[num].push_back(make_pair(i, j));
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			ll s = val[i] - val[j];
			if (has[s])
			{
				if (val[i] != val[j])
				{
					int nn = has[s];
					int si = a[nn].size();
					for (int hh = 0; hh < si; hh++)
					{
						if (a[nn][hh].first != i&&a[nn][hh].first != j&&a[nn][hh].second != i&&a[nn][hh].second != j)
						{
							printf("%lld\n", val[i]);
							return;
						}
					}
				}
			}
		}
	}
	printf("no solution\n");
}

void cle()
{
	int i;
	for (i = 1; i <= num; i++)
	{
		a[i].clear();
	}
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		input();
		solve();
		cle();
	}

	//system("pause");
	return 0;
}
