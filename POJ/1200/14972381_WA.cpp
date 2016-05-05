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

const int mod = 10007;

int n, nc;
char ch[16000005];
int num[200];
int has[16000005];

void init()
{
	memset(num, 0, sizeof(num));
	memset(has, 0, sizeof(has));
}

void solve()
{
	int i, j, k;
	int res = 0;
	int len = strlen(ch);

	j = 0;
	for (i = 0; i < len; i++)
	{
		if (num[ch[i]] == 0)num[ch[i]] = ++j;
		if (j == nc)
			break;
	}

	for (i = 0; i+n <= len; i++)
	{
		k = 0;
		for (j = i; j <= n; j++)
		{
			k = k*nc + num[ch[i]];
		}
		if (has[k] == 0)
		{
			has[k] = 1;
			res++;
		}
	}
	printf("%d\n", res);
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	
	int i;
	while (scanf("%d%d%s", &n, &nc, ch) != EOF)
	{
		init();
		solve();
	}
	//system("pause");
	return 0;
}