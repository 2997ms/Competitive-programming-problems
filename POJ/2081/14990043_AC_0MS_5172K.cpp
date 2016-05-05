#include<iostream>
using namespace std;

int a[5000010]={0};
int b[5000010]={0};

int main()
{
	a[0]=0;
	b[0]=-1;
	int i,x;
	for(i=1;i<500010;i++)
	{
		a[i]=a[i-1]-i;
		if(a[i]<0||b[a[i]]==-1)
				a[i]=a[i-1]+i;
		b[a[i]]=-1;
	}
	while(cin>>x)
	{
		if(x==-1)break;
		cout<<a[x]<<endl;
	}
	return 0;
}