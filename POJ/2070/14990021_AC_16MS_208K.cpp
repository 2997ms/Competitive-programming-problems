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

double sp;
int w, str;

struct no
{
	double sp;
	int wei;
	int str;
	char name[20];

}node[5];

void init()
{
	node[1].sp = 4.5, node[1].wei = 150, node[1].str = 200;
	strcpy(node[1].name, "Wide Receiver");

	node[2].sp = 6.0, node[2].wei = 300, node[2].str = 500;
	strcpy(node[2].name, "Lineman");

	node[3].sp = 5.0, node[3].wei = 200, node[3].str = 300;
	strcpy(node[3].name, "Quarterback");
}

void solve()
{
	int i;
	int flag = 0;

	for (i = 1; i <= 3; i++)
	{
		if (sp <= node[i].sp&&w >= node[i].wei&&str >= node[i].str)
		{
			flag = 1;
			cout << node[i].name <<" ";
		}
	}
	if (flag == 0)
	{
		cout << "No positions" ;
	}
	cout << endl;
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	init();
	while (cin >> sp >> w >> str)
	{
		if (sp == 0 && w == 0 && str == 0)
			break;
		solve();
	}

	return 0;
}