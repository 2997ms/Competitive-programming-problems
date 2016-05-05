#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

string moshi,pipei;

int result;
int next_moshi[10005];

void get_next()
{
	int i,j=-1;
	int len=moshi.length();
	next_moshi[0]=-1;

	for(i=0;i<len;)
	{
		if(j==-1||moshi[i]==moshi[j])
		{
			i++;
			j++;

			if(moshi[i]==moshi[j])
			{
				next_moshi[i]=next_moshi[j];
			}
			else
			{
				next_moshi[i]=j;
			}
		}
		else
		{
			j=next_moshi[j];
		}
	}
}

void get_result()
{
	int i=0,j=0;

	int len_pipei=pipei.length();
	int len_moshi=moshi.length();

	while(j<len_pipei)
	{
		int temp=j;
		while(temp<len_pipei&&moshi[i]==pipei[temp])
		{
			i++;
			temp++;
			
			if(i==len_moshi)
				break;
			if(moshi[i]==pipei[temp])
				continue;
			else
			{
				i=next_moshi[i];
				j++;
				temp=j;
			}
		}
		if(i==len_moshi)
		{
			result++;
			i=0;
			j++;
		}
		else if(i==-1||i==0)
		{
			j++;
			i=0;
		}
	}
}

int main()
{
	int Test;
	cin>>Test;

	while(Test--)
	{
		result=0;

		cin>>moshi>>pipei;
		
		memset(next_moshi,0,sizeof(next_moshi));
		
		get_next();
		get_result();

		cout<<result<<endl;
	}
	return 0;
}