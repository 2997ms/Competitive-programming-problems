#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int a1[35];
int a2[35];
int sum, n, k, m;

int main()
{
	int i;
	cin >> n >> m >> k;
	
	for (i = 0; i < k; i++)
	{
		cin >> a1[i];
	}
	for (i = 0; i < k; i++)
	{
		cin >> a2[i];
	}
	sum = 0;

	for (i = 0; i < k; i++)
	{
		sum += abs(a1[i] - a2[i]);
	}
	cout << sum/2 << endl;
	return 0;
}
