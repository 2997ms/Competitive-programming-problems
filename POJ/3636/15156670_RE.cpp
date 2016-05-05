#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <ctime>;
#include <set>
#include <map>
using namespace std;

#define INF 0x3fffffff
typedef long long ll;

const ll mod = 1e9 + 7;
const int maxn = 5005;

int n;
struct no
{
	int len, wei;
}node[maxn], a[maxn];

bool cmp(no n1, no n2)
{
	if (n1.len == n2.len)
		return n1.wei < n2.wei;
	else
		return n1.len < n2.len;
}

void solve()
{
	int i, j;
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &node[i].len, &node[i].wei);
	}
	sort(node + 1, node + n + 1, cmp);

	int res = 0;
	for (i = 1; i <= n; i++)
	{
		int f = 0;
		for (j = 1; j <= res; j++)
		{
			if (node[i].len>a[j].len&&node[i].wei > a[j].wei)
			{
				a[j].len = node[i].len;
				a[j].wei = node[i].wei;
				f = 1;
				break;
			}
		}
		if (!f)
		{
			res++;
			a[res].len = node[i].len;
			a[res].wei = node[i].wei;
		}
	}
	printf("%d\n", res);
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
	return 0;
}