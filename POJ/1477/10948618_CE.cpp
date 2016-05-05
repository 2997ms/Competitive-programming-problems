#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int count,column,count1,h[100],sum,result;
	cin>>column;
	for(count=1;cin>>column&&column!=0;count++)
	{
		sum=0;result=0;
		for(count1=1;count1<=column;count1++)
		{
			cin>>h[count1];
			sum=sum+h[count1];
		}
		sum=floor(sum/column);
		for(count1=1;count1<=column;count1++)
		{
			result=result+abs(h[count1]-sum);
		}
		cout<<"Set #"<<count<<endl;
		cout<<"The minimum number of moves is "<<result/2<<'.'<<endl<<endl;
	}
	return 0;
}



		

