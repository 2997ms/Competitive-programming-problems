#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#pragma warning(disable:4996)
using namespace std;

const int N1 = 15000;
const int N2 = 100;
int num,m[15000];

struct no {
	int sno[7];
}node[N1][N2];

bool check(no node_one,int pos, int x)
{
	int i, j;
	bool flag = false;
	for (j = 0; j < 6; j++)
	{
		for (i = 1; i <= 6; i++)
		{
			if (node_one.sno[i] != node[pos][x].sno[(i + j) % 6 + 1])
			{
				if (i == 6)
					flag = true;
			}
		}
	}

	if (flag)
		return true;
	
	for (j = 0; j < 6; j++)
	{
		for (i = 1; i <= 6; i++)
		{
			if (node_one.sno[i] != node[pos][x].sno[(i - j) % 6 + 1])
			{
				if (i == 6)
					flag = true;
			}
		}
	}
	return flag;
}

int main()
{
	int i,j;
	bool flag = true;

	memset(m, 0, sizeof(m));
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		no node_one;
		for (j = 1; j <= 6; j++)
		{
			scanf("%d",&node_one.sno[j]);
		}
		if (!flag)continue;

		int pos = (node_one.sno[1] + node_one.sno[2] + node_one.sno[3] + node_one.sno[4] + node_one.sno[5] + node_one.sno[6])%14997;

		for (j = 0; j < m[pos]; j++)
		{
			if (check(node_one,pos,j))
			{
				flag = false;
				break;
			}
		}
		if (!flag)
		{
			cout << "Twin snowflakes found." << endl;
		}
		else
		{
			m[pos]++;
			node[pos][m[pos]] = node_one;
		}
	}
	if (flag)
	{
		cout << "No two snowflakes are alike." << endl;
	}
	return 0;
}
