#include <iostream>
using namespace std;
double jiecheng(int i)
{
	int count;
	double sum=1;
	for(count=1;count<=i;count++)
	{
		sum=sum*count;
	}
	return sum;
}

int main()
{
	double e=1;
	int i;
	cout<<"n e"<<endl<<"- -----------"<<endl<<"0 1"<<endl;
	for(i=1;i<=9;i++)
	{
		e=e+1/jiecheng(i);
		cout<<i<<' '<<e<<endl;
	}
	return 0;
}