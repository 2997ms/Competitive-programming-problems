#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int count,count1,result;
	double x,y,length;
	cin>>count;

	for(count1=1;count1<=count;count1++)
	{
		cin>>x>>y;

		length=sqrt(x*x+y*y);

		for(result=1;;result++)
		{
			if(result*50>(3.1415926*length*length)/2&&(result-1)*50<(3.1415926*length*length)/2)
				
				break;
		}

		cout<<"Property "<<count1<<": This property will begin eroding in year "<<result<<'.'<<endl;
	}
	cout<<"END OF OUTPUT."<<endl;

	return 0;
}




