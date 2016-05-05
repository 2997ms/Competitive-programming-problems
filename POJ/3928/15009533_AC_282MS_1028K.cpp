#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
using namespace std;

typedef long long ll;

int n, maxn;
int ans1[100005];
int ans2[100005];
int val[100005];

int lowbit(int x)
{
	return x&(-x);
}

void add1(int x, int y)
{
	while (x <= maxn)
	{
		ans1[x] += y;
		x = x + lowbit(x);
	}
}

void add2(int x, int y)
{
	while (x <= maxn)
	{
		ans2[x] += y;
		x = x + lowbit(x);
	}
}

int sum1(int x)
{
	int res = 0;
	while (x > 0)
	{
		res += ans1[x];
		x = x - lowbit(x);
	}
	return res;
}

int sum2(int x)
{
	int res = 0;
	while (x > 0)
	{
		res += ans2[x];
		x = x - lowbit(x);
	}
	return res;
}

void input()
{
	int i;
	scanf("%d", &n);

	memset(ans1, 0, sizeof(ans1));
	memset(ans2, 0, sizeof(ans2));

	maxn = -1;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);		
		maxn = max(maxn, val[i]);
	}
	for (i = 1; i <= n; i++)
	{
		add2(val[i], 1);
	}
}

void solve()
{
	ll res = 0;

	int i;
	for (i = 1; i <= n; i++)
	{
		if (val[i] == 1)
		{
			add1(val[i], 1);
			add2(val[i], -1);
			continue;
		}
		else
		{
			add1(val[i], 1);
			add2(val[i], -1);

			ll r1 = sum1(val[i] - 1);//前面比它小的
			ll r2 = sum2(maxn) - sum2(val[i]);//后面比它大的

			res += r1*r2;

			r1 = sum1(maxn) - sum1(val[i]);//前面比它大的
			r2 = sum2(val[i] - 1);//后面比它小的

			res += r1*r2;
		}
	}
	printf("%lld\n", res);
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while (t--)
	{
		input();
		solve();
	}
	//system("pause");
	return 0;
}