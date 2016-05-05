#include <iostream>
using namespace std;

int main()
{
	char a[105],b[105];
    int count,line1,line2,count1;
	cin>>a;
	while(a[0]!='0')
	{
		for(line1=0;a[line1];line1++);
		cin>>b;
		if(b[0]=='0')
			break;
		for(line2=0;b[line2];line2++);
		if(line1>line2)
		{
			for(count=line2;count>=0;count--)
			{
			    b[count+line1-line2]=b[count];
				b[count]='0';
			}
		}
		else if(line1<line2)
		{
			for(count=line1;count>=0;count--)
			{
				a[count+line2-line1]=a[count];
				a[count]='0';
			}
		}
		for(count=((line1<line2?line2:line1)-1);count>=0;count--)
			{
				a[count]=a[count]+b[count]-48;
				if(a[count]>'9')
				{
					a[count]-=10;
					if(count==0)
					{
						for(count1=line1;count1>=0;count1--)
						{
						   a[count1+1]=a[count1];
						}
					 a[count1+1]='1';
					}	
					else
					    a[count-1]++;
				}
			}
	}
	for(count=0;a[count]<='9'&&a[count]>='0';count++)
       cout<<a[count];
	cout<<endl;
	return 0;
}