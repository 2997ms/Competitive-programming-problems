#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

long long euler(long long n)
{
	long long res = n, a = n;
	for (long long i = 2; i*i < a; i++)
	{
		if (a%i == 0)
		{
			res = res / i*(i - 1);
			while (a%i == 0)a /= i;
		}
	}
	if (a > 1)res = res / a*(a - 1);
	return res;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	long long n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		cout << euler(n) << endl;
	}

	system("pause");
	return 0;
}
