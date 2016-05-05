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
	int x, y;
}node[10005];

int n;
int conbag[10005];

no orign;//原点

int dis(no n1, no n2)
{
	return (n1.x - n2.x)*(n1.x - n2.x) + (n1.y - n2.y)*(n1.y - n2.y);
}

int xmult(int x1, int y1, int x2, int y2)
{
	return x1*y2 - x2*y1;
}

int Across(no n1, no n2, no n3, no n4)
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

	min_x = 1005;
	cin >> n;
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
	
	if (n < 3 || conbag[0] < 3)
	{
		cout << 0 << endl;
	}
	else
	{
		sum = 0;
		for (i = 1; i + 2 <= conbag[0]; i++)
		{
			sum += abs(Across(node[conbag[i]], node[conbag[i + 1]], node[conbag[i]],node[conbag[i + 2]]));
		}
		sum += abs(Across(node[conbag[conbag[0] - 1]], node[conbag[conbag[0]]], node[conbag[0] - 1], node[conbag[1]]));
		sum += abs(Across(node[conbag[conbag[0]]], node[conbag[1]], node[conbag[0]], node[2]));

		sum = sum / 4.0;
		cout << (int)(sum / 50) << endl;
	}
	return 0;
}
