#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#include <string.h>
using namespace std;

struct sa
{
	int begin, end;
} dat[1000050];

int cmp(const sa&x, const sa&y)
{
	if (x.begin == y.begin)
		return x.end>y.end;
	else return x.begin<y.begin;
}
int main()
{
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);

	sa tmp;
	int n, t;
	while (cin >> n >> t)
	{
		memset(dat, 0, sizeof(dat));
		//        memset(tmp,0,sizeof(tmp));
		for (int i = 0; i<n; i++)
			cin >> dat[i].begin >> dat[i].end;
		sort(dat, dat + n, cmp);
		tmp = dat[0];
		if (tmp.begin != 1)
		{
			cout << -1 << endl;
			continue;
		}
		int maxn = -1, sum = 1, flag = 0, b = 0;
		while (tmp.end<t&&flag<n)
		{
			for (int i = 0; i<n; i++)
			{
				if (dat[i].begin <= tmp.end + 1 && dat[i].end >= tmp.end + 1 && tmp.end<t)
				{
					maxn = dat[i].end;
					b = i;

				}
				// cout<<tmp.begin<<" "<<tmp.end<<endl;
			}
			tmp = dat[b];
			if (tmp.end <= t)
			{
				sum++;

				// cout<<sum<<endl;
			}
			flag++;
			//   cout<<flag<<"  "<<'a'<<endl;
			//  cout<<tmp.begin<<" "<<tmp.end<<endl;
		}

		if (tmp.end != t)
		{

			cout << -1 << endl;
		}
		else
		{
			cout << sum << endl;
		}
		//for(int i=0;i<n;i++)
		//  cout<<tmp.begin<<" "<<tmp.end<<endl;
	}
	return 0;
}