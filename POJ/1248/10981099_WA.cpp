#include <iostream>
#include <string>
using namespace std;

int main()
{
	char s[50];
	int target,sign=0,count1,count2,count3,count4,count5;
   
	while(cin>>target>>s&&target!=0&&!(s[0]=='E'&&s[1]=='N'&&s[2]=='D'&&s[3]=='\0'))
	{
		sign=0;
		for(count1=0;s[count1];count1++)
		{
			for(count2=0;s[count2];count2++)
			{
				while(s[count2]==s[count1])
				{
					count2++;
				}
				for(count3=0;s[count3];count3++)
				{
					while(s[count3]==s[count2]||s[count3]==s[count1])
					{
						count3++;
					}
					for(count4=0;s[count4];count4++)
					{
						while(s[count4]==s[count3]||s[count4]==s[count2]||s[count4]==s[count1])
						{
							count4++;
						}
						for(count5=0;s[count5];count5++)
						{
							while(s[count5]==s[count4]||s[count5]==s[count3]||s[count5]==s[count2]||s[count5]==s[count1])
							{
								count5++;
							}
							if((count1+1)-(count2+1)*(count2+1)+(count3+1)*(count3+1)*(count3+1)-(count4+1)*(count4+1)*(count4+1)*(count4+1)+(count5+1)*(count5+1)*(count5+1)*(count5+1)*(count5+1)==target)
							{
								sign=1;
								cout<<s[count1]<<s[count2]<<s[count3]<<s[count4]<<s[count5]<<endl;
								break;
							}
						}
						if(sign)
							break;
					}
					if(sign)
						break;
				}
				if(sign)
					break;
			}
			if(sign)
				break;
		}
		if(!sign)
			cout<<"no solution"<<endl;
	}
		return 0;
}


