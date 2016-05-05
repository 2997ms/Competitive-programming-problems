#include<iostream>
#include<string>
#define MAX 10000
int num,MMax=-100,MMin=100;
using namespace std;
int main()
{
	string a,str;
	while(cin>>num&&num)
	{
		cin>>a>>str;
		if(str=="high")
			MMin=num<MMin?num:MMin;
		if(str=="low")
			MMax=num>MMax?num:MMax;
		if(str=="on")
		{
			if(num>MMax&&num<MMin)
				cout<<"Stan may be honest\n";
			else
				cout<<"Stan is dishonest\n";
			MMax=-100;MMin=100;
		}
	}
	return 0;
}