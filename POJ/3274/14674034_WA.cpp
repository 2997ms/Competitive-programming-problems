#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#pragma warning(disable:4996)
using namespace std;

int n, k;
int val[100005];

map<int, int>searc;//看是否有冲突

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	searc.clear();
	int i, diff, ans = 1;
	
	scanf("%d%d", &n, &k);
	diff = pow(2.0, k) - 1;

	val[0] = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);
		val[i] = val[i] + val[i - 1];
		if (val[i] > diff)
			val[i] = val[i] - diff;
		if (searc[val[i]] == 0)
		{
			searc[val[i]] = i;
		}
		else
		{
			if (i - searc[val[i]] > ans)
			{
				ans = i - searc[val[i]];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
