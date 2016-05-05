#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

string test;

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	else
		return gcd(b%a, a);
}

int main()
{

	int all_len, num_len, i;
	int all, num, k, res;
	int min_a, min_b, p, j;
	while (cin >> test)
	{
		if (test == "0")
			break;
		all_len = 0;
		all = 0;
		for (i = 2; test[i] != '.'; i++)
		{
			all = all * 10 + test[i] - '0';
			all_len++;
		}
		
		num = all;
		k = 1;
		min_a = 1000000000;
		min_b = 1000000000;

		for (i = 1; i <= all_len; i++)
		{
			num = num / 10;

			k = k * 10;
			p = (int)pow(10.0, all_len - i)*(k - 1);
			j = gcd(all - num, p);

			if (min_b > p / j)
			{
				min_a = (all - num) / j;
				min_b = p / j;
			}
		}
		cout << min_a <<  "/" << min_b << endl;
	}

	return 0;
}
