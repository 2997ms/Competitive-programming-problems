#include <iostream>
using namespace std;
int main()
{
	int i,count,a,b;
	cin>>i;
	for(count=1;count<=i;count++)
	{
		cin>>a>>b;
		if(a>=b)
			cout<<"MMM BRAINS"<<endl;
		else
			cout<<"NO BRAINS"<<endl;
	}
	return 0;
}
