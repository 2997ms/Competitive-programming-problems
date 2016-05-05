#pragma warning(disable:4996) 
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct sa
{
	double x, y, left, right;
}dat[1005];
double cmp(const sa&a, const sa&b)/////////////这里改了
{
	if (a.left == b.left)
		return a.right < b.right;
	else
	    return a.left < b.left;
}
int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	sa tmp;
	int n;
	double d;
	int k = 1;
	while (cin >> n >> d)
	{
		memset(dat, 0, sizeof(dat));
		int sum = 1;
		double maxn = 0.0, minn = 0.0;
		if (n == 0 && d == 0)//////////////////////这里改了
			break;
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> dat[i].x >> dat[i].y;
			if (dat[i].y > d || dat[i].y < 0 || d <= 0)
			{
				flag = -1;
			}
			else
			{
				dat[i].left = dat[i].x - sqrt(d*d - dat[i].y*dat[i].y);
				dat[i].right = dat[i].x + sqrt(d*d - dat[i].y*dat[i].y);
			}
		}
		//  cout<<maxn<<endl;
		sort(dat, dat + n, cmp);
		tmp = dat[0];
		if (flag==-1)
		{

			printf("Case ");
			printf("%d", k);
			printf(": ");
			cout << -1 << endl;
			k++;

			continue;
		}
		else
		{
			/*for (int i = 1; i<n; i++)
				if (sqrt((tmp.left - dat[i].x)*(tmp.left - dat[i].x) + dat[i].y*dat[i].y)>d)
				{
					sum++;
					tmp = dat[i];
				}*/
			/////表示这里没看懂

			for (int i = 1; i < n; i++)
			{
				if (dat[i].left > tmp.right)
				{
					sum++;
					tmp = dat[i];
				}
				else if (dat[i].right < tmp.right)
				{
					tmp = dat[i];
				}
			}
		}
		printf("Case ");
		printf("%d", k);
		printf(": ");
		cout << sum << endl;
		k++;
		// for(int i=0;i<n;i++)
		//   cout<<data[i].left<<endl;
	}
	//system("pause");
	return 0;
}