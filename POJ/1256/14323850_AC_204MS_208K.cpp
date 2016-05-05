#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

char s[5000];

bool cmp(char a,char b)
{
	double front,behind;

	if(a>='A'&&a<='Z')
		front = (double)a+31.5;
	else
		front = (double)a;
	
	if(b>='A'&& b<='Z')
		behind = (double)b+31.5;
	else
		behind = (double)b;

	return front<behind;
}
int main()
{
	int count;
	cin>>count;

	while(count--)
	{
		cin>>s;
		sort(s,s+strlen(s),cmp);
		
		cout<<s<<endl;
		while(next_permutation(s,s+strlen(s),cmp))
		{
			cout<<s<<endl;
		}
	}

	return 0;
}
