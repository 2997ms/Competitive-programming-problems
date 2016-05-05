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

	long long n,c;
	while(scanf("%d%d",&n,&c)!=EOF)
	{
		if(n==0)
		{
			cout<<0<<endl;
			continue;
		}
		else
		{
				cout<<(-1*(c/2)*(c/(2*n))+c*(c/(2*n))< -1*(c/2+1)*(c/(2*n)+1)+c*(c/(2*n)+1)?c/(2*n)+1:c/(2*n))<<endl;
		}
	}
	return 0;
}
