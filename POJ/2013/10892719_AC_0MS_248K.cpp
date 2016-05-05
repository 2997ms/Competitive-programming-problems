#include <iostream>
using namespace std;
int main()
{
	int i,count,count1,b[20],flag=0;
	char a[20][30];
	cin>>i;
	while(i!=0)
	{
		for(count=1;count<=i;count++)
		{
			cin>>a[count];
		}
		for(count=1,count1=1;count<=i;count=count+2,count1++)
		{
			b[count1]=count;
		}
		for(count=2,count1=i;count<=i;count=count+2,count1--)
		{
			b[count1]=count;
		}
		cout<<"SET "<<++flag<<endl;
		for(count=1;count<=i;count++)
		{
			cout<<a[b[count]]<<endl;
		}
		cin>>i;
	}
	return 0;
}