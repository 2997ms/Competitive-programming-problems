#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int years,money,lilv;
	double lilv1,sum=0;
	cin>>lilv>>money>>years;

	lilv1=1+(double)lilv/100;
	sum=money;
	for(int count=1;count<=years;count++)
	{
		sum=sum*lilv1;
	}
	money=floor(sum);
	cout<<money<<endl;
	return 0;
}
