#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#pragma warning(disable:4996)
using namespace std;

const int N = 1000000007;
map<int, int>hash1;
map<int, int>hash2;
int num,temp[8];

int main()
{
	int i;
	char str[8][20];
	bool flag = true;
	hash1.clear();

	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		scanf("%d%d%d%d%d%d", &temp[1], &temp[2], &temp[3], &temp[4], &temp[5], &temp[6]);
		if (!flag) continue;

		if ( hash1[ (temp[1] * temp[2]) % N + (temp[2] * temp[3]) % N + (temp[2] * temp[3]) % N
			        + (temp[3] * temp[4]) % N + (temp[4] * temp[5]) % N + (temp[5] * temp[6]) % N
			        + (temp[6] * temp[1]) % N]
			&&hash2[temp[1]+ temp[2]+ temp[3]+ temp[4]+ temp[5] + temp[6]]
			)
		{
			flag = false;
		}
		else
		{
			hash1[(temp[1] * temp[2]) % N + (temp[2] * temp[3]) % N + (temp[2] * temp[3]) % N
				+ (temp[3] * temp[4]) % N + (temp[4] * temp[5]) % N + (temp[5] * temp[6]) % N
				+ (temp[6] * temp[1]) % N] = 1;
			hash2[temp[1] + temp[2] + temp[3] + temp[4] + temp[5] + temp[6]] = 1;
		}
	}
	if (flag)
	{
		cout << "No two snowflakes are alike." << endl;
	}
	else
	{
		cout << "Twin snowflakes found." << endl;
	}
	return 0;
}
