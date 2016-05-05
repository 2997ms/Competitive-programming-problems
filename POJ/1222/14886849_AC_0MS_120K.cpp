#pragma warning(disable:4996) 
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define maxn 35

int x[maxn];
int f[maxn][maxn];
int val[maxn][maxn];
int dir[5][2] = 
{
	{0,0},
	{0,1},
	{1,0},
	{-1,0},
	{0,-1}
};

void input()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			scanf("%d", &val[i * 6 + j][30]);
		}
	}
}

void work()
{
	int k;
	int row, col;

	for (row = 0, col = 0; row < 30 && col < 30; row++, col++)
	{
		for (k = row; k < 30; k++)
		{
			if (val[k][col] != 0)
			{
				break;
			}
		}
		if (k == 30)
		{
			row--;
			continue;
		}
		if (k != row)
		{
			for (int i = col; i <= 30; i++)
			{
				swap(val[row][i], val[k][i]);
			}
		}

		for (int i = row + 1; i < 30; i++)
		{
			if (val[i][col])
			{
				for (int j = col; j <= 30; j++)
				{
					val[i][j] ^= val[row][j];
				}
			}
		}

	}

	for (int i = row; i >= 0; i--)
	{
		x[i] = val[i][30];
		for (int j = 29; j > i; j--)
		{
			x[i] ^= (val[i][j] && x[j]);
		}
	}
}

void print()
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d", x[i * 6]);
		for (int j = 1; j < 6; j++)
		{
			printf(" %d", x[i * 6 + j]);
		}
		putchar('\n');
	}
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				int a = i + dir[k][0];
				int b = j + dir[k][1];

				if (a >= 0 && b >= 0 && a < 5 && b < 6)
				{
					f[i * 6 + j][a * 6 + b] = 1;
				}
			}
		}
	}

	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		printf("PUZZLE #%d\n", i + 1);
		memcpy(val, f, sizeof(val));
		input();
		work();
		print();
	}
	//system("pause");
	return 0;
}