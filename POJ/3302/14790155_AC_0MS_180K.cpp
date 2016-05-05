#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;

string s1,s2,s3;
bool check(string x,string y)
{
	int i=0,j=0;
	while(i<x.length()&&j<y.length())
	{
		if(x[i]==y[j])
		{
			j++;
		}
		i++;
	}
	if(j == y.length())
		return true;
	else
		return false;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int test;
	scanf("%d",&test);

	while(test--)
	{
		cin>>s1>>s2;
		s3=s2;
		reverse(s2.begin(),s2.end());
		if(check(s1,s2)||check(s1,s3))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}