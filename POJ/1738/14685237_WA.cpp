#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int n,ans,stone_num;
int stone[50005];

void combine(int t)
{
	int i,j;
	int temp = stone[t] + stone[t - 1];
	ans += temp;

	stone_num--;
	for (j = t - 1; j > 0 && stone[j - 1] < temp; j--)
		stone[j] = stone[j - 1];
	
	stone[j] = temp;
	
	while (j > 2 && stone[j] > stone[j - 2])
	{
		int dis = stone_num - j;
		combine(j - 1);
		j = stone_num - dis;
	}
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int i;

	while (scanf("%d", &n)!=EOF && n)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d", &stone[i]);
		}
		stone_num = 1;
		ans = 0;

		for (i = 1; i < n; i++)
		{
			stone[stone_num++] = stone[i];

			while (stone_num >= 3 && stone[stone_num - 3]>stone[stone_num - 1])
			{
				combine(stone_num - 2);
			}
		}
		while (stone_num > 1)combine(stone_num - 1);
		cout << ans << endl;
	}
	return 0;
}
