#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#pragma warning(disable:4996)
using namespace std;

map<string, int>hash1;
int num,temp[8];
string s1;
string s2;
string s3;
string s4;
string s5;
string s6;

void change()
{
	int te;
	s1 = "";
	s2 = "";
	s3 = "";
	s4 = "";
	s5 = "";
	s6 = "";
	while (temp[1] != 0)
	{
		s1 += '0' + temp[1] % 10;
		temp[1] /= 10;
	}
	while (temp[2] != 0)
	{
		s2 += '0' + temp[2] % 10;
		temp[2] /= 10;
	}
	while (temp[3] != 0)
	{
		s3 += '0' + temp[3] % 10;
		temp[3] /= 10;
	}
	while (temp[4] != 0)
	{
		s4 += '0' + temp[4] % 10;
		temp[4] /= 10;
	}
	while (temp[5] != 0)
	{
		s5 += '0' + temp[5] % 10;
		temp[5] /= 10;
	}
	while (temp[6] != 0)
	{
		s6 += '0' + temp[6] % 10;
		temp[6] /= 10;
	}
}

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

		itoa(temp[1], str[1], 10);
		itoa(temp[2], str[2], 10);
		itoa(temp[3], str[3], 10);
		itoa(temp[4], str[4], 10);
		itoa(temp[5], str[5], 10);
		itoa(temp[6], str[6], 10);

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

