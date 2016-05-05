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

//const ll mod = 100000007;
const int maxn = 1005;
const double PI = acos(-1.0);

int n, k;
int tre[maxn * 4];

struct no
{
	char nam[15];
	int num;
	int id;
}node[maxn];

const int antiprime[] =
{
	1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,
	1260,1680,2520,5040,7560,10080,15120,20160,25200,
	27720,45360,50400,55440,83160,110880,166320,221760,
	277200,332640,498960,554400,665280
};

const int factorNum[] =
{
	1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,
	64,72,80,84,90,96,100,108,120,128,144,160,168,180,
	192,200,216,224
};

void build(int root, int le, int ri)
{
	tre[root] = ri - le + 1;
	if (le == ri)
		return ;
	int mid = (ri + le) / 2;
	build(root << 1, le, mid);
	build(root << 1 | 1, mid + 1, ri);
}

int update(int root, int le, int ri, int k)
{
	tre[root]--;
	if (le == ri)
		return le;
	int mid = (le + ri) / 2;
	if (k <= tre[root << 1])
	{
		return update(root << 1, le, mid, k);
	}
	else
	{
		return update(root << 1, mid + 1, ri, k - tre[root << 1]);
	}
}

void solve()
{
	int i, j;
	int cnt, pos, &mod = tre[1];

	for (i = 1; i <= n; i++)
	{
		scanf("%s%d", node[i].nam, &node[i].num);
	}
	build(1, 1, n);

	cnt = 0;
	while (cnt < 35 && antiprime[cnt] <= n)
	{
		cnt++;
	}
	cnt--;
	pos = 0;
	
	node[pos].num = 0;
	for (i = 0; i < antiprime[cnt]; i++)
	{
		if (node[pos].num>0)
		{
			k = ((k + node[pos].num - 2) % mod + mod) % mod + 1;
		}
		else
		{
			k = ((k + node[pos].num - 1) % mod + mod) % mod + 1;
		}
		pos = update(1, 1, n, k);
	}
	printf("%s %d\n", node[pos].nam, factorNum[cnt]);
}

int main()
{
	while (scanf("%d%d", &n, &k) != EOF)
	{
		solve();
	}
	return 0;
}