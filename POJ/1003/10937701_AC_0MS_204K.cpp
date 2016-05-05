#include <iostream>
using namespace std;

int main()
{
	double x,sum=0;
	int n;
	cin>>x;
	for(;;)
	{
		if(!x)
		 break;
		for(n=2;;n++)
		{
			if(sum>x)
				break;
			sum=sum+(double)1/n;
		}
		cout<<n-2<<" card(s)"<<endl;
		sum=0;
		cin>>x;
	}
	return 0;
}
