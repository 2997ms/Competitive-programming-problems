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

const ll mod = 100000007;
const int maxn = 1e5 + 5;
const double PI = acos(-1.0);

string s;
void solve()
{
	int i, j, k;
	int len = s.length();
	int num = 0;
	for (i = 2; i <= len; i++)
	{
		num = (num + 1999) % i;
	}
	if (s[num] == '?')
	{
		puts("Yes");
	}
	else if(s[num]==' ')
	{
		puts("No");
	}
	else
	{
		puts("No comments");
	}
}
int main()
{
	char ch;
	s = "";
	while (scanf("%c", &ch) != EOF)
	{
		if(ch!='\n')
			s += ch;
	}
	solve();
	return 0;
}