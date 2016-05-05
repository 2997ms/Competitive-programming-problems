#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <stdlib.h>
#include <string.h>  
#include <string>
#include <cstring>
using namespace std;

#define eps 1e-6

int n, p, len;
char s[350];
int free_x[500];
double x[500];
double val[500][500];

inline double zero(double x)
{
	if (fabs(x) > eps)return x;
	return 0;
}
int Gauss(int equ, int var)
{
	int i, j, k;
	int max_r;//当前这列绝对值最大的行
	int col;//当前处理的列
	double tb;
	double temp;

	for (int i = 0; i <= var; i++)
	{
		x[i] = 0;
		free_x[i] = 1;
	}
	//转换为阶梯阵
	col = 0;//当前处理的列
	for (k = 0; k < equ&&col < var; k++, col++)
	{
		//枚举当前处理的行
		//找到该col列元素绝对值最大的那行与第k行交换.(为了在除法时减少误差)
		max_r = k;
		for (i = k + 1; i < equ; i++)
		{
			if (fabs(val[i][col])>fabs(val[max_r][col]))
				max_r = i;
		}
		if (max_r != k)
		{//与第k行交换
			for (j = k; j < var + 1; j++)
				swap(val[k][j], val[max_r][j]);
		}
		if (fabs(val[k][col]) < eps)
		{
			k--;
			continue;
		}
		for (i = k + 1; i < equ; i++)
		{//枚举要删去的行
			if (fabs(val[i][col]) > eps)
			{
				tb = val[i][col] / val[k][col];
				for (j = col; j < var + 1; j++)
				{
					val[i][j] = (val[i][j] - val[k][j] * tb);
				}
			}
		}
	}

	//无解的情况
	for (i = k; i < equ; i++)
	{
		if (val[i][col] > eps)
			return -1;
	}

	if (k < equ)
	{
		//注释处为求多解的自由变量  
		// 首先，自由变元有n - k个，即不确定的变元至少有n - k个.  
		int num = 0, freeidx;
		for (i = k - 1; i >= 0; --i)
		{
			num = 0;// 用于判断该行中的不确定的变元的个数，如果超过1个，则无法求解，它们仍然为不确定的变元.  
			double tmp = val[i][n];
			// 第i行一定不会是(0, 0, ..., 0)的情况，因为这样的行是在第k行到第m行.  
			// 同样，第i行一定不会是(0, 0, ..., a), a != 0的情况，这样的无解的.  
			for (j = 0; j < n; ++j)
			{
				if (fabs(val[i][j])>eps && free_x[j])
				{
					num++;
					freeidx = j;
				}
			}
			if (num > 1) continue; // 无法求解出确定的变元.  
								   // 说明就只有一个不确定的变元free_index，那么可以求解出该变元，且该变元是确定的.  
			tmp = val[i][n];
			for (j = 0; j < n; ++j)
			{
				if (fabs(val[i][j])>eps && j != freeidx) tmp -= val[i][j] * x[j];
			}
			x[freeidx] = tmp / val[i][freeidx];
			free_x[freeidx] = 0;
		}
		return n - k;
	}

	for (i = var - 1; i >= 0; i--)
	{
		temp = val[i][var];
		for (j = i + 1; j < var; j++)
		{
			if (val[i][j])
			{
				temp = temp - val[i][j] * x[j];
			}
		}
		x[i] = temp / val[i][i];
	}
	return 0;
}

void dfs(double *a)
{
	int cnt = 0;
	while (s[p] != ')')
	{
		if (s[p] == ' ')
		{
			p++;
		}
		else if (s[p] == '(')
		{
			double b[50];
			p++;

			memset(b, 0, sizeof(b));
			dfs(b);
			cnt++;
			for (int k = 0; k <= n; k++)
			{
				a[k] += b[k];
			}
		}
		else if (s[p] >= '0'&&s[p] <= '9')
		{
			cnt++;
			int num = 0;
			while (s[p] >= '0'&&s[p] <= '9')
			{
				num = num * 10;
				num = num + s[p] - '0';
				p++;
			}
			a[n] += num;
		}
		else if (s[p] == '-')
		{
			cnt++;
			int num = 0;
			p++;
			while (s[p] >= '0'&&s[p] <= '9')
			{
				num = num * 10;
				num = num + s[p] - '0';
				p++;
			}
			a[n] -= num;
		}
		else if (s[p] >= 'a'&&s[p] <= 'z')
		{
			cnt++;
			a[s[p] - 'a']++;
			p++;
		}
	}

	if (cnt)
	{
		for (int k = 0; k <= 27; k++)
		{
			a[k] = a[k] / cnt;
		}
	}
	p++;
	return;
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int i, k, ans;
	int itest = 0;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;

		getchar();
		memset(val, 0, sizeof(val));

		printf("Game %d\n", ++itest);
		for (i = 0; i < n; i++)
		{
			gets_s(s);//VS2015用gets_s代替了get

			p = 0;
			while (s[p] != '(')
				p++;
			p++;
			dfs(val[i]);
			for (k = 0; k < n; k++)
				val[i][k] = -val[i][k];
			val[i][i]++;
		}
		ans = Gauss(n, n);
		for (k = 0; k < n; k++)
		{
			if (ans == -1)
			{
				printf("Expected score of %c undefined\n", k + 'a');
			}
			else if (ans == 0)
			{
				printf("Expected score for %c = %.3lf\n", k + 'a',x[k]);
			}
			else
			{
				if (free_x[k])
					printf("Expected score of %c undefined\n", k + 'a');
				else
					printf("Expected score for %c = %.3lf\n", k + 'a', x[k]);
			}

		}
		printf("\n");
	}
	//system("pause");
	return 0;
}