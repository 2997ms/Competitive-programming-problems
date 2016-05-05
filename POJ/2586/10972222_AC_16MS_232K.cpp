#include <iostream>
using namespace std;

int main()
{
	int s,d;
	int ans=1;
	while(scanf("%d%d",&s,&d)==2)
	{
		ans=-1;
		if(4*s<d)
		{
			ans=10*s-2*d;
		}
		if(3*s<2*d)
		{
			if(8*s-4*d>ans)
				ans=8*s-4*d;
		}
		if(2*s<3*d)
		{
			if(6*s-6*d>ans)
			{
				ans=6*s-6*d;
			}
		}
		if(s<4*d)
		{
			if(3*s-9*d>ans)
				ans=3*s-9*d;
		}
		if(ans>0)
			cout<<ans<<endl;
		else
			cout<<"Deficit"<<endl;
	}
	return 0;
}

