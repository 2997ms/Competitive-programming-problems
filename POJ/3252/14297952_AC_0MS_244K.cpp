#include <iostream>
using namespace std;

int c[33][33];
int bin[35];

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

void dec_to_bin(int x)
{
	memset(bin,0,sizeof(bin));

	while(x!=0)
	{
		bin[++bin[0]]=x&1;
		x=x>>1;
	}
}

int result(int x)
{
	dec_to_bin(x);
	
	int i,j;
	int sum=0;

	for(i=0;i<bin[0]-1;i++)
	{
		for(j=i/2+1;j<=i;j++)
		{
			sum +=c[i][j];
		}
	}

	int zero=0;

	for(i=bin[0]-1;i>=1;i--)
	{
		if(bin[i])
		{
			for(j=(bin[0]+1)/2-(zero+1);j<=i-1;j++)
				sum += c[i-1][j];
		}
		else
			zero++;
	}
	return sum;
}

int main()
{
	init();
	int a,b;
	cin>>a>>b;

	cout<<result(b+1)-result(a)<<endl;
	return 0;
}