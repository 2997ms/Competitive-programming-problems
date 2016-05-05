#include <iostream>
using namespace std;
int main()
{
	char ch;int i,count,a,b,l,num,num1,num2,m[105][105]={0},sum=0;
	cin>>i;
	for(count=1;count<=i;count++)
	{
		cin>>ch;
		if(ch=='B')
		{
			for(num=1;num<=4;num++)
			{
				cin>>ch;
			}
			cin>>a>>b>>l;

			for(num1=a;num1<a+l;num1++)
			{
				for(num2=b;num2<b+l;num2++)
				{
					m[num1][num2]=1;
				}
			}
		}
		if(ch=='W')
		{
			for(num=1;num<=4;num++)
			{
				cin>>ch;
			}
			cin>>a>>b>>l;
			for(num1=a;num1<a+l;num1++)
			{
				for(num2=b;num2<b+l;num2++)
				{
					m[num1][num2]=0;
				}
			}
		}
		if(ch=='T')
		{
			for(num=1;num<=3;num++)
			{
				cin>>ch;
			}
			cin>>a>>b>>l;
			for(num1=a;num1<a+l;num1++)
			{
				for(num2=b;num2<b+l;num2++)
				{
					if(m[num1][num2])
					{
						sum++;
					}
				}
			}
			cout<<sum<<endl;
			sum=0;
		}
	}
	return 0;
}



