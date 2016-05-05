#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

struct no {
	int x;
	int y;
}node[1005];

int num;

bool cmp(const no& node1, const no& node2)
{
	if (node1.x == node2.x)
	{
		return node1.y < node2.y;
	}
	else
	{
		return node1.x < node2.x;
	}
}

bool binsearch(int x, int y)
{
	int left = -1, right = num, mid;

	while (right - left > 1)
	{
		mid = (left + right) / 2;
		if (node[mid].x == x && node[mid].y == y)
			return true;
		else
		{
			if ((node[mid].x == x && node[mid].y < y) || (x > node[mid].x))
			{
				left = mid;
			}
			else
			{
				right = mid;
			}
		}
	}
	return false;
}

int main()
{
	int i, j, pos_x1, pos_y1, pos_x2, pos_y2, ans;
	while (cin >> num)
	{
		if (num == 0)
			break;
		if (num <= 3)
		{
			cout << 0 << endl;
			continue;
		}
		ans = 0;

		for (i = 0; i < num; i++)
		{
			scanf("%d%d", &node[i].x, &node[i].y);
		}
		sort(node, node + num, cmp);

		for (i = 0; i < num; i++)
		{
			for (j = i + 1; j < num; j++)
			{
				pos_x1 = node[i].x + (node[i].y - node[j].y);
				pos_y1 = node[i].y - (node[i].x - node[j].x);

				pos_x2 = node[j].x + (node[i].y - node[j].y);
				pos_y2 = node[j].y - (node[i].x - node[j].x);

				if ((binsearch(pos_x1, pos_y1)) && (binsearch(pos_x2, pos_y2)))
					ans++;

				pos_x1 = node[i].x - (node[i].y - node[j].y);
				pos_y1 = node[i].y + (node[i].x - node[j].x);


				pos_x2 = node[j].x - (node[i].y - node[j].y);
				pos_y2 = node[j].y + (node[i].x - node[j].x);

				if ((binsearch(pos_x1, pos_y1)) && (binsearch(pos_x2, pos_y2)))
					ans++;
			}
		}
		cout << ans/4 << endl;
	}
	return 0;
}
