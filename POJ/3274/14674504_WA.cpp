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
int value[100005];
int val[100005][31];

map<int, int>searc;//看是否有冲突
vector<int>dic[100005];

int check(int i, int key)
{
	int j,h,answer = 0;
	for (j = 0; j < dic[searc[key]].size(); j++)
	{
		for (h = 2; h <= k; h++)
		{
			if ((val[dic[searc[key]][j]][h]-val[i][h]) != (val[dic[searc[key]][j]][h-1] - val[i][h-1]))
				break;
		}
		if (h == k + 1)
		{
			if (i - dic[searc[key]][j] > answer)
			{
				answer = i - dic[searc[key]][j];
				if (value[dic[searc[key]][j]] == value[i])
					answer++;
			}
		}
	}
	if (answer == 0)
	{
		dic[searc[key]].push_back(i);
	}
	return answer;
}

int main()
{

	int i, ans, fea, key, dic_num, temp,temp2;
	
	while (scanf("%d%d", &n, &k) == 2)
	{	
		ans = 0;
		dic_num = 0;
		searc.clear();

		for (i = 0; i < 31; i++)
		{
			val[0][i] = 0;
		}
		for (i = 0; i < 10001; i++)
		{
			dic[i].clear();
		}
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &value[i]);
			
			key = 0;
			fea = 1;
			temp2 = value[i];

			while (fea<=k)
			{
				val[i][fea] = (temp2& 1) + val[i - 1][fea];
				
				if(fea!=1) key += abs(val[i][fea] - val[i][fea - 1]);
				fea++;
				temp2 = temp2 >> 1;
			}
			if (value[i] == 0 || value[i] == pow(2.0, k) - 1)
			{
				ans = max(ans,1);
			}
			if (key == 0)
			{
				ans = max(ans, i);
			}
			/*if (i == 8)
			{
				i++;
				i--;
			}*/
			if (searc[key] == 0)
			{
				searc[key] = ++dic_num;
				dic[dic_num].push_back(i);
			}
			else
			{
				temp = check(i, key);
				if (temp>ans)
				{
					ans = temp;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
