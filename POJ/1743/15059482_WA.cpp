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
typedef long long ll;

#define INF 0x3fffffff
const int mod = 1e9 + 7;
const int maxn = 20005;

int nx;
int sa[maxn], num[maxn], patern[maxn];
int ran[maxn], height[maxn];
int wa[maxn], wb[maxn], wv[maxn], wss[maxn];

int cmp(int *r, int a, int b, int l)
{
	return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int *r, int n, int m)            //  倍增算法0(nlgn)。
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
		for (i = 0; i < n; i++)//sa[x]=y 表示排第x的是y位置
		{
			if (sa[i] >= j)//假设sa[i]=x,便表示排第i位的是第x位置，
						   //要满足x>=j,第二关键字赋值才有意义
						   //如果满足了这个关系，即在y上累加，做记录(前面比它小的都做完记录了)
			{
				y[p++] = sa[i] - j;
			}
		}
		for (i = 0; i < n; i++)
		{
			wv[i] = x[y[i]];//y[i]=x 表示第二关键字排第i位的是x
							//x数组保存的就是当前的rank值
							//x[i]=j 表示i后缀 排到了第j位
							//x[y[i]]的意思就是把第二关键字排第i位
							//的那个第一关键字搞出来，按照第一关键字排序
							//相等的第一关键字 按照第二关键字排序
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
			sa[--wss[wv[i]]] = y[i];//y[i]=x 表示第二关键字排第i位的是x
									//sa[x]=y表示总体记录，整个的字符串排在第x位的是y
		}
		for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
		{
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
		}
	}
}

void calHeight(int *r, int n)            //  求height数组
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
		j = sa[ran[i] - 1];//表示后缀i排的位置前一位的 位置
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
	int minn, maxn;

	minn = INF;
	maxn = -INF;
	for (i = 1; i <= nx - 1; i++)
	{
		if (k == 0)
		{
			if (height[i] >= x)
			{
				minn = min(min(minn, sa[i]), sa[i - 1]);
				maxn = max(max(maxn, sa[i]), sa[i - 1]);

				k = 1;
				if (maxn - minn >= x)
					return true;
			}
		}
		else
		{
			if (height[i] >= x)
			{
				minn = min(min(minn, sa[i]), sa[i - 1]);
				maxn = max(max(maxn, sa[i]), sa[i - 1]);

				k = 1;
				if (maxn - minn >= x)
					return true;
			}
			else
			{
				minn = INF;
				maxn = -INF;
				k = 0;
			}
		}
	}
	return false;
}

void input()
{
	int i;
	for (i = 0; i < nx; i++)
	{
		scanf("%d", num + i);
	}
}

void solve()
{
	nx--;

	int i;
	for (i = 0; i < nx; i++)
	{
		num[i] = num[i + 1] - num[i] + 90;
	}
	num[nx] = 0;

	da(num, nx + 1, 200);
	calHeight(num, nx);

	int le, ri, mid;
	le = 0;
	ri = nx + 1;

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
	printf("%d\n", le >= 4 ? le + 1: 0);
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	while (scanf("%d", &nx) != EOF)
	{
		if (nx == 0)
			break;
		input();
		solve();
	}

	return 0;
}