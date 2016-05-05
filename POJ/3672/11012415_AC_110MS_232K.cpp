#include <iostream>
using namespace std;

int main()
{
	int M,T,U,F,D,count,sum=0,result;
	char op;
	scanf("%d%d%d%d%d",&M,&T,&U,&F,&D);
	for(count=1;count<=T;count++)
	{
		getchar();
		scanf("%c",&op);
		if(op=='u'||op=='d')
		{
			sum=sum+U+D;
			if(sum>M&&sum-U-D<=M)
			{
				result=count-1;
			}
		}
		else
		{
			sum=sum+2*F;
			if(sum>M&&sum-2*F<=M)
			{
				result=count-1;
			}
		}
	}
	cout<<result<<endl;
	return 0;
}