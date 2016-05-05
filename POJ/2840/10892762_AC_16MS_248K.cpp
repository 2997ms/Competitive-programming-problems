#include <iostream>
using namespace std;
int main()
{
	int i,count,hour,minute;
	char a;
	cin>>i;
	for(count=1;count<=i;count++)
	{
		cin>>hour>>a>>minute;
		if(minute!=0)
		{
			cout<<'0'<<endl;
		}
		else
		{
			if(hour<=12)
				cout<<hour+12<<endl;
			else
				cout<<hour-12<<endl;
		}
	}
	return 0;
}
