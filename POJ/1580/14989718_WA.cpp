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

int d;
char a[1005], b[1005];

void ex_gcd(int a, int b)
{
	if (b == 0)
	{
		d = a;
	}
	else
	{
		ex_gcd(b, a%b);
	}
}

void solve()
{
	int maxn = 0;
	int i, j, k;
	int len1 = strlen(a);
	int len2 = strlen(b);
	
	int flag = 0;
	if (len1 < len2)
	{
		flag = 1;
		char temp[1005];
		strcpy(temp, b);
		strcpy(b, a);
		strcpy(a, temp);

		int t;
		t = len1;
		len1 = len2;
		len2 = t;
	}
	for (k = 0; k < len1; k++)
	{
		i = k;
		j = 0;
		int res = 0;
		while (i < len1&&j < len2)
		{
			if (a[i] == b[j])
			{
				res++;
			}
			i++;
			j++;
		}
		maxn = max(res, maxn);
	}
	maxn = 2 * maxn;
	if (flag)
	{
		cout << "appx(" << b << "," << a << ") = ";
	}
	else
	{
		cout << "appx(" << a << "," << b << ") = ";
	}
	if (maxn == 0)
	{
		cout << 0 << endl;
	}
	else
	{
		if (maxn == len1 + len2)
		{
			cout << 1 << endl;
		}
		else
		{
			ex_gcd(maxn, len1 + len2);
			cout << maxn / d << "/" << (len1 + len2) / d<<endl;
		}
	}
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	
	while (scanf("%s", a) != EOF)
	{
		if (strcmp(a, "-1") == 0)
			break;
		scanf("%s", b);
		solve();
	}
	return 0;
}