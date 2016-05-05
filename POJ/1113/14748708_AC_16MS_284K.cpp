#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

struct no
{
	double x, y;
}node[10005];

const double pi = 3.141592654;
int n;
int L;
int conbag[10005];

no orign;//原点

double dis(no n1, no n2)
{
	return (n1.x - n2.x)*(n1.x - n2.x) + (n1.y - n2.y)*(n1.y - n2.y);
}

double dis2(no n1, no n2)
{
	return sqrt((n1.x - n2.x)*(n1.x - n2.x) + (n1.y - n2.y)*(n1.y - n2.y));
}

double xmult(double x1, double y1, double x2, double y2)
{
	return x1*y2 - x2*y1;
}

double Across(no n1, no n2, no n3, no n4)
{
	return xmult(n2.x - n1.x, n2.y - n1.y, n4.x - n3.x, n4.y - n3.y);
}

int cmp(const void* n1, const void* n2)
{
	int temp = Across(orign, *(no *)n1, orign, *(no *)n2);

	if (temp > 0)
	{
		return -1;
	}
	else if (temp == 0)
	{
		return (dis(orign, *(no *)n1) - dis(orign, *(no *)n2));
	}
	else
	{
		return 1;
	}
}

int main()
{

	int i, j, k, min_x, pos_x;
	double sum;
	while (cin>>n>>L)
	{
		min_x = 100005;
		for (i = 1; i <= n; i++)
		{
			cin >> node[i].x >> node[i].y;
			if (node[i].x < min_x)
			{
				min_x = node[i].x;
				pos_x = i;
			}
			else if (min_x == node[i].x&&node[i].y < node[pos_x].y)
			{
				pos_x = i;
			}
		}
		orign = node[pos_x];
		qsort(node + 1, n, sizeof(no), cmp);

		int pc = 1;
		conbag[1] = 1;
		conbag[++pc] = 2;
		conbag[0] = 2;

		i = 3;
		while (i <= n)
		{
			if (Across(node[conbag[pc - 1]], node[conbag[pc]], node[conbag[pc]], node[i]) >= 0)
			{
				conbag[++pc] = i++;
				conbag[0]++;
			}
			else
			{
				pc--;
				conbag[0]--;
			}
		}
		sum = dis2(node[1], node[conbag[conbag[0]]]);
		for (i = 1; i + 1 <= conbag[0]; ++i)
		{
			sum += dis2(node[conbag[i]],node[conbag[i+1]]);
		}
		sum += pi * 2.0 * L;
		cout << (int)(sum + 0.5) << endl;
	}
	return 0;
}