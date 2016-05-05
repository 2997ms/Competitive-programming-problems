#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

int n, nc;
char ch[1600005];
map<string, int>m;

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	
	int i, j, k, len;
	while (scanf("%d%d", &n, &nc) != EOF)
	{
		scanf("%s", ch);
		
		m.clear();
		
		string wc = ch;
		for (i = 0; ch[i+n-1]!='\0'; i++)
		{
			string x = wc.substr(i, n);
			if (m[x] == 0)
			{
				m[x]++;
			}
		}
		printf("%d\n", m.size());
	}
	//system("pause");
	return 0;
}