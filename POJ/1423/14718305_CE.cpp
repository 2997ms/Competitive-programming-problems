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
	int test;
	long long n;
	
	cin >> test;
	while (test--)
	{
		cin >> n;
		double re = log10(sqrt(2 * acos(-1)*n)) + n*log10(n / exp(1.0));
		cout << (int)re + 1 << endl;
	}

	system("pause");
	return 0;
}
