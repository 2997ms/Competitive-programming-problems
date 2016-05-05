#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int c[33][33],len,i,sum;
char temp[50];

void init()
{
	int i,j;
	memset(c,0,sizeof(c));

	for(i=0;i<=32;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(j==0||j==i)
				c[i][j]=1;
			else
				c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
}

bool pend(string temp)
{
	for(i=1;i<len;i++)
	{
		if(temp[i]<temp[i-1])
			return false;
	}
	return true;
}

void dfs(int step)
{
	if(step==len)
		return;

}

int main()
{
	while(scanf("%s",temp)!=EOF)
	{
		init();
		sum=0;
		len=strlen(temp);

		if(pend(temp))
		{
			for(i=1;i<len;i++)
			{
				sum+=c[26][i];
			}
			for(i=0;i<len;i++)
			{
				char temp_c;
				if(i!=len-1)
				{
					if(i==0)
						temp_c='a';
					else
						temp_c=temp[i-1]+1;
					for(;temp_c<temp[i];temp_c++)
					{
						sum += c[26-(temp_c-'a'+1)][len-(i+1)];
					}
				}
				else
				{
					if(len==1)
						sum+=temp[i]-'a'+1;
					else
						sum += temp[i]-temp[i-1];
				}
			}
			cout<<sum<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
