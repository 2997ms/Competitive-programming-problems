#include <iostream>
#include <iomanip>
using namespace std;
void isornot(int inter)
{
	int count,sum=0;
	for(count=1;count<inter;count++)
	{
		if(inter%count==0)
		{
			sum=sum+count;
		}
	}
	if(sum==inter)
	{
		cout<<setw(5)<<inter<<"  PERFECT"<<endl;
	}
	if(sum>inter)
	{
		cout<<setw(5)<<inter<<"  ABUNDANT"<<endl;
	}
	if(sum<inter)
	{
		cout<<setw(5)<<inter<<"  DEFICIENT"<<endl;
	}
}

int main()
{
	int inter;
	cout<<"PERFECTION OUTPUT"<<endl;
	for(;cin>>inter&&inter!=0;)
	{
		isornot(inter);
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}