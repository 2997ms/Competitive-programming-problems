#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>  
#include <string>  
#include <cmath>
#include <queue>
#include <map>
using namespace std;

#define INF 0x3fffffff
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1000505;

map<int, int>ha;
int N, nx, sear;
int dic[305];
char x[105][1505];
int sa[maxn], num[maxn];
int ran[maxn], height[maxn];
int wa[maxn], wb[maxn], wv[maxn], wss[maxn];

int cmp(int *r, int a, int b, int l)
{
	return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int *r, int n, int m)
{
	int i, j, p, *x = wa, *y = wb, *t;
	for (i = 0; i < m; i++)
	{
		wss[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		wss[x[i] = r[i]] ++;
	}
	for (i = 1; i < m; i++)
	{
		wss[i] += wss[i - 1];
	}
	for (i = n - 1; i >= 0; i--)
	{
		sa[--wss[x[i]]] = i;
	}

	for (j = 1, p = 1; p < n; j *= 2, m = p)
	{
		for (p = 0, i = n - j; i < n; i++)
		{
			y[p++] = i;
		}
		for (i = 0; i < n; i++)
		{
			if (sa[i] >= j)
			{
				y[p++] = sa[i] - j;
			}
		}
		for (i = 0; i < n; i++)
		{
			wv[i] = x[y[i]];
		}
		for (i = 0; i < m; i++)
		{
			wss[i] = 0;
		}
		for (i = 0; i < n; i++)
		{
			wss[wv[i]] ++;
		}
		for (i = 1; i < m; i++)
		{
			wss[i] += wss[i - 1];
		}
		for (i = n - 1; i >= 0; i--)
		{
			sa[--wss[wv[i]]] = y[i];
		}
		for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
		{
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
		}
	}
}

void calHeight(int *r, int n)
{
	int i, j, k = 0;
	for (i = 1; i <= n; i++)
	{
		ran[sa[i]] = i;
	}

	for (i = 0; i < n; i++)
	{
		if (k)
		{
			k--;
		}
		else
		{
			k = 0;
		}
		j = sa[ran[i] - 1];
		while (r[i + k] == r[j + k])
		{
			k++;
		}
		height[ran[i]] = k;
	}
}

bool check(int x)
{
	int i, k = 0;
	int count = 0;
	for (i = 1; i <= nx; i++)
	{
		if (k == 0)
		{
			if (height[i] >= x)
			{
				int pos1 = lower_bound(dic + 1, dic + sear, sa[i - 1]) - dic;
				int pos2 = lower_bound(dic + 1, dic + sear, sa[i]) - dic;

				if (ha[(pos1 + 1) / 2] == 0)
				{
					ha[(pos1 + 1) / 2] = 1;
					count++;
				}
				if (ha[(pos2 + 1) / 2] == 0)
				{
					ha[(pos2 + 1) / 2] = 1;
					count++;
				}
				if (count > N / 2)
				{
					return true;
				}
				k = 1;
			}
		}
		else
		{
			if (height[i] >= x)
			{
				int pos1 = lower_bound(dic + 1, dic + sear, sa[i - 1]) - dic;
				int pos2 = lower_bound(dic + 1, dic + sear, sa[i]) - dic;

				if (ha[(pos1 + 1) / 2] == 0)
				{
					ha[(pos1 + 1) / 2] = 1;
					count++;
				}
				if (ha[(pos2 + 1) / 2] == 0)
				{
					ha[(pos2 + 1) / 2] = 1;
					count++;
				}
				if (count > N / 2)
				{
					return true;
				}
				k = 1;
			}
			else
			{
				ha.clear();
				count = 0;
				k = 0;
			}
		}
	}
	return false;
}

void solve()
{
	int i, j, len;
	int max_len = 0;

	nx = 0;
	sear = 1;

	for (i = 1; i <= N; i++)
	{
		dic[sear++] = nx;
		scanf("%s", x[i]);

		len = strlen(x[i]);
		max_len = max(len, max_len);
		for (j = 0; j < len; j++)
		{
			num[nx++] = x[i][j] - 'a' + 1;
		}
		dic[sear++] = nx - 1;
		num[nx++] = '$';
	}
	num[nx] = 0;

	da(num, nx + 1, 130);
	calHeight(num, nx);

	int le, ri, mid;
	le = 0;
	ri = max_len + 1;

	while (le < ri - 1)
	{
		mid = (le + ri) / 2;
		if (check(mid))
		{
			le = mid;
		}
		else
		{
			ri = mid - 1;
		}
	}
	if (le == 0)
	{
		printf("?\n");
	}
	else
	{
		int j, kk;
		int k = 0;
		int count = 0;
		ha.clear();
		for (i = 1; i <= nx; i++)
		{
			if (k == 0)
			{
				if (height[i] >= le)
				{
					int pos1 = lower_bound(dic + 1, dic + sear, sa[i - 1]) - dic;
					int pos2 = lower_bound(dic + 1, dic + sear, sa[i]) - dic;

					if (ha[(pos1 + 1) / 2] == 0)
					{
						ha[(pos1 + 1) / 2] = 1;
						count++;
					}
					if (ha[(pos2 + 1) / 2] == 0)
					{
						ha[(pos2 + 1) / 2] = 1;
						count++;
					}
					k = 1;
				}
			}
			else
			{
				if (height[i] >= le)
				{
					int pos1 = lower_bound(dic + 1, dic + sear, sa[i - 1]) - dic;
					int pos2 = lower_bound(dic + 1, dic + sear, sa[i]) - dic;

					if (ha[(pos1 + 1) / 2] == 0)
					{
						ha[(pos1 + 1) / 2] = 1;
						count++;
					}
					if (ha[(pos2 + 1) / 2] == 0)
					{
						ha[(pos2 + 1) / 2] = 1;
						count++;
					}

					k = 1;
				}
				else
				{
					ha.clear();
					if (count > N / 2)
					{
						for (j = sa[i - 1], kk = 1; kk <= le; kk++, j++)
						{
							printf("%c", num[j] + 'a' - 1);
						}
						printf("\n");
					}
					count = 0;
					k = 0;
				}
			}
		}
	}
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int mm = 0;
	while (scanf("%d", &N) != EOF)
	{
		if (N == 0)
			break;
		if (mm > 0)
		{
			printf("\n");
		}
		mm++;
		solve();
	}
	return 0;
}