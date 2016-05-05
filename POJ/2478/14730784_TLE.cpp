#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

long long a[1000005];

int euler(int n)
{
	int res = n, a = n;
	for (int i = 2; i*i <= a; i++)
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

	int i, n;
	a[1] = 0;
	for (i = 2; i <= 1000000; i++)
	{
		a[i] = a[i - 1] + euler(i);
	}
	while (cin >> n&&n)
	{
		cout << a[n] << endl;
	}
	//system("pause");
	return 0;
}
