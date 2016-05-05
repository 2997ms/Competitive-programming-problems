#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string a;
	while(cin>>a&&a!="#")
	{
		if(next_permutation(a.begin(),a.end()))
		{
			cout<<a<<endl;
		}
		else
		{
			cout<<"No Successor"<<endl;
		}
	}
	return 0;
}