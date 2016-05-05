#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int front,behind;
string a;

bool find()
{
	int len =a.length()-1;
	while(len>0)
	{
		if(a[len-1] >= a[len])
		{
		}
		else
		{
			front = len-1;
			return true;
		}
		len--;
	}
	return false;
}

void change()
{
	int len =a.length()-1;
	int min=100;

	while(len>front)
	{
		if(a[len]>a[front]&&a[len]<min)
		{
			min=len;
		}
		len--;
	}
	char temp=a[min];
	a[min]=a[front];
	a[front]=temp;
}

void sort()
{
	int len = a.length();
	int i,j;
	char temp;

	for(i=front+1;i<len;i++)
	{
		for(j=i;j<len;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

int main()
{
	while(cin>>a&&a!="#")
	{
		if(find())
		{
			change();
			sort();
			cout<<a<<endl;
		}
		else
		{
			cout<<"No Successor"<<endl;
		}
	}
	return 0;
}