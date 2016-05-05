#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

string s[15];
int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	int i, j, n;
	s[0] = '-';

	for (i = 1; i <= 14; i++)
	{
		s[i] = s[i - 1];
		for (j = 1; j <= s[i-1].length(); j++)
		{
			s[i] += ' ';
		}
		s[i] += s[i - 1];
	}
	while (scanf("%d",&n)!=EOF)
	{
		cout << s[n] << endl;
	}

	return 0;
}
