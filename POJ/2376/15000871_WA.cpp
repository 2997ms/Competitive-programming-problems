#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
using namespace std;

int n, t;
struct sa
{
	int begin, end;
} dat[1000050];

int cmp(sa x,sa y)
{
	if (x.begin == y.begin)
		return x.end>y.end;
	else
		return x.begin<y.begin;
}

void input()
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &dat[i].begin, &dat[i].end);
	}
}

void solve()
{
	sort(dat, dat + n, cmp);
	
	int i, j, mpos;
	int res = 1, maxn = 0;
	if (dat[0].begin != 1)
	{
		puts("-1");
		return;
	}
	res = 1, maxn = dat[0].end;
	mpos = 0;
	i = 0;
	while (i < n)
	{
		if (maxn >= t)
			break;
		int flag = 0;
		for (j = i + 1; j < n; j++)
		{
			if (dat[j].begin <= dat[i].end)
			{
				flag = 1;
				maxn = max(maxn, dat[j].end);
				mpos = j;
			}
			else
			{
				break;
			}
		}
		if (flag == 0)
			break;
		i = mpos;
		res++;
		if (maxn >= t || j == n)
			break;
	}
	if (maxn < t)
	{
		puts("-1");
	}
	else
	{
		printf("%d\n", res);
	}
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	while (scanf("%d%d", &n, &t) != EOF)
	{
		input();
		solve();
	}
	//system("pause");
	return 0;
}