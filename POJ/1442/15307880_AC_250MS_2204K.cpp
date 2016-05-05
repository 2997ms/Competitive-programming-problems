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

const ll mod = 1000000007;
const int maxn = 3 * 30005;
const double PI = acos(-1.0);

struct treap
{
	int key;
	int num;
	int sz;
	int son[2];
	void set(int _key, int _num, int _sz)
	{
		key = _key;
		num = _num;
		sz = _sz;
	}
}t[maxn];

int root, cnt;

void init()
{
	root = 0;
	cnt = 0;
	memset(t, 0, sizeof(t));
}

void rotate(int &x, int p)
{
	int y = t[x].son[!p];
	t[x].sz = t[x].sz - t[y].sz + t[t[y].son[p]].sz;
	t[x].son[!p] = t[y].son[p];
	t[y].sz = t[t[y].son[!p]].sz + 1 + t[x].sz;
	t[y].son[p] = x;
	x = y;
}

void add(int &x, int key)
{
	if (x == 0)
	{
		cnt++;
		t[x = cnt].set(key, 0, 1);
	}
	else
	{
		t[x].sz++;
		int p = key < t[x].key;
		add(t[x].son[!p], key);
		
		if (t[t[t[x].son[!p]].son[0]].sz>t[t[x].son[p]].sz || t[t[t[x].son[!p]].son[1]].sz > t[t[x].son[p]].sz)
		{
			rotate(x, p);
		}
	}
}

int find(int &x,int num)
{
	if (num == t[t[x].son[0]].sz + 1)
	{
		return t[x].key;
	}
	else
	{
		if (num < t[t[x].son[0]].sz + 1)
		{
			return find(t[x].son[0], num);
		}
		else
		{
			return find(t[x].son[1], num - t[t[x].son[0]].sz - 1);
		}
	}
}
int n, m;
int u[maxn], v[maxn];

void solve()
{
	int i, j;
	scanf("%d%d", &n, &m);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &u[i]);
	}

	for (i = 1; i <= m; i++)
	{
		scanf("%d", &v[i]);
		for (j = v[i - 1] + 1; j <= v[i]; j++)
		{
			add(root, u[j]);
		}
		printf("%d\n", find(root, i));
	}
}

int main()
{
#ifndef ONLINE_JUDGE  
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif

	init();
	solve();
	//system("pause");
	return 0;
}
