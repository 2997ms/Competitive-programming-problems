#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#pragma warning(disable:4996)
using namespace std;

string all;
char ans[20], ask[20];
map<string, string>dic;

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int flag = 0;
	dic.clear();
	while (getline(cin, all))
	{
		if (all == "")
		{
			flag = 1;
			continue;
		}
		if (flag == 0)
		{
			sscanf(all.c_str(), "%s%s", ans, ask);
			dic[ask] = ans;
		}
		else
		{
			sscanf(all.c_str(), "%s", ask);
			if (dic[ask] == "")
			{
				cout << "eh" << endl;
			}
			else
			{
				cout << dic[ask] << endl;
			}
		}
	}
	return 0;
}
