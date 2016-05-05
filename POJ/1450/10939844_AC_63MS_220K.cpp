#include <iostream>
using namespace std;

int main()
{
	int count1,count2,n,m;
	float result;
	cin>>count2;
	for(count1=1;count1<=count2;count1++)
	{
		cin>>n>>m;
		if(n%2!=0&&m%2!=0)
			result=n*m+0.41;
		else
			result=n*m;
		printf("Scenario #%d:\n",count1);
        printf("%.2f\n\n",result);
	}
	return 0;
}
