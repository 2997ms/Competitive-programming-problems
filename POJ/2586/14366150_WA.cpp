#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int s,d;
	while(cin>>s>>d)
	{
		if(4*s<d)
		{
			if(10*s-2*d>0)
				cout<<10*s-2*d<<endl;
			else
				cout<<"Deficit"<<endl;
		}
		else if(3*s<2*d)
		{
			if(8*s-4*d>0)
				cout<<8*s-4*d<<endl;
			else
				cout<<"Deficit"<<endl;
		}
		else if(2*s<3*d)
		{
			if(6*s-6*d>0)
				cout<<6*s-6*d<<endl;
			else
				cout<<"Deficit"<<endl;
		}
		else 
		{
			cout<<"Deficit"<<endl;
		}
	}
	return 0;
}