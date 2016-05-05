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

int n, m;
int x[305];//解集
int val[305][305];//增广矩阵
bool free_x[305];//标记是否是不确定的变元
char day[7][10] = { "MON","TUE", "WED","THU", "FRI","SAT","SUN" };

inline int gcd(int a, int b)
{
	int t;
	while (b != 0)
	{
		t = b;
		b = a%b;
		a = t;
	}
	return a;
}

inline int lcm(int a, int b)
{
	return a / gcd(a, b)*b;//先除后乘防溢出
}

int Gauss(int equ, int var)
{
	int i, j, k;
	int max_r;//当前这列绝对值最大的行
	int col;//当前处理的列
	int ta, tb;
	int LCM;
	int temp;
	int free_x_num;
	int free_index;

	for (int i = 0; i <= var; i++)
	{
		x[i] = 0;
		free_x[i] = true;
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
			if (abs(val[i][col])>abs(val[max_r][col]))
				max_r = i;
		}
		if (max_r != k)
		{//与第k行交换
			for (j = k; j < var + 1; j++)
				swap(val[k][j], val[max_r][j]);
		}
		if (val[k][col] == 0)
		{
			k--;
			continue;
		}
		for (i = k + 1; i < equ; i++)
		{//枚举要删去的行
			if (val[i][col] != 0)
			{
				LCM = lcm(abs(val[i][col]), abs(val[k][col]));
				ta = LCM / abs(val[i][col]);
				tb = LCM / abs(val[k][col]);
				if (val[i][col] * val[k][col] < 0)
					tb = -tb;
				for (j = col; j < var + 1; j++)
				{
					val[i][j] = ((val[i][j] * ta - val[k][j] * tb) % 7 + 7) % 7;
				}
			}
		}
	}

	//无解的情况
	for (i = k; i < equ; i++)
	{
		if (val[i][col] != 0)
			return -1;
	}

	if (k < var)
	{
		/*for (i = k - 1; i >= 0; i--)
		{
		free_x_num = 0;
		for (j = 0; j < var; j++)
		{
		if (val[i][j] != 0 && free_x[j])
		{
		free_x_num++;
		free_index = j;
		}
		}
		if (free_x_num > 1)
		continue;
		temp = val[i][var];
		for (j = 0; j < var; j++)
		{
		if (val[i][j] != 0 && j != free_index)
		temp -= val[i][j] * x[j] % 7;
		temp = (temp % 7 + 7) % 7;
		}
		while ((temp % val[i][free_index]))temp += 7;
		x[free_index] = (temp / val[i][free_index]) % 7;
		free_x[free_index] = 0;
		}*/
		return var - k;
	}
	for (i = var - 1; i >= 0; i--)
	{
		temp = val[i][var];
		for (j = i + 1; j < var; j++)
		{
			if (val[i][j] != 0)
			{
				temp = temp - val[i][j] * x[j];
				temp = (temp % 7 + 7) % 7;
			}
		}
		for (x[i] = 0; x[i] < 7; x[i]++)
		{
			if ((x[i] * val[i][i] + 7) % 7 == temp)
			{
				break;
			}
		}
	}
	return 0;
}

int tran(char *s)
{
	if (strcmp(s, "MON") == 0)
		return 1;
	else if (strcmp(s, "TUE") == 0)//"MON","TUE", "WED","THU", "FRI","SAT","SUN"
		return 2;
	else if (strcmp(s, "WED") == 0)
		return 3;
	else if (strcmp(s, "THU") == 0)
		return 4;
	else if (strcmp(s, "FRI") == 0)
		return 5;
	else if (strcmp(s, "SAT") == 0)
		return 6;
	else if (strcmp(s, "SUN") == 0)
		return 7;
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int i, j, num, temp_num, ans;
	char temp1[20], temp2[20];
	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0)
			break;
		memset(val, 0, sizeof(val));
		for (i = 0; i < m; i++)
		{
			scanf("%d%s%s", &num, temp1, temp2);

			val[i][n] = ((tran(temp2) - tran(temp1) + 1) % 7 + 7) % 7;
			for (j = 0; j < num; j++)
			{
				scanf("%d", &temp_num);
				val[i][temp_num - 1]++;
				val[i][temp_num - 1] = val[i][temp_num - 1] % 7;
			}
		}
		ans = Gauss(m, n);
		if (ans == 0)
		{
			for (int h = 0; h < n; h++)
			{
				if (x[h] < 3)x[h] = x[h] + 7;
				if (h == 0)
					printf("%d", x[h]);
				else
				{
					printf(" %d", x[h]);
				}
			}
			printf("\n");
		}
		else if (ans == -1)
		{
			printf("Inconsistent data.\n");
		}
		else
		{
			printf("Multiple solutions.\n");
		}
	}
	//system("pause");
	return 0;
}