#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

struct matrix {
	long long m[105][105];
};

long long n, mo, k;
matrix b;

matrix mu(matrix no1, matrix no2)
{
	matrix t;
	memset(t.m, 0, sizeof(t.m));

	int i, j, k;

	for (i = 1; i <= n; i++)
	{
		for (k = 1; k <= n; k++)
		{
			if (no1.m[i][k])
			{
				for (j = 1; j <= n; j++)
				{
					t.m[i][j] += no1.m[i][k] * no2.m[k][j];
				}
			}
		}
	}
	return t;

}

matrix multi(matrix no, long long x)
{
	memset(b.m, 0, sizeof(b.m));
	int i;
	for (i = 1; i <= n; i++)
	{
		b.m[i][i] = 1;
	}
	while (x > 0)
	{
		if (x & 1)
			b = mu(no, b);
		x = x >> 1;
		no = mu(no, no);
	}
	return b;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	
	int i,temp;
	string test;
	matrix no;

	while (cin >> n >> mo >> k)
	{
		if (n == 0 && mo == 0 && k == 0)
			break;
		memset(no.m, 0, sizeof(no.m));
		
		for (i = 1; i <= n; i++)
			no.m[i][i] = 1;
		for (i = 1; i <= k; i++)
		{
			cin >> test >> temp;
			if (test == "g")
			{
				for (i = 1; i <= n; i++)
				{
					no.m[i][temp]++;
				}
			}
			else if (test == "s")
			{
				int temp2;
				long long b;
				cin >> temp2;

				for (i = 1; i <= n; i++)
				{
					b = no.m[i][temp];
					no.m[i][temp] = no.m[i][temp2];
					no.m[i][temp2] = b;
				}
			}
			else if (test == "e")
			{
				for (i = 1; i <= n; i++)
				{
					no.m[i][temp] = 0;
				}
			}
		}

		no = multi(no, mo);

		cout << no.m[1][1];

		for (i = 2; i <= n; i++)
		{
			cout << " " << no.m[1][i];
		}
		cout << endl;
	}
	//system("pause");
	return 0;
}
