#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

struct matrix {
	int m[35][35];
};

int n, mod;
long long ko;
matrix no;

matrix mu(matrix no1, matrix no2)
{
	matrix t;
	memset(t.m, 0, sizeof(t.m));

	int i, j, k;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			for (k = 1; k <= n; k++)
			{
				t.m[i][j] += no1.m[i][k] * no2.m[k][j];
				if (t.m[i][j] >= mod)
				{
					t.m[i][j] %= mod;
				}
			}
		}
	}
	return t;

}

matrix multi(matrix no, long long x)
{
	matrix b;
	memset(b.m, 0, sizeof(b.m));
	int i;
	for (i = 1; i <= n; i++)
	{
		b.m[i][i] = 1;
	}
	while (x)
	{
		if (x & 1) b = mu(b, no);
		x = x >> 1;
		no = mu(no, no);
	}
	return b;
}
matrix add(matrix no1, matrix no2)
{
	matrix t;

	int i, j;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			t.m[i][j] = no1.m[i][j] + no2.m[i][j];
			if (t.m[i][j] >= mod)
			{
				t.m[i][j] %= mod;
			}
		}
	}
	return t;
}

matrix sum2(long long i)
{
	if (i == 1)return no;
	if (i & 1)
		return add(multi(no, i), sum2(i - 1));
	else
	{
		long long k = i >> 1;
		matrix s = sum2(k);
		return add(s, mu(s, multi(no, k)));
	}

}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int i, j;
	cin >> n >> ko >> mod;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &no.m[i][j]);
			if (no.m[i][j] >= mod)
			{
				no.m[i][j] %= mod;
			}
		}
	}
	no = sum2(ko);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (j == 1)
				cout << no.m[i][j];
			else
				cout << " " << no.m[i][j];
		}
		cout << endl;
	}
	//system("pause");
	return 0;
}
