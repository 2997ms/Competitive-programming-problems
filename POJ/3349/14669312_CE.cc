#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stdlib.h>
#pragma warning(disable:4996)
using namespace std;

map<string, int>hash1;
int num;

int main()
{
	int i, temp[8];
	char str[8][20];
	bool flag = true;
	hash1.clear();

	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		scanf("%d%d%d%d%d%d", &temp[1], &temp[2], &temp[3], &temp[4], &temp[5], &temp[6]);
		if (!flag) continue;

		itoa(temp[1], str[1], 10);
		itoa(temp[2], str[2], 10);
		itoa(temp[3], str[3], 10);
		itoa(temp[4], str[4], 10);
		itoa(temp[5], str[5], 10);
		itoa(temp[6], str[6], 10);

		string s1 = str[1];
		string s2 = str[2];
		string s3 = str[3];
		string s4 = str[4];
		string s5 = str[5];
		string s6 = str[6];
		if (hash1["s" + s1 + "s" + s2 + "s" + s3 + "s" + s4 + "s" + s5 + "s" + s6]
			|| hash1["s" + s6 + "s" + s5 + "s" + s4 + "s" + s3 + "s" + s2 + "s" + s1]

			|| hash1["s" + s2 + "s" + s3 + "s" + s4 + "s" + s5 + "s" + s6 + "s" + s1]
			|| hash1["s" + s1 + "s" + s6 + "s" + s5 + "s" + s4 + "s" + s3 + "s" + s2]

			|| hash1["s" + s3 + "s" + s4 + "s" + s5 + "s" + s6 + "s" + s1 + "s" + s2]
			|| hash1["s" + s2 + "s" + s1 + "s" + s6 + "s" + s5 + "s" + s4 + "s" + s3]

			|| hash1["s" + s4 + "s" + s5 + "s" + s6 + "s" + s1 + "s" + s2 + "s" + s3]
			|| hash1["s" + s3 + "s" + s2 + "s" + s1 + "s" + s6 + "s" + s5 + "s" + s4]

			|| hash1["s" + s5 + "s" + s6 + "s" + s1 + "s" + s2 + "s" + s3 + "s" + s4]
			|| hash1["s" + s4 + "s" + s3 + "s" + s2 + "s" + s1 + "s" + s6 + "s" + s5]

			|| hash1["s" + s6 + "s" + s1 + "s" + s2 + "s" + s3 + "s" + s4 + "s" + s5]
			|| hash1["s" + s5 + "s" + s4 + "s" + s3 + "s" + s2 + "s" + s1 + "s" + s6]
			)
		{
			flag = false;
		}
		else
		{
			hash1["s" + s1 + "s" + s2 + "s" + s3 + "s" + s4 + "s" + s5 + "s" + s6] = 1;
			hash1["s" + s2 + "s" + s3 + "s" + s4 + "s" + s5 + "s" + s6 + "s" + s1] = 1;
			hash1["s" + s3 + "s" + s4 + "s" + s5 + "s" + s6 + "s" + s1 + "s" + s2] = 1;
			hash1["s" + s4 + "s" + s5 + "s" + s6 + "s" + s1 + "s" + s2 + "s" + s3] = 1;
			hash1["s" + s5 + "s" + s6 + "s" + s1 + "s" + s2 + "s" + s3 + "s" + s4] = 1;
			hash1["s" + s6 + "s" + s1 + "s" + s2 + "s" + s3 + "s" + s4 + "s" + s5] = 1;

			hash1["s" + s6 + "s" + s5 + "s" + s4 + "s" + s3 + "s" + s2 + "s" + s1] = 1;
			hash1["s" + s1 + "s" + s6 + "s" + s5 + "s" + s4 + "s" + s3 + "s" + s2] = 1;
			hash1["s" + s2 + "s" + s1 + "s" + s6 + "s" + s5 + "s" + s4 + "s" + s3] = 1;
			hash1["s" + s3 + "s" + s2 + "s" + s1 + "s" + s6 + "s" + s5 + "s" + s4] = 1;
			hash1["s" + s4 + "s" + s3 + "s" + s2 + "s" + s1 + "s" + s6 + "s" + s5] = 1;
			hash1["s" + s5 + "s" + s4 + "s" + s3 + "s" + s2 + "s" + s1 + "s" + s6] = 1;
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
