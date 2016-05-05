#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int count1,count2,a,b;
	cin>>count1;
	for(count2=1;count2<=count1;count2++)
	{
		cin>>a>>b;
		char s1[20],s2[20];
		sprintf(s1,"%d",a);
		sprintf(s2,"%d",b);
		reverse(s1,s1+strlen(s1));
		reverse(s2,s2+strlen(s2));
		sscanf(s1,"%d",&a);
		sscanf(s2,"%d",&b);
		sprintf(s1,"%d",a+b);
		reverse(s1,s1+strlen(s1));
		sscanf(s1,"%d",&a);
		printf("%d\n",a);
	}
	return 0;
}
