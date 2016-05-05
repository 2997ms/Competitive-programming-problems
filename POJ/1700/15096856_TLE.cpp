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
const int maxn = 5005;

int n;
int val[maxn];

void input()
{
	int i;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", val + i);
	}
}

int dfs(int x)
{
	if (x == 1 || x == 2)
	{
		return val[x];
	}
	else if (x == 3)
	{
		return val[1] + val[2] + val[3];
	}
	else if (x == 4)
	{
		return min(2 * val[1] + val[2] + val[3] + val[4], val[1] + 3 * val[2] + val[4]);
	}
	else
	{
		return min(val[x] + dfs(x - 1), val[x] + 2 * val[2] + dfs(x - 2));
	}
}

void solve()
{
	sort(val + 1, val + n + 1);
	printf("%d\n", dfs(n));
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

	return 0;
}