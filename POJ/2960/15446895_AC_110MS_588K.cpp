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

const ll mod = 2520;
const int maxn = 1e5 + 5;
const double PI = acos(-1.0);

int snum;
int s[105], sg[maxn], vis[105];

void init()
{
	int i, j, k;
	sg[0] = 0;
	for (i = 1; i <= 10000; i++)
	{
		memset(vis, 0, sizeof(vis));
		for (j = 1; j <= snum&&s[j] <= i;j++)
		{
			vis[sg[i - s[j]]] = 1;
		}
		for (j = 0;; j++)
		{
			if (!vis[j])
			{
				sg[i] = j;
				break;
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE  
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif

	int i, j, k;
	while (scanf("%d", &snum) != EOF)
	{
		if (snum == 0)
			break;
		for (i = 1; i <= snum; i++)
		{
			scanf("%d", &s[i]);
		}
		memset(sg, 0, sizeof(sg));
		sort(s + 1, s + snum + 1);
		init();

		int res, q;
		sa(q);
		repp(i, 1, q)
		{
			int num;
			sa(num);
			res = 0;
			repp(j, 1, num)
			{
				sa(k);
				res = res^sg[k];
			}
			if (res == 0)
			{
				printf("L");
			}
			else
			{
				printf("W");
			}
		}
		printf("\n");
	}
	return 0;
}