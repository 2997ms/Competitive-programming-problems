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

int x[15];
int num[15];
int val[15][25];
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
				ta =  abs(val[k][col]);
				tb =  abs(val[i][col]);
				if (val[i][col] * val[k][col] < 0)
					tb = -tb;

				for (j = col; j < var + 1; j++)
				{
					val[i][j] = (((val[i][j] * ta)%4 - (val[k][j] * tb)%4)% 4 + 4) % 4;
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
				temp = temp - (val[i][j] * x[j])%4;
				temp = (temp % 4 + 4) % 4;
			}
		}
		for (x[i] = 0; x[i] < 4; x[i]++)
		{
			if ((x[i] * val[i][i] + 4) % 4 == temp)
			{
				break;
			}
		}
	}
	return 0;
}
int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	
	int i, sum;
	int j1, j2, j3, j4, j5, j6, j7, j8, j9;

	for (i = 1; i <= 9; i++)
		scanf("%d", &num[i]);

	memset(val, 0, sizeof(val));
	for (i = 0; i < 9; i++)
	{
		val[i][9] = (4 - num[i + 1]) % 4;
		if (i == 0)
		{
			val[i][0] = 1;
			val[i][1] = 1;
			val[i][3] = 1;
		}
		else if (i == 1)
		{
			val[i][0] = 1;
			val[i][1] = 1;
			val[i][2] = 1;
			val[i][4] = 1;
		}
		else if (i == 2)
		{
			val[i][1] = 1;
			val[i][2] = 1;
			val[i][5] = 1;
		}
		else if (i == 3)
		{
			val[i][0] = 1;
			val[i][3] = 1;
			val[i][4] = 1;
			val[i][6] = 1;
		}
		else if (i == 4)
		{
			val[i][0] = 1;
			val[i][2] = 1;
			val[i][4] = 1;
			val[i][6] = 1;
			val[i][8] = 1;
		}
		else if (i == 5)
		{
			val[i][2] = 1;
			val[i][4] = 1;
			val[i][5] = 1;
			val[i][8] = 1;
		}
		else if (i == 6)
		{
			val[i][3] = 1;
			val[i][6] = 1;
			val[i][7] = 1;
		}
		else if (i == 7)
		{
			val[i][4] = 1;
			val[i][6] = 1;
			val[i][7] = 1;
			val[i][8] = 1;
		}
		else if (i == 8)
		{
			val[i][5] = 1;
			val[i][7] = 1;
			val[i][8] = 1;
		}
	}

	Gauss(9, 9);
	
	for (j1 = 1; j1 <= x[0]; j1++)printf("1 ");
	for (j2 = 1; j2 <= x[1]; j2++)printf("2 ");
	for (j3 = 1; j3 <= x[2]; j3++)printf("3 ");
	for (j4 = 1; j4 <= x[3]; j4++)printf("4 ");
	for (j5 = 1; j5 <= x[4]; j5++)printf("5 ");
	for (j6 = 1; j6 <= x[5]; j6++)printf("6 ");
	for (j7 = 1; j7 <= x[6]; j7++)printf("7 ");
	for (j8 = 1; j8 <= x[7]; j8++)printf("8 ");
	for (j9 = 1; j9 <= x[8]; j9++)printf("9 ");
	
	//system("pause");
	return 0;
}