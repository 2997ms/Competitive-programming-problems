#pragma warning(disable:4996)
#include <iostream>  
#include <algorithm>
#include <cstring>
#include <cstring>
#include <vector>  
#include <string>  
#include <cmath>
#include <queue>
#include <map>
using namespace std;

typedef unsigned long long ll;

const int maxn = 100005;

char x[maxn];
int sa[maxn], num[maxn];
int ran[maxn], height[maxn];
int wa[maxn], wb[maxn], wv[maxn], wss[maxn];
int dp[maxn][30], LOG[maxn], a[maxn], cnt;

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

void RMQ(int n)
{
	int i, j;
	memset(dp, 127, sizeof(dp));

	for (i = 1; i <= n; i++)
	{
		dp[i][0] = height[i];
	}
	for (j = 1; j <= LOG[n]; j++)
	{
		for (i = 1; i + (1 << j) - 1 <= n; i++)
		{
			dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int lcp(int le, int ri)
{
	int a = ran[le], b = ran[ri];
	if (a > b)
		swap(a, b);
	a++;
	int t = LOG[b - a + 1];
	return min(dp[a][t], dp[b - (1 << t) + 1][t]);
}

void init()
{
	int i;
	LOG[0] = -1;
	for (i = 1; i <= maxn; i++)
	{
		LOG[i] = (i&(i - 1)) ? LOG[i - 1] : LOG[i - 1] + 1;
	}
}

void solve()
{
	int i, j, len = strlen(x), nx = 0;
	for (i = 0; i < len; i++)
	{
		num[nx++] = x[i];
	}
	num[nx] = 0;
	da(num, nx + 1, 130);
	calHeight(num, nx);

	RMQ(nx);
	int li;
	int mmax = 0;
	for (li = 1; li < nx; li++)
	{
		for (i = 0; i + li < nx; i+=li)
		{
			int r = lcp(i, i + li);
			int step = r / li + 1;
			int k = i - (li - r%li);
			if (k >= 0 && r%li)
			{
				if (lcp(k, k + li) >= r)
				{
					step++;
				}
			}
			if (step > mmax)
			{
				mmax = step;
				cnt = 0;
				a[cnt++] = li;
			}
			else if (step == mmax)
			{
				a[cnt++] = li;
			}
		}
	}

	int flag = 1, st;
	for (i = 1; i <= nx&&flag; i++)
	{
		for (j = 0; j < cnt&&flag; j++)
		{
			li = a[j];
			if(lcp(sa[i],sa[i]+li)>=(mmax-1)*li)
			{
				len = li;
				st = sa[i];
				flag = 0;
			}
		}
	}

	for (int i = st, j = 0; j < len*mmax; i++, j++)
	{
		printf("%c", x[i]);
	}
	printf("\n");
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int t = 1;
	while (scanf("%s", x) != EOF)
	{
		if (x[0] == '#')
			break;
		printf("Case %d: ", t++);
		solve();
	}
	return 0;
}