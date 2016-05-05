#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

long long n, k;

int main()
{
	int result;
	while (cin>>n>>k)
	{
		result = 0;
		while (n != 0)
		{
			result += n;
			n = n / k;
		}
		cout << result << endl;
	}

	return 0;
}