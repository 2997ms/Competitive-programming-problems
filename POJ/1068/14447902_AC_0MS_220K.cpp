#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int Test,num,i;
int ps[225];
int flag[225];

vector<char> seq;

void change()
{
	int qian=0,temp,j;
	for(i=1;i<=num;i++)
	{
		temp = ps[i]-qian;
		for(j=1;j<=temp;j++)
			seq.push_back('<');
		seq.push_back('>');
		qian=ps[i];
	}
}

void cal()
{
	memset(flag,0,sizeof(flag));
	int len= seq.size();
	int j;

	for(i=0;i<len;i++)
	{
		if(seq[i]=='>')
		{
			int result=1;
			for(j=i-1;j>=0;j--)
			{
				if(seq[j]=='>')
					result++;
				if(seq[j]=='<'&&flag[j]==0)
				{
					cout<<result<<" ";
					flag[j]=1;
					break;
				}
			}
		}
	}
	cout<<endl;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	cin>>Test;

	while(Test--)
	{
		cin>>num;
		for(i=1;i<=num;i++)
			cin>>ps[i];
		change();

		cal();
		seq.clear();
	}

	return 0;
}