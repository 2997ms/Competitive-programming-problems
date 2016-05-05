#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	int test, i, j, k, result;
	cin >> test;
	while (test--)
	{
		cin >> j >> k;
		result = 0;
		for (i = 2; i*(i + 1) / 2 <= k; i++)
		{
			if ((k - (i*(i + 1) / 2)) % i == 0)
			{
				result++;
			}
		}
		cout << j<<" "<<result << endl;
	}
	return 0;
}
