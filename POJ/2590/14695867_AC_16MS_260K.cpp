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

	int Test, i, j;
	int temp,ans,cnt;
	cin>>Test;
	
	while(Test--)
	{
		cin >> i >> j;
		temp = j - i;

		ans = 0;
		cnt = 0;
		while (temp > 0)
		{
			++cnt;
			temp = temp - cnt;
			ans ++;

			if (temp > 0)
			{
				temp = temp - cnt;
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
