#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int mi,mj,mk,min=10000000,volumn,surface,r1,r2,r3;
	cin>>volumn;
	for(mi=1;mi<sqrt((float)volumn)+1;mi++)
	{
		if(volumn%mi==0)
		{
			for(mj=1;mj<(volumn/mi);mj++)
			{
				if((volumn/mi)%mj==0)
				{
					mk=volumn/mi/mj;
					surface=mj*mi+mj*mk+mi*mk;
					if(surface<min)
					{
						min=surface;
						r1=mi;r2=mj;r3=mk;
					}
				}
			}
		}
	}
	cout<<r1<<' '<<r2<<' '<<r3<<endl;
	return 0;
}
