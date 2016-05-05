#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

char moshi[10005];
char pipei[1000005];

int result;
int next_moshi[10005];

void get_next()
{
	int i,j=-1;
	int len=strlen(moshi);
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
	
	int len_pipei=strlen(pipei);
	int len_moshi=strlen(moshi);

	while(j<len_pipei&&i<len_moshi)
	{
	
		if(moshi[i]==pipei[j])
		{
			i++;
			j++;
		}
		else
		{
			i=next_moshi[i];
		}
		if(i==len_moshi)
		{
			result++;
			i=next_moshi[i];
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
	scanf("%d",&Test);

	while(Test--)
	{
		result=0;

		scanf("%s%s",moshi,pipei);
		
		get_next();
		get_result();

		cout<<result<<endl;
	}
	return 0;
}