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
#include <ctime>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

#define INF 0x33ffffff

#define eps 1e-6
const ll mod = 1000000007;
const int maxn = 100005;
const double PI = acos(-1.0);

struct tr
{
	int key;
	int num;
	int sz;
	int son[2];
	void se(int _x, int _y, int _z)
	{
		key = _x;
		num = _y;
		sz = _z;
		son[0] = son[1] = 0;
	}
}t[maxn];

int oper;
int cnt, n;

void init()
{
	cnt = 0;
	n = 0;
	memset(t, 0, sizeof(t));
}

void rotate(int &x, int p)//1右旋 0左旋
{
	int y = t[x].son[!p];
	t[x].son[!p] = t[y].son[p];
	t[y].son[p] = x;
	x = y;
}

void ins(int &x, int key, int num)
{
	if (x == 0)
	{
		cnt++;
		t[x = cnt].se(key, num, 1);
	}
	else
	{
		int p = key < t[x].key;
		ins(t[x].son[!p], key, num);
		if (t[x].sz < t[t[x].son[!p]].sz)rotate(x, p);
	}
}

void del(int &x, int key)
{
	if (t[x].key == key)
	{
		if (t[x].son[0] && t[x].son[1])
		{
			int p = t[t[x].son[0]].sz>t[t[x].son[1]].sz;
			rotate(x, p);
			del(t[x].son[p], key);
		}
		else
		{
			if (!t[x].son[0])
				x = t[x].son[1];
			else
				x = t[x].son[0];
		}
	}
	else
	{
		int p = t[x].key > key;
		del(t[x].son[!p], key);
	}
}

int get(int x, int p)
{
	while (t[x].son[p])
	{
		x = t[x].son[p];
	}
	return x;
}

void solve()
{
	int x;
	int k, p;
	
	if (oper == 1)
	{
		scanf("%d%d", &k, &p);
		ins(n, p, k);
	}
	else if (oper == 2)
	{
		x = get(n, 1);
		if (n)
		{
			printf("%d\n", t[x].num);
			del(n, t[x].key);
		}
		else
		{
			printf("0\n");
		}
	}
	else
	{
		x = get(n, 0);
		if (x)
		{
			printf("%d\n", t[x].num);
			del(n, t[x].key);
		}
		else
		{
			printf("0\n");
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE  
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	int time_wangchong756 = clock();
#endif
	init();
	while (scanf("%d", &oper) != EOF)
	{
		if (oper == 0)
			break;
		solve();
	}
#ifndef ONLINE_JUDGE
	printf("time: %d\n", (int)(clock() - time_wangchong756));
#endif
	//system("pause");
	return 0;
}