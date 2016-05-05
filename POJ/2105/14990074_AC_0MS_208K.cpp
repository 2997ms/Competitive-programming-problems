#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int N;
	string s;
	scanf("%d", &N);

	while (N--)
	{
		cin >> s;
		for (int i = 0; i < s.length(); i++)
		{
			s[i] = s[i] - '0';
		}
		for (int i = 0; i < 4; i++)
		{
			int res = s[i * 8] * 128 + s[i * 8 + 1] * 64 + s[i * 8 + 2] * 32 + s[i * 8 + 3] * 16 + s[i * 8 + 4] * 8 + s[i * 8 + 5] * 4 + s[i * 8 + 6] * 2 + s[i * 8 + 7] * 1;
			cout << res;
			if (i != 3)
			{
				cout << ".";
			}
		}
		cout << endl;
	}

	return 0;
}