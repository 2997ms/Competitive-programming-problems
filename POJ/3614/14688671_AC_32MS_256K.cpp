#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#pragma warning(disable:4996)
using namespace std;

struct no1 {
	int min_v;
	int max_v;
}cow[2505],lotion[2505];

int num_c, num_l;

bool cmp2(no1 x, no1 y)
{
	if (x.min_v == y.min_v)
	{
		return x.max_v < y.max_v;
	}
	else
	{
		return x.min_v < y.min_v;
	}
}

class cmp
{
public:
	bool operator()(int x, int y)
	{
		return x > y;
	}
};

priority_queue<int, vector<int>, cmp>qu;

int main()
{
	int i,j,ans;
	scanf("%d%d", &num_c, &num_l);

	for (i = 1; i <= num_c; i++)
	{
		scanf("%d%d", &cow[i].min_v, &cow[i].max_v);
	}
	for (i = 1; i <= num_l; i++)
	{
		scanf("%d%d", &lotion[i].min_v, &lotion[i].max_v);
	}
	sort(cow + 1, cow + num_c + 1, cmp2);
	sort(lotion + 1, lotion + num_l + 1, cmp2);

	j = 1; 
	ans = 0;
	
	for (i = 1; i <= num_l;i++)
	{
		while (j <= num_c && cow[j].min_v <= lotion[i].min_v)
		{
			qu.push(cow[j].max_v);
			j++;
		}
		while (qu.size() != 0 && lotion[i].max_v != 0)
		{
			int x = qu.top();
			qu.pop();
			if (x < lotion[i].min_v)
			{
				continue;
			}
			else
			{
				ans++;
				lotion[i].max_v--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
