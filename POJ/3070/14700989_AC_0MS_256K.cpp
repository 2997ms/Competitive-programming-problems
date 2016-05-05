#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

struct matr {
	int a[3][3];
};
matr no;
const int mod = 10000;

matr mu(matr no1, matr no2)
{
	matr t ;
	t.a[1][1] = 0;
	t.a[1][2] = 0;
	t.a[2][1] = 0;
	t.a[2][2] = 0;
	int i, j, k;

	for (i = 1; i <= 2; i++)
	{
		for (j = 1; j <= 2; j++)
		{
			for (k = 1; k <= 2; k++)
			{
				t.a[i][j] += no1.a[i][k] * no2.a[k][j];
				t.a[i][j] %= mod;
			}
		}
	}
	return t;

}

matr multi(matr no, long long x)
{
	matr b;
	b.a[1][1] = 1;
	b.a[1][2] = 0;
	b.a[2][1] = 0;
	b.a[2][2] = 1;

	while (x)
	{
		if (x & 1) b = mu(b, no);
		x = x >> 1;
		no = mu(no, no);
	}
	return b;
}

int main()
{
	long long x;
	while (cin >> x)
	{
		if (x == -1)
			break;
		if (x == 0)
		{
			cout << 0 << endl;
			continue;
		}
		no.a[1][1] = 1;
		no.a[1][2] = 1;
		no.a[2][1] = 1;
		no.a[2][2] = 0;
		no = multi(no, x);
		cout << no.a[1][2] % 10000 << endl;
	}

	return 0;
}
