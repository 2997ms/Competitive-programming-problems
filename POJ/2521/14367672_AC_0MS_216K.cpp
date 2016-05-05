#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n,m,p,c;
	while(cin>>n>>m>>p>>c && n+m+p+c)
	{
		cout<<n-m+p<<endl;
	}
	return 0;
}