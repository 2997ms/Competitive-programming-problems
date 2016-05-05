#include <iostream>
using namespace std;

int main()
{
	int f0,f1,f2;
	while(scanf("%d%d%d",&f0,&f1,&f2)==3)
	{
		cout<<(9*(f2+f0-2*f1))/2+3*(4*f1-f2-3*f0)/2+f0<<' '<<8*(f2+f0-2*f1)+2*(4*f1-f2-3*f0)+f0<<' '<<25*(f2+f0-2*f1)/2+5*(4*f1-f2-3*f0)/2+f0<<endl;
	}
	return 0;
}