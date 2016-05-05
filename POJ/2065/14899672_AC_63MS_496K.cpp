#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
using namespace std;

int p;
char res[75];
int x[305];//解集
int val[305][305];//增广矩阵
bool free_x[305];//标记是否是不确定的变元

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
					val[i][j] = ((val[i][j] * ta - val[k][j] * tb) % p + p) % p;
				}
			}
		}
	}
	for (i = var - 1; i >= 0; i--)
	{
		temp = val[i][var];
		for (j = i + 1; j < var; j++)
		{
			if (val[i][j] != 0)
			{
				temp = temp - val[i][j] * x[j];
				temp = (temp % p + p) % p;
			}
		}
		while ((temp % val[i][i]))temp += p;
		x[i] = ((temp / val[i][i]) % p + p) % p;
	}
	return 0;
}

int getresult(int A, int n, int k)
{
	int b = 1;
	while (n > 0)
	{
		if (n & 1)
		{
			b = (b*A) % k;
		}
		n = n >> 1;
		A = (A*A) % k;
	}
	return b;
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int test, i, j, len;
	scanf("%d", &test);

	while (test--)
	{
		memset(val, 0, sizeof(val));
		
		scanf("%d%s", &p, res);

		len = strlen(res);
		for (i = 0; i < len; i++)
		{
			if (res[i] == '*')
				val[i][len] = 0;
			else
				val[i][len] = res[i] - 'a' + 1;
			
			for (j = 0; j < len; j++)
				val[i][j] = getresult(i + 1, j, p);
		}
		Gauss(len, len);
		for (i = 0; i < len; i++)
		{
			if (i == 0)
				printf("%d", x[i]);
			else
				printf(" %d", x[i]);
		}
		printf("\n");
	}

	//system("pause");
	return 0;
}