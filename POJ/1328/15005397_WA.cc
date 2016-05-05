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
double cmp(const sa&a, const sa&b)
{

	return a.left > b.left;
}
int main()
{
	sa tmp;
	int n;
	double d;
	int k = 1;
	while (cin >> n >> d)
	{
		memset(dat, 0, sizeof(dat));
		int sum = 1;
		double maxn = 0.0, minn = 0.0;
		if (n == 0 && d == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			cin >> dat[i].x >> dat[i].y;
			dat[i].left = dat[i].x - sqrt(d*d - dat[i].y*dat[i].y);
			dat[i].right = dat[i].x + sqrt(d*d - dat[i].y*dat[i].y);
			maxn = max(maxn, dat[i].y);
			minn = min(minn, dat[i].y);
			// cout<<maxn<<endl;
		}
		//  cout<<maxn<<endl;
		sort(dat, dat + n, cmp);
		tmp = dat[0];
		if (maxn > d || d <= 0 || minn < 0)
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
			for (int i = 0; i<n; i++)
				if (sqrt((tmp.left - dat[i].x)*(tmp.left - dat[i].x) + dat[i].y*dat[i].y)>d)
				{
					sum++;
					tmp = dat[i];
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
	return 0;
}