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

#define INF 0x3fffffff
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 200005;

int K;
char A[maxn], B[maxn];
int sa[maxn], num[maxn];
int ran[maxn], height[maxn];
int wa[maxn], wb[maxn], wv[maxn], wss[maxn];

struct no
{
	ll len;
	ll num;

	no() {};
	no(ll x, ll y) { len = x; num = y; }
}sta[maxn];

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

ll cal(char * s)
{
	int i;
	int len = strlen(s);

	for (i = 0; i < len; i++)
	{
		num[i] = s[i];
	}
	num[i] = 0;
	da(num, len + 1, 130);
	calHeight(num, len);

	ll ans, t, x, top;
	no p;

	ans = 0;
	top = -1;
	t = 0;
	for (i = 1; i <= len; i++)
	{
		if (height[i] < K)
		{
			t = 0;
			top = -1;
			continue;
		}
		x = 1;
		t += height[i] - K + 1;

		while (top >= 0 && height[i] <= sta[top].len)
		{
			p = sta[top--];
			t -= p.num*(p.len - K + 1);
			t += p.num*(height[i] - K + 1);
			x += p.num;
		}
		sta[++top] = no(height[i], x);
		ans += t;
	}
	return ans;
}

void solve()
{
	ll resA, resB, res_sum;

	scanf("%s", A);
	scanf("%s", B);

	resA = cal(A);
	resB = cal(B);

	char *s = strcat(strcat(A, "&"), B);
	res_sum = cal(s);

	printf("%lld\n", res_sum - resA - resB);
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	while (scanf("%d", &K) != EOF)
	{
		if (K == 0)
			break;
		solve();
	}
	return 0;
}