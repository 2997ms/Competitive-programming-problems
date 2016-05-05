#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

string test;

int main()
{
	while(cin>>test)
	{
		if(test=="0")
			break;
		
		int len = test.length();
		int i,k=1,result=0;

		for(i=len-1;i>=0;i--)
		{
			result = result+ (test[i]-'0')*(pow(2,k)-1);
			k++;
		}
		cout<<result<<endl;
	}

	system("pause");
	return 0;
}
