#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int n,c;
	while(scanf("%d%d",&n,&c)!=EOF)
	{
		if(n==0)
		{
			cout<<0<<endl;
			continue;
		}
		else
		{
			if(c/(2*n)-1>=0)
				cout<<(-n*(c/(2*n))*(c/(2*n))+c*(c/(2*n))< -n*(c/(2*n)-1)*(c/(2*n)-1)+c*(c/(2*n)-1)?c/(2*n)-1:c/(2*n))<<endl;
			else
				cout<<c/(2*n)<<endl;
		}
	}
	return 0;
}
