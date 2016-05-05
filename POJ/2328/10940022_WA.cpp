#include <iostream>
using namespace std;

int main()
{
	char a[100];
	int high[10],low[10],result,count1=1,count2=1,count,flag=0;
	cin>>result;
	getchar();
	for(;result!=0;)
	{
		gets(a);
		if(a[4]=='h')
		{
			high[count1++]=result;
		}
		else if(a[4]=='l')
		{
			low[count2++]=result;
		}
		else if(a[0]=='r')
		{
			for(count=1;count<count1;count++)
			{
				if(result>high[count])
				{
					cout<<"Stan is dishonest"<<endl;
					flag++;
					count1=1;
		            count2=1;
					break;
				}
			}
			for(count=1;count<count2;count++)
			{
				if(result<low[count])
				{
				    cout<<"Stan is dishonest"<<endl;
					flag++;
					count1=1;
		            count2=1;
					break;
				}
			}
			if(!flag)
			{	
				cout<<"Stan may be honest"<<endl;
			    count1=1;
		        count2=1;
			}
			flag=0;
		}
		cin>>result;
		getchar();
	}
	return 0;
}



