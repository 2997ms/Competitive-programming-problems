#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int L, N, M;
long long dis[60000];

bool check(int mid)
{
	int i,before = 0,cnt = 0;
	for (i = 1; i <= N + 1; )
	{
		if (dis[i] - dis[before] >= mid)
		{
			i++;
			before = i - 1;
		}
		else
		{
			cnt++;
			i++;
		}
	}
	if (cnt <= M)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{

	int i,left,right,mid;
	cin >> L >> N >> M;
	
	dis[0] = 0;
	dis[N + 1] = L;
	
	for (i = 1; i <= N; i++)
	{
		cin >> dis[i];
	}
	sort(dis, dis + 1 + N);

	left = 0;
	right = L;

	while (right - left > 1)
	{
		mid = (right + left) / 2;
		if (check(mid))
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	cout << left << endl;
	return 0;
}
