#include <iostream>
using namespace std;

int main()
{
	int a[1500]={1},i=1,j2=0,j3=0,j5=0,m,count;
	while(i<1500)
	{
		m=999999999;
		if(m>2*a[j2])m=2*a[j2];
		if(m>3*a[j3])m=3*a[j3];
		if(m>5*a[j5])m=5*a[j5];
		if(m==2*a[j2])j2++;
        if(m==3*a[j3])j3++;
		if(m==5*a[j5])j5++;
		a[i]=m;
		i++;
	}
	while(cin>>count&&count)
	{
		cout<<a[count-1]<<endl;
	}
	return 0;
}
