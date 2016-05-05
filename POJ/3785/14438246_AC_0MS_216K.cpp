#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int Test,num;
	char s[100];

	cin>>Test;
	while(Test--)
	{
		cin>>num>>s;
		cout<<num<<" ";

		int n=next_permutation(s,s+strlen(s));
		
		if(n==0)
			cout<<"BIGGEST"<<endl;
		else
			cout<<s<<endl;
	}

	return 0;
}