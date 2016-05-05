#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int N;

class cmp
{
public:
	bool operator()(int x, int y)
	{
		return x > y;
	}
};

int main()
{
	int i, temp1, temp2;
	long long ans = 0;
	priority_queue<int, vector<int>, cmp>qu;
	
	cin >> N;
	for (i = 1; i <= N; i++)
	{
		cin >> temp1;
		qu.push(temp1);
	}
	while (qu.size() != 1)
	{
		temp1 = qu.top();
		qu.pop();

		temp2 = qu.top();
		qu.pop();

		ans = ans + temp1 + temp2;
		qu.push(temp1 + temp2);
	}

	cout << ans << endl;
	return 0;
}
