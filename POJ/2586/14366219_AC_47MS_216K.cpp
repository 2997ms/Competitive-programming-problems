#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int s,d;
	while(cin>>s>>d)
	{
		int result=-1;
		if(4*s<d)
		{
			if(10*s-2*d>result)
				result=10*s-2*d;
		}
		if(3*s<2*d)
		{
			if(8*s-4*d>result)
				result=8*s-4*d;
		}
		if(2*s<3*d)
		{
			if(6*s-6*d>=0)
				result= 6*s-6*d;
		}
		if(s<4*d)
		{
			if(3*s-9*d>result)
				result=3*s-9*d;
		}
		if(result<0)
		{
			cout<<"Deficit"<<endl;
		}
		else
		{
			cout<<result<<endl;
		}
	}
	return 0;
}