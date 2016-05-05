#include <iostream>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;

int A[105];

int main()
{
	int count,result;
	while(scanf("%d",&count)!=EOF)
	{
		result=0;
		while(count--)
		{
			cin>>A[count];
			result=result^A[count];
		}

		if(result==0)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}