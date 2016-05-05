#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

string out;

void recursion(string test)
{
	if(test.length()==1)
	{
		out=test;
		return;
	}
	int i,result=0;
	for(i=0;i<test.length();i++)
	{
		result += test[i]-'0';
	}
	int temp;
	string test2;
	while(result!=0)
	{
		temp=result%10;
		test2 += temp+'0';
		result /=10;
	}
	recursion(test2);
}

int main()
{	
	string test;
	
	while(cin>>test)
	{
		if(test=="0")
			break;
		recursion(test);
		cout<<out<<endl;
	}
	return 0;
}
