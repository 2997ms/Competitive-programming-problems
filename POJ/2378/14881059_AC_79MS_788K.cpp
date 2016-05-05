#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;

int n, flag;
int used[10005];
int sum[10005];
int max_v[10005];
vector<int>connect[10005];

int dfs(int v)
{
	used[v] = 1;

	int k, size;
	sum[v] = 0;
	max_v[v] = 0;

	size = connect[v].size();

	for (k = 0; k < size; k++)
	{
		if (used[connect[v][k]] == 0)
		{
			int temp = dfs(connect[v][k]);
			max_v[v] = max(max_v[v], temp);
			sum[v] = sum[v] + temp;
		}
	}
	used[v] = 0;
	return sum[v] + 1;
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	
	int i, temp1, temp2;
	scanf("%d", &n);
	
	for (i = 1; i <= n - 1; i++)
	{
		scanf("%d%d", &temp1, &temp2);
		
		connect[temp1].push_back(temp2);
		connect[temp2].push_back(temp1);
	}

	dfs(1);
	flag = 0;
	for (i = 1; i <= n; i++)
	{
		if (max_v[i] <= n / 2 && n - sum[i] - 1 <= n / 2)
		{
			flag = 1;
			printf("%d\n", i);
		}
	}
	if (flag == 0)
		printf("NONE\n");
	//system("pause");
	return 0;
}