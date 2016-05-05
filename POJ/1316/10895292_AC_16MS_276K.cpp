#include <iostream>
using namespace std;

int main ()
{
	int ture[11000]={0},a,b,c,d,i;
	for(a=0;a<=9;a++)
		for(b=0;b<=9;b++)
			for(c=0;c<=9;c++)
				for(d=0;d<=9;d++)
				{
					i=1001*a+101*b+11*c+2*d;
					ture[i]=1;
				}
	for(i=1;i<10000;i++)
	{
		if(!ture[i])
			cout<<i<<endl;
	}
	return 0;
}