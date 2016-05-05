#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int h[1000002];

void init()
{
	int i, j, multi;

	memset(h, 0, sizeof(h));
	for (i = 5; i <= 1000001; i = i + 4)
	{
		for (j = 5; j <= 1000001; j = j + 4)
		{
			multi = i*j;
			if (multi > 1000001)
				break;
			if (h[i] == 0 && h[j] == 0)
				h[multi] = 1;
			else
				h[multi] = -1;
		}
	}
	int count = 0;
	for (i = 1; i <= 1000001; i++)
	{
		if (h[i] == 1)
			count++;
		h[i] = count;
	}
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	
	int x;
	init();
	
	while (cin >> x&&x)
		cout << x << " " << h[x] << endl;

	return 0;
}
