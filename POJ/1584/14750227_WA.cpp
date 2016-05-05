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
}node[2005], peg, orign;

int n, conbag[2005];
double peg_r;

double dis(no n1, no n2)
{
	return (n1.x - n2.x)*(n1.x - n2.x) + (n1.y - n2.y)*(n1.y - n2.y);
}

double dis2(no n1, no n2)
{
	return sqrt((n1.x - n2.x)*(n1.x - n2.x) + (n1.y - n2.y)*(n1.y - n2.y));
}

double dis3(no n1, no n2)
{
	if (n1.x == n2.x)
	{
		return fabs(n1.x - peg.x);
	}
	else
	{
		double k = (n2.y - n1.y) / (n2.x - n1.x);
		double b = n2.y - k*n2.x;
		return fabs(k*peg.x - peg.y + b) / sqrt(k*(k + 1));
	}
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
	double temp = Across(orign, *(no *)n1, orign, *(no *)n2);

	if (temp > 0)
	{
		return -1;
	}
	else if (temp == 0)
	{
		double i = (dis(orign, *(no *)n1) - dis(orign, *(no *)n2));
		if (i > 0)
			return 1;
		else
			return -1;
	}
	else
	{
		return 1;
	}
}

bool convex()
{
	int pc = 1;
	conbag[1] = 1;
	conbag[++pc] = 2;
	conbag[0] = 2;

	int i = 3;
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
	if (conbag[0] == n)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{

	int i, pos_x;
	double min_x;

	while (cin >> n)
	{
		if (n < 3)
			break;
		cin >> peg_r >> peg.x >> peg.y;
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

		if (convex())
		{
			cout << "HOLE IS ILL-FORMED" << endl;
		}
		else
		{
			int sign = 0;
			for (i = 1; i <= n; i++)
			{
				if (Across(node[(i+1)%n], node[i % n], peg, node[(i + 1) % n]) <= 0)
				{
					sign = 1;
					break;
				}
			}
			if (sign == 1)
			{
				cout <<"PEG WILL NOT FIT" << endl;
			}
			else
			{
				double len;
				for (i = 1; i <= n; i++)
				{
					len = dis3(node[i%n], node[(i + 1) % n]);
					if (len < peg_r)
					{
						sign = 1;
						break;
					}
				}
				if (sign == 1)
				{
					cout << "PEG WILL NOT FIT" << endl;
				}
				else
				{
					cout << "PEG WILL FIT" << endl;
				}
			}
		}
	}

	return 0;
}
