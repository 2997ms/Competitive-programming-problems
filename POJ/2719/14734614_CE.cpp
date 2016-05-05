#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

string test;

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	int len,i,temp,sum;
	while(cin>>test)
	{
		if(test=="0")
			break;
		len=test.length();
		sum=0;

		for(i=0;i<=len-1;i++)
		{
			if(test[i]>='5')
			{
				temp=test[i]-'0'-1;
			}
			else
			{
				temp=test[i]-'0';
			}
			sum +=temp*pow(9,len-i-1);
		}
		cout<<test<<": "<<sum<<endl;
	}

	return 0;
}
