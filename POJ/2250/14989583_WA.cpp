#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int len1, len2;
char a[35][105], b[35][105];
int mapp[35][35];
int dp[35][35];

void input()
{
	for (len1 = 1;; len1++)
	{
		scanf("%s", a[len1]);
		if (strcmp(a[len1], "#") == 0)
		{
			break;
		}
	}
	for (len2 = 0;; len2++)
	{
		scanf("%s", b[len2]);
		if (strcmp(b[len2], "#") == 0)
		{
			break;
		}
	}
}

void solve()
{
	memset(mapp, 0, sizeof(mapp));

	int i, j, k;
	for (i = 0; i < len1; i++)
	{
		for (j = 0; j < len2; j++)
		{
			if (strcmp(a[i], b[j]) == 0)
			{
				if (i == 0 || j == 0)
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					mapp[i][j] = 1;
				}
			}
			else
			{
				if (dp[i - 1][j]>dp[i][j - 1])
				{
					dp[i][j] = dp[i - 1][j];
					mapp[i][j] = 2;
				}
				else
				{
					dp[i][j] = dp[i][j-1];
					mapp[i][j] = 3;
				}
			}
		}
	}
}

void out(int x, int y)
{
	if (mapp[x][y] == 0)
	{
		cout << a[x] << " ";
		return;
	}
	if (mapp[x][y] == 1)
	{
		out(x - 1, y - 1);
		cout << a[x] << " ";
	}
	else if(mapp[x][y] == 2)
	{
		out(x - 1, y);
	}
	else if (mapp[x][y] == 3)
	{
		out(x, y - 1);
	}
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	
	while (scanf("%s", a[0]) != EOF)
	{
		input();
		solve();
		out(len1 - 1, len2 - 1);
		cout << endl;
	}
	return 0;
}