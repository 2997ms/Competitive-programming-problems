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

const int maxn = 50;
const double PI = acos(-1.0);
const ll mod = 23333333;

int n;
int pos[maxn];

bool check()
{
	int i, j, k;
	repp(i, 1, n)
		if (pos[i] != i)
			return false;
	return true;
}

void reverse(int i, int j)
{
	int le = i, ri = j;
	while (le <= ri)
	{
		swap(pos[le], pos[ri]);
		le++, ri--;
	}
}
int find(int x)
{
	int i, j, k;
	repp(i, 1, n)
		if (pos[i] == x)
			return i;
}
void solve()
{
	int i, j, k, num;
	vector<int>res;
	num = 0;
	repp(i, 1, n)
		sa(pos[i]);
	int en = n;
	while (en > 1)
	{
		if (check())
			break;
		int t = find(en);
		if (t == en)
		{
			en--;
			continue;
		}
		if (t != 1)
		{
			reverse(1, t);
			res.push_back(t);
			num++;
			if (check())
				break;
		}
		reverse(1, en);
		res.push_back(en);
		num++;
		if (check())
			break;
		en--;
	}
	if (num == 0)
	{
		printf("%d\n", num);
	}
	else
	{
		printf("%d ", num);
		for (i = 0; i < res.size(); i++)
		{
			printf("%d%c", res[i], i == res.size() - 1 ? '\n' : ' ');
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE  
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
	
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;
		solve();
	}

	return 0;
}