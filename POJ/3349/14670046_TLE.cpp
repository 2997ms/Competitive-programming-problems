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
	int i, j,cnt;
	bool flag = false;
	for (j = 0; j < 6; j++)
	{
		cnt = 0;
		for (i = 1; i <= 6; i++)
		{
			if (node_one.sno[i] == node[pos][x].sno[(i + j) % 6 + 1])
			{
				cnt++;
				if (cnt == 6)
					return true;
			}
		}
	}
	
	for (j = 7; j >= 2 ; j--)
	{
		cnt = 0;
		for (i = 1; i <= 6; i++)
		{
			if (node_one.sno[i] == node[pos][x].sno[(j-i+6)%6+1])
			{
				cnt++;
				if (cnt == 6)
					return true;
			}
		}
	}
	return flag;
}

int main()
{
	int i,j;
	bool flag = true;
	no node_one;

	memset(m, 0, sizeof(m));
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		for (j = 1; j <= 6; j++)
		{
			scanf("%d",&node_one.sno[j]);
		}
		int pos = (node_one.sno[1] + node_one.sno[2] + node_one.sno[3] + node_one.sno[4] + node_one.sno[5] + node_one.sno[6])%14997;

		for (j = 0; j < m[pos]; j++)
		{
			if (check(node_one,pos,j))
			{
				puts("Twin snowflakes found.");
				return 0;
			}
		}
			node[pos][m[pos]] = node_one;
			m[pos]++;
	}
	puts("No two snowflakes are alike.");
	return 0;
}
