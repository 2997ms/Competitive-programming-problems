#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int n, maxn;
string test;
int grid[30][30];

void dfs(int step,int color[], int cap)
{
	if (step == n )
	{
		maxn = min(maxn, cap);
		return;
	}
	int i, j;
	for (i = 1; i <= 4; i++)
	{
		for (j = 0; j < 26; j++)
		{
			if (grid[step][j] == 1 && color[j] == i)
				break;
		}
		if (j == 26)
		{
			color[step] = i;
			dfs(step + 1, color, max(cap, i));
			color[step] = 0;
		}
	}
}

int main()
{
	int i, j, k, len;
	int color[30];
	while (cin >> n)
	{
		if (n == 0)
			break;
		memset(grid, 0, sizeof(grid));
		memset(color, 0, sizeof(color));
		maxn = 10;

		for (i = 0; i < n; i++)
		{
			cin >> test;
			len = test.length();

			if (len == 2)
				continue;
			k = test[0] - 'A';
			for (j = 2; j < len; j++)
			{
				grid[k][test[j] - 'A'] = 1;
				grid[test[j] - 'A'][k] = 1;
			}
		}
		dfs(0,color,0);

		if (maxn == 1)
		{
			cout <<"1 channel needed." << endl;
		}
		else
		{
			cout << maxn <<" channels needed. "<< endl;
		}
	}
	return 0;
}
