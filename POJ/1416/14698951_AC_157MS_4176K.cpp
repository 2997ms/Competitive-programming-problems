#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int target, len, maxn, num_max;//数组的最大长度
int val_final[8], val[8];
int dis[1000000];
string shre;

void dfs(int x, int sum, int c)
{
	if (x > len - 1)
	{
		if (maxn < sum)
		{
			maxn = sum;
			num_max = c;
			for (int i = 0; i < c; i++)
			{
				val_final[i] = val[i];
			}
		}
		dis[sum]++;
		return;
	}
	else
	{
		int i, t = 0;
		for (i = x; i < len; i++)
		{
			t = t * 10 + shre[i] - '0';
			if (sum + t <= target)
			{
				val[c] = t;
				dfs(i + 1, sum + t, c + 1);
			}
			else
				break;
		}
	}
}

int main()
{

	int i, t;
	while (cin>>target>>shre)
	{
		if (target == 0 && shre == "0")
			break;
		memset(dis, 0, sizeof(dis));
		memset(val_final, 0, sizeof(val_final));
		memset(val, 0, sizeof(val));
		t = 0;
		len = shre.length();
		maxn = -1;

		for (i = 0; i < len; i++)
		{
			t += shre[i] - '0';
		}
		if (t > target)
		{
			cout << "error" << endl;
			continue;
		}
		
		dfs(0, 0, 0);

		if (dis[maxn] != 1)
		{
			cout << "rejected" << endl;
		}
		else
		{
			cout << maxn;
			int k;
			for (k = 0; k < num_max; k++)
			{
				cout << " " << val_final[k];
			}
			cout << endl;
		}
	}

	return 0;
}
