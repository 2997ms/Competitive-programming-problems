#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int num,i=1;
	while(cin>>num)
	{
		if(num==0)
			break;
		cout<<i<<". ";
		i++;
		if(num%2)
			cout<<"odd ";
		else
			cout<<"even ";
		cout<<num/2<<endl;
	}
	return 0;
}
