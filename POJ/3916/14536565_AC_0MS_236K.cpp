#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#pragma warning(disable:4996)
using namespace std;

vector<int>a;
int num;

int main()
{
	int i,temp;
	while(cin>>num)
	{
		if(num==0)
			break;
		a.clear();
		for(i=1;i<=num;i++)
		{
			cin>>temp;
			a.push_back(temp);
		}
       
		vector<int>::iterator iter =unique(a.begin(),a.end());  
        a.erase(iter,a.end()); 
		for(i=0;i<a.size();i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<"$"<<endl;
	}
	return 0;
}
