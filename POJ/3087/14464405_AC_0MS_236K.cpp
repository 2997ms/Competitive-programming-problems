#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

map<string,int> meet;
int Test,i,i1,num;
string s1,s2,dis;

string shuffle(string t1,string t2)
{
	string re="";
	for(i=0;i<num;i++)
	{
		re += t2[i];
		re += t1[i];
	}
	return re;
}

int cal()
{
	string temp=shuffle(s1,s2);
	meet[temp]=1;
	string temp1,temp2,temp3;
	while(1)
	{
		if(temp==dis)
			return meet[temp];
		temp1=temp.substr(0,num);
		temp2=temp.substr(num,num);

		temp3=shuffle(temp1,temp2);
		if(meet[temp3])
			return -1;
		else
			meet[temp3]=meet[temp]+1;
		temp=temp3;
	}
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	cin>>Test;
	
	for(i1=1;i1<=Test;i1++)
	{
		cin>>num;
		cin>>s1>>s2;
		cin>>dis;

		cout<<i1<<" "<<cal()<<endl;
	}
	return 0;
}
