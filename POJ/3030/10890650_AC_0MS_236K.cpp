#include <iostream>
using namespace std;
int main()
{
	int i,count;
	long long r,e,c;
	cin>>i;
	for(count=1;count<=i;count++)
	{
		cin>>r>>e>>c;
		if(r==e-c)
		{
			cout<<"does not matter"<<endl;
		}
		else if(r>e-c)
		{
			cout<<"do not advertise"<<endl;
		}
		else if(r<e-c)
		{
			cout<<"advertise"<<endl;
		}
	}
	return 0;
}
