#include <iostream>
using namespace std;

int main()
{
	int count1,count2,count3,flag[30],result=0,min=100,sum=0;
	char a[30];
	while(cin>>count1&&count1)
	{
		for(count2=1;count2<=count1;count2++)
		{
			getchar();
			gets(a);

			for(count3=0;count3<25;count3++)
			{
				if(a[count3]==' ')
				{
					result++;
				}
			}
			flag[count2]=result;
            result=0;
		}
		for(count2=1;count2<=count1;count2++)
		{
			if(min>flag[count2])
				min=flag[count2];
		}
		for(count2=1;count2<=count1;count2++)
		{
			sum=sum+flag[count2]-min;
		}
		cout<<sum<<endl;
		sum=0;min=100;
		memset(flag,0,sizeof(flag));
	}
	return 0;
}




