#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
using namespace std;

int minn;
int val[25];
int val_c[25];

void dfs(int i, int a[],int num)
{
	if (i == 21)
	{
		minn = min(minn, num);
		return;
	}
	if (a[i - 1] == 1)
	{
		a[i] = (a[i] + 1) & 1;
		a[i + 1] = (a[i + 1] + 1) & 1;
		dfs(i + 1, a, num + 1);
	}
	else
	{
		dfs(i + 1, a, num);
		
		a[i] = (a[i] + 1) & 1;
		a[i + 1] = (a[i + 1] + 1) & 1;
		dfs(i + 1, a, num + 1);
	}
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int i;

	memset(val, 0, sizeof(val));
	for (i = 1; i <= 20; i++)
		scanf("%d", val + i);
	
	minn = 200;
	dfs(1,val,0);

	cout << minn << endl;
	//system("pause");
	return 0;
}