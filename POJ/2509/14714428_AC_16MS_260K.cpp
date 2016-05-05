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
	long long result;
	while (cin>>n>>k)
	{
		result = n;
		while (n >= k )
		{
			result += n/k;
			n = n / k + n % k;
		}
		cout << result << endl;
	}
	return 0;
}