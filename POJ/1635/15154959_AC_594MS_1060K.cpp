#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <ctime>;
#include <set>
#include <map>
using namespace std;

#define INF 0x3fffffff
typedef long long ll;

const ll mod = 1e9 + 7;
const int maxn = 3005;

char x1[maxn], x2[maxn];

string solve(int le,int ri,string x)
{
	vector<string>now;
	
	int i;
	int st = le, subtree = 0;
	for (i = le; i <= ri; i++)
	{
		if (x[i] == '0')
		{
			subtree++;
		}
		else if (x[i] == '1')
		{
			subtree--;
		}
		if (subtree == 0)
		{
			if (st == i - 1)
			{
				now.push_back("01");
			}
			else
			{
				now.push_back("0" + solve(st + 1, i - 1, x) + "1");
			}
			st = i + 1;
		}
	}
	sort(now.begin(), now.end());
	string res = "";
	for (i = 0; i < now.size(); i++)
		res += now[i];
	return res;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s%s", x1, x2);
		string s1 = solve(0, strlen(x1) - 1, x1);
		string s2 = solve(0, strlen(x2) - 1, x2);
		if (strcmp(s1.c_str(), s2.c_str()) == 0)
		{
			puts("same");
		}
		else
		{
			puts("different");
		}
	}
	//system("pause");
	return 0;
}