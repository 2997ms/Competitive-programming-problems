#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	string m,n;
	cin>>m>>n;

	int i,j,result=0;
	for(i=0;i<m.length();i++)
	{
		for(j=0;j<n.length();j++)
		{
			result += (m[i]-'0')*(n[j]-'0');
		}
	}
	cout<<result<<endl;
    return 0;
}