#include <iostream>
using namespace std;

int main()
{
	long country,match,count,mark,markzong=0;
	char countryname[30];
	cin>>country>>match;
	while(country!=0&&match!=0)
	{
	for(count=1;count<=country;count++)
	{
		cin>>countryname;
		cin>>mark;
		markzong=mark+markzong;		
	}
	cout<<3*match-markzong<<endl;
	cin>>country>>match;
	markzong=0;
	mark=0;
	}
	return 0;
}
