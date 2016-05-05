#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define eps 1e-6

int t;
double ave;
double v[1005];

void input()
{
	ave = 0;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		cin >> v[i];
		ave += v[i];
	}
	ave = ave / t;

	double n = 0;
	for (int i = 0; i < t; i++)
	{
		if (v[i] - ave > eps)
		{
			n++;
		}
	}
	printf("%.3lf%%\n", n / t * 100);
	//cout << "%" << endl;
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int N;
	scanf("%d", &N);

	while (N--)
	{
		input();
	}

	return 0;
}