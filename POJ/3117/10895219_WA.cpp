#include <iostream>
using namespace std;

int main()
{
	int country,match,count,mark,markzong=0,sum1;
	char countryname[30];
	cin>>country>>match;
	while(country!=0&&match!=0)
	{
	for(count=1;count<=country;count++)
	{
		cin>>countryname;
		cin>>mark;
		markzong=mark+markzong;
		sum1=3*match-markzong;
	}
	cout<<sum1<<endl;
	cin>>country>>match;
	markzong=0;
	}
	return 0;
}
