#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector <string> zifu;

bool pend()
{
	int m = zifu.size();
	int i,j;

	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(zifu[i]==zifu[j])
				return false;
		}
	}
	return true;
}

int main()
{
	string a;
	int len,i,k;
	while(cin>>a)
	{
		if(a=="*")
			break;
		len=a.length();

		int flag=1;
		for(k=2;k<len;k++)
		{
			for(i=0;i+k<=len;i=i++)
			{
				string temp;
				temp += a[i];
				temp += a[i+k-1];
				zifu.push_back(temp);
			}
			if(!pend())
			{
				cout<<a<<" is NOT surprising."<<endl;
				flag=0;
				break;
			}
			else
			{
				zifu.clear();
			}
		}
		if(flag)
			cout<<a<<" is surprising."<<endl;
	}

	return 0;
}
