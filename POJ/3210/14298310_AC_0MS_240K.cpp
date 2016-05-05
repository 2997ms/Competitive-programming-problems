#include<iostream>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
			break;

		if(n%2)
		{
			cout<<n-1<<endl;
		}
		else
		{
			cout<<"No Solution!"<<endl;
		}
	}
	return 0;
}