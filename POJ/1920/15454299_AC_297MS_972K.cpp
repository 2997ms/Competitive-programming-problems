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

const int maxn = 1e5 + 5;
const ll mod = 1000000;
const double PI = acos(-1.0);

int n;
int num[5], pos[maxn], val[maxn];

void solve()
{
	int i, j, k;

	sa(num[1]), sa(num[2]), sa(num[3]);

	repp(i, 1, 3)
	{
		repp(j, 1, num[i])
		{
			sa(k);
			pos[k] = i;
		}
	}
	val[0] = 1, val[1] = 2;
	repp(i, 2, n)
	{
		val[i] = (val[i - 1] << 1) % mod;
	}
	int temp = pos[n - 1], last = pos[n];
	int res = 0;
	for (i = n - 1; i > 0; i--, temp = pos[i])
	{
		if (last != temp)
		{
			res = (res + val[i - 1]) % mod;
			last = 6 - last - pos[i];
		}
	}
	printf("%d\n%d\n", pos[n], res);
}

int main()
{
#ifndef ONLINE_JUDGE  
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
	
	while (scanf("%d", &n) != EOF)
	{
		solve();
	}
	return 0;
}