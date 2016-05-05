#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int cluster_num;
char value;
char val[20][20];
int vis[20][20];
int num[20][20];
int col_val[20][20];
int row_val[20][20];

void dfs_delete(int x, int y)
{
	val[x][y] = 0;
	vis[x][y] = 1;

	if (val[x - 1][y] == value&&vis[x - 1][y] == 0)
	{
		dfs_delete(x - 1, y);
	}

	if (val[x + 1][y] == value&&vis[x + 1][y] == 0)
	{
		dfs_delete(x + 1, y);
	}

	if (val[x][y - 1] == value&&vis[x][y - 1] == 0)
	{
		dfs_delete(x, y - 1);
	}

	if (val[x][y + 1] == value&&vis[x][y + 1] == 0)
	{
		dfs_delete(x, y + 1);
	}
}

void dfs(int x, int y)
{
	cluster_num++;
	vis[x][y] = 1;

	if (val[x - 1][y] == value&&vis[x - 1][y] == 0)
	{
		dfs(x - 1, y);
	}

	if (val[x + 1][y] == value&&vis[x + 1][y] == 0)
	{
		dfs(x + 1, y);
	}

	if (val[x][y - 1] == value&&vis[x][y - 1] == 0)
	{
		dfs(x, y - 1);
	}

	if (val[x][y + 1] == value&&vis[x][y + 1] == 0)
	{
		dfs(x, y + 1);
	}
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	int test, itest, i, j, sum, inum, remove_num, row_num, col_num;
	cin >> test;

	for (itest = 1; itest <= test; itest++)
	{
		cout << "Game " << itest << ":" << endl << endl;

		for (i = 10; i >= 1; i--)
		{
			cin >> val[i] + 1;
		}

		sum = 0;
		remove_num = 0;
		inum = 1;
		row_num = 10;
		col_num = 15;
		while (true)
		{
			memset(vis, 0, sizeof(vis));
			memset(num, 0, sizeof(num));

			for (i = 1; i <= 15; i++)
			{
				for (j = 1; j <= 10; j++)
				{
					if (val[j][i] == 0)continue;
					if (j == 1 && i == 6)
					{
						j++;
						j--;
					}
					if (vis[j][i] == 0)//第j行第i列
					{
						cluster_num = 0;
						value = val[j][i];

						dfs(j, i);

						num[j][i] = cluster_num;
					}
				}
			}

			int maxn;
			int x, y;

			maxn = 1;
			for (i = 1; i <= 15; i++)
			{
				for (j = 1; j <= 10; j++)
				{
					if (num[j][i] > maxn)
					{
						maxn = num[j][i];
						x = j;
						y = i;
					}
				}
			}

			if (maxn == 1)
				break;
			else
			{
				cout << "Move " << inum << " at (" << x << "," << y << "): removed " << maxn << " balls of color " << val[x][y] << ", got " << (maxn - 2)*(maxn - 2) << " points. " << endl;

				sum += (maxn - 2)*(maxn - 2);
				remove_num += maxn;

				memset(vis, 0, sizeof(vis));
				value = val[x][y];
				dfs_delete(x, y);
			}
		
			memset(col_val, 0, sizeof(col_val));
			for (j = 1; j <= 15; j++)//移动横球部分
			{
				int c_n = 0;
				for (i = 1; i <= 10; i++)
				{
					if (val[i][j] == 0)
						continue;
					else
					{
						col_val[c_n++][j] = val[i][j];
					}
				}

				c_n = 0;
				for (i = 1; i <= 10; i++)
				{
					val[i][j] = col_val[c_n++][j];
				}
			}

			for (j = 1; j <= col_num; j++)
			{
				for (i = 10; i >= 1; i--)
				{
					if (val[i][j] == 0)
						continue;
					else
						break;
				}
				if (i == 0)
				{
					int k, p;
					for (k = j + 1; k <= col_num; k++)
					{
						for (p = 10; p >= 1; p--)
						{
							val[p][k - 1] = val[p][k];
						}
					}
					for (i = 10; i >= 1; i--)
					{
						val[i][col_num] = 0;
					}
					j--;
					col_num--;
				}
			}
			
			inum++;
		}

		if (remove_num == 150)
		{
			sum += 1000;
		}
		cout << "Final score: " << sum << ", with " << 150 - remove_num << " balls remaining." << endl << endl;
	}

	//system("pause");
	return 0;
}
