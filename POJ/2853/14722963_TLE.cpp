#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int Test, k, i, j, count;
	cin >> Test;
	while (Test--)
	{
		cin >> j >> k;
		count = 0;
		for (i = 3; i <= k/2 ; i = i + 2)
		{
			if (k%i == 0)
			{
				count++;
			}
		}
		cout << j<<" "<< count +(k%2==0?0:1)<< endl;
	}
	return 0;
}
