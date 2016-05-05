#include <iostream>
using namespace std;

int fun(int m,int n)
{
	if(n==1||m==0)
	{
		return 1;
	}	
	if(n>m)
		return fun(m,m);
	else
		return fun(m,n-1)+fun(m-n,n);
}
int main()
{
	int count,m,n;
	cin>>count;
	while(count--)
	{
		cin>>m>>n;
		cout<<fun(m,n)<<endl;
	}
	return 0;
}
