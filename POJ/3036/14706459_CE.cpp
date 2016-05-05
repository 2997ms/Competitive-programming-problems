#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int n, result;

void dfs(int step,double x,double y)
{
	if (step == n)
	{
		if (x == 20 && y == 20 )
		{
			result++;
		}
		return;
	}
	if (x > 27 || x < 13 || y > 20 + 7 * ((sqrt(3)) / 2) || y < 20 - 7 * ((sqrt(3)) / 2))
	{
		return;
	}
	dfs(step + 1, x + 1, y );
	dfs(step + 1, x - 1, y );
	dfs(step + 1, x + 0.5, y + (sqrt(3)) / 2);
	dfs(step + 1, x + 0.5, y - (sqrt(3)) / 2);
	dfs(step + 1, x - 0.5, y + (sqrt(3)) / 2);
	dfs(step + 1, x - 0.5, y - (sqrt(3)) / 2);
}

int a[15];

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int i, test;
	cin >> test;
	a[1] = 0;
	a[2] = 6;
	a[3] = 12;
	a[4] = 90;
	a[5] = 360;
	a[6] = 2040;
	a[7] = 10080;
	a[8] = 54810;
	a[9] = 290640;
	a[10] = 1588356;
	a[11] = 8676360;
	a[12] = 47977776;
	a[13] = 266378112;
	a[14] = 1488801600;
	for (i = 1; i <= test; i++)
	{
		cin >> n;
	
		cout << a[n] << endl;
	}
	return 0;
}
