#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
using namespace std;

int res[35];
int val[35][35];
int templat[35][35];

void Gauss()
{
	int row, col, i, j, k;
	
	for (row = 1, col = 1; col <= 30 && row <= 30; col++, row++)
	{
		k = row;
		while (val[k][col] == 0 && k <= 30)
			k++;
		
		if (k != row)
		{
			for (i = 1; i <= 31; i++)
			{
				swap(val[k][i], val[row][i]);
			}
		}
		for (i = row + 1; i <= 30; i++)
		{
			if (val[i][col])
			{
				for (j = col; j <= 31; j++)
				{
					val[i][j] = val[i][j] ^ val[row][j];
				}
			}
		}
	}

	for (i = 30; i >= 1; i--)
	{
		res[i] = val[i][31];
		for (j = 30; j > i; j--)
		{
			res[i] ^= (val[i][j] && res[j]);
		}
	}
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int t, test, i, j, k;
	memset(templat, 0, sizeof(templat));

	for (i = 0; i < 5; i++)
	{
		for (j = 1; j <= 6; j++)
		{
			templat[i * 6 + j][i * 6 + j] = 1;
			if (i - 1 >= 0)
			{
				templat[i * 6 + j][(i - 1) * 6 + j] = 1;
			}
			if (i + 1 < 5)
			{
				templat[i * 6 + j][(i + 1) * 6 + j] = 1;
			}
			if (j - 1 >= 1)
			{
				templat[i * 6 + j][i * 6 + j - 1] = 1;
			}
			if (j + 1 <= 6)
			{
				templat[i * 6 + j][i * 6 + j + 1] = 1;
			}
		}
	}

	scanf("%d", &t);
	for (test = 1; test <= t; test++)
	{
		printf("PUZZLE #%d\n", test);
		memcpy(val, templat, sizeof(templat));
		memset(res, 0, sizeof(res));

		for (i = 0; i < 5; i++)
		{
			for (j = 1; j <= 6; j++)
			{
				scanf("%d", &val[i * 6 + j][31]);
			}
		}
		Gauss();

		for (i = 1; i <= 30; i++)
		{
			if (i % 6 == 1)
			{
				printf("%d", res[i]);
			}
			else
			{
				printf(" %d", res[i]);
			}
			if (i % 6 == 0)
			{
				printf("\n");
			}
		}
	}
	
	//system("pause");
	return 0;
}