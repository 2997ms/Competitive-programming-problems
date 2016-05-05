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
int val[maxn];
struct no
{
	int len, wei;
}node[maxn];

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
	memset(val, 0, sizeof(val));

	int res = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j < i; j++)
		{
			if (node[j].wei>node[i].wei)
			{
				val[i] = max(val[i], val[j] + 1);
			}
		}
		res = max(res, val[i]);
	}
	printf("%d\n", res + 1);
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