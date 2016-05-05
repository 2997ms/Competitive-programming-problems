#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
#pragma warning(disable:4996)
using namespace std;

struct node
{
	double x, y;
}point[35][35];

double xmult(node a, node b, node c)
{
	return (a.x - c.x)*(b.y - c.y) - (b.x - c.x)*(a.y - c.y);
}
void init(int n)
{
	point[0][0].x = 0.0;
	point[0][0].y = 0.0;

	point[0][n + 1].x = 1.0;
	point[0][n + 1].y = 0.0;

	point[n + 1][0].x = 0.0;
	point[n + 1][0].y = 1.0;

	point[n + 1][n + 1].x = 1.0;
	point[n + 1][n + 1].y = 1.0;
}

node intersection(node a,node b,node c,node d)//ab与cd直线的交点
{
	node temp = a;
	double t = ((a.x - c.x)*(c.y - d.y) - (a.y - c.y)*(c.x - d.x)) / ((a.x - b.x)*(c.y - d.y) - (a.y - b.y)*(c.x - d.x));

	temp.x += (b.x - a.x)*t;
	temp.y += (b.y - a.y)*t;

	return temp;
}

int main()
{

	int n, i, j;
	while (cin >> n)
	{
		if (!n)
			break;
		double maxn = 0.0, res;
		init(n);

		for (i = 1; i <= n; i++)
		{
			cin >> point[0][i].x;
			point[0][i].y = 0.0;
		}

		for (i = 1; i <= n; i++)
		{
			cin >> point[n + 1][i].x;
			point[n + 1][i].y = 1.0;
		}

		for (i = 1; i <= n; i++)
		{
			cin >> point[i][0].y;
			point[i][0].x = 0.0;
		}
		
		for (i = 1; i <= n; i++)
		{
			cin >> point[i][n + 1].y;
			point[i][n + 1].x = 1.0;
		}

		for (j = 1; j <= n; j++)
		{
			for (i = 1; i <= n ; i++)
			{
				point[i][j] = intersection(point[0][j], point[n + 1][j], point[i][0], point[i][n + 1]);
			}
		}

		for (i = 1; i <= n + 1; i++)
		{
			for (j = 1; j <= n + 1; j++)
			{
				res = fabs(xmult(point[i - 1][j - 1], point[i][j], point[i][j - 1]));
				res += fabs(xmult(point[i - 1][j - 1], point[i][j], point[i - 1][j]));

				res /= 2;
				maxn = max(res, maxn);
			}	
		}
		cout << fixed << setprecision(6) << maxn << endl;
	}
	//system("pause");
	return 0;
}
