#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring> 
#include <set>
#include <map>
using namespace std;

int n, m;
map<string, int>dic;

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	
	int i, j, k;
	int sala;
	string words;
	scanf("%d%d", &n, &m);

	for (i = 1; i <= n;i++)
	{
		cin >> words >> sala;
		dic[words] = sala;
	}
	long long sum;
	for (i = 1; i <= m; i++)
	{
		sum = 0;
		while (cin >> words)
		{
			if (words == ".")
				break;
			sum += dic[words];
		}
		cout << sum << endl;
	}
	return 0;
}