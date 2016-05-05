#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int a[3][200005];

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	int i, j, x;

	while (cin >> x)
	{
		memset(a[0], 0, sizeof(a[0]));
		memset(a[1], 0, sizeof(a[1]));
		a[0][100000] = 1;
		for (i = 1;; i++)
		{
			memset(a[i&1], 0, sizeof(a[i&1]));
			for (j = 0; j <= 200000; j++)
			{
				if (a[(i - 1) & 1][j] == 1)
				{
					a[i & 1][j + i] = 1;
					a[i & 1][j - i] = 1;
				}
			}
			if (a[i & 1][100000 + x] == 1 || a[i & 1][100000 - x] == 1)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
