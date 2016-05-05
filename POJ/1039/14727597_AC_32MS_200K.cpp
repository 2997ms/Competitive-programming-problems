#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
#pragma warning(disable:4996)
using namespace std;

struct point
{
	double x, y;
}up[22],down[22];
const double eps = 1e-3;

double Multi(point p1, point p2, point p0)
{
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}

//直线ab与线段cd是否相交
bool Across(point a, point b, point c, point d)
{
	double tmp = Multi(c, a, b)*Multi(d, a, b);
	if (tmp < 0 || fabs(tmp) < eps)
		return true;
	else
		return false;
}

double getIntersect(point a, point b, point c, point d)
{
	double A1 = b.y - a.y;
	double B1 = a.x - b.x;
	double C1 = (b.x - a.x)*a.y - (b.y - a.y)*a.x;
	double A2 = d.y - c.y;
	double B2 = c.x - d.x;
	double C2 = (d.x - c.x)*c.y - (d.y - c.y)*c.x;
	double x = (C2*B1 - C1*B2) / (A1*B2 - A2*B1);
	double y = (C1*A2 - C2*A1) / (A1*B2 - A2*B1);

	return x;
}

int main()
{
	int n, i, j, k;
	double res;
	bool flag;

	while (scanf("%d", &n) && n)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%lf%lf", &up[i].x, &up[i].y);
			down[i].x = up[i].x;
			down[i].y = up[i].y - 1;
		}
		res = up[0].x;
		flag = false;

		for (i = 0; i < n&&!flag; i++)
		{
			for (j = 0; j < n&&!flag; j++)
			{
				if (i == j)continue;
				for (k = 0; k < n; k++)
				{
					if (!Across(up[i], down[j], up[k], down[k]))
						break;
				}
				if (k == n)
				{
					flag = true;
				}
				else if (k > max(i, j))
				{
					res = max(res, getIntersect(up[i], down[j], up[k - 1], up[k]));
					res = max(res, getIntersect(up[i], down[j], down[k - 1], down[k]));
				}
			}
		}
		if (flag)
			cout << "Through all the pipe." << endl;
		else
			cout << fixed << setprecision(2) << res << endl;
	}
	//system("pause");
	return 0;
}
