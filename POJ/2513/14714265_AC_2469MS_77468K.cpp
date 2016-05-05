#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
class node
{
public:
	bool flag1;
	int id;

	node *next[27];

	node()
	{
		flag1 = false;
		id = 0;
		memset(next, 0, sizeof(next));
	}
}root;

int color = 0;
int degree[500005];
int ancestor[500005];

int hash1(char *stick)
{
	node *no = &root;
	int i = 0;
	while (stick[i] != '\0')
	{
		int j = stick[i] - 'a';
		if (!no->next[j])
		{
			no->next[j] = new node;
		}
		no = no->next[j];
		i++;
	}
	if (no->flag1 == false)
	{
		no->flag1 = true;
		no->id = ++color;
	}
	return no->id;
}

int find(int x)
{
	while (ancestor[x] != x)
	{
		x = ancestor[x];
	}
	return x;
}

void union_set(int i, int j)
{
	int x = find(i);
	int y = find(j);

	ancestor[x] = y;
}

int main()
{
	char stick1[20], stick2[20];
	memset(degree, 0, sizeof(degree));
	for (int i = 0; i <= 500000; i++)
		ancestor[i] = i;

	while (cin >> stick1 >> stick2)
	{
		int i = hash1(stick1);
		int j = hash1(stick2);

		degree[i]++;
		degree[j]++;

		union_set(i, j);
	}

	int result = 0;
	int s = find(1);
	for (int i = 1; i <= color; i++)
	{
		if (degree[i] % 2)
		{
			result++;
		}
		if (result > 2)
		{
			cout << "Impossible" << endl;
			return 0;
		}
		if (s != find(i))
		{
			cout << "Impossible" << endl;
			return 0;
		}
	}
	if(result==1)
		cout << "Impossible" << endl;
	else
		cout << "Possible" << endl;
	return 0;
}
