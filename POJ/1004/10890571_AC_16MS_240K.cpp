#include <iostream>
using namespace std;
int main()
{
	float sum=0.0,a;int i;
	for(i=1;i<=12;i++)
	{
		cin>>a;
		sum+=a;
	}
	printf("$");
	printf("%.2lf\n",sum/12);
	return 0;
}