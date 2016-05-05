#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

map <int,string> web;

int main()
{	
	string operate;
	string website;

	int cur=1,zong=1;
	web[1]="http://www.acm.org/";

	while(cin>>operate)
	{
		if(operate=="QUIT")
			break;
		if(operate=="VISIT")
		{
			cin>>website;
			web[++cur]=website;
			zong=cur;
			cout<<website<<endl;
		}
		if(operate=="BACK")
		{
			if(cur==1)
			{
				cout<<"Ignored"<<endl;
			}
			else
			{
				cur--;
				cout<<web[cur]<<endl;
			}
		}
		if(operate=="FORWARD")
		{
			if(cur==zong)
			{
				cout<<"Ignored"<<endl;
			}
			else
			{
				cur++;
				cout<<web[cur]<<endl;
			}
		}
	}

	return 0;
}