#include <iostream>
#include <string>
using namespace std;

int main()
{
	char s[50];
	int target,sign=0,count1,count2,count3,count4,count5;
	while(cin>>target>>s&&target!=0&&!(s[0]=='E'||s[1]=='N'||s[2]=='D'||s[3]=='\0'))
	{
		sign=0;
		for(count1=strlen(s)-1;count1>=0;count1--)
		{
			for(count2=strlen(s)-1;count2>=0;count2--)
			{
				for(count3=strlen(s)-1;count3>=0;count3--)
				{
					for(count4=strlen(s)-1;count4>=0;count4--)
					{
						for(count5=strlen(s)-1;count5>=0;count5--)
						{
							if((s[count1]-'A'+1)-(s[count2]-'A'+1)*(s[count2]-'A'+1)+(s[count3]-'A'+1)*(s[count3]-'A'+1)*(s[count3]-'A'+1)-(s[count4]-'A'+1)*(s[count4]-'A'+1)*(s[count4]-'A'+1)*(s[count4]-'A'+1)+(s[count5]-'A'+1)*(s[count5]-'A'+1)*(s[count5]-'A'+1)*(s[count5]-'A'+1)*(s[count5]-'A'+1)==target&&(s[count1])!=(s[count2])&&(s[count1])!=(s[count3])&&(s[count1])!=(s[count4])&&(s[count1])!=(s[count5])&&(s[count2])!=(s[count3])&&(s[count2])!=(s[count4])&&(s[count2])!=(s[count5])&&(s[count3])!=(s[count4])&&(s[count3])!=(s[count5])&&(s[count4])!=(s[count5]) )
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
		memset(s,'\0',sizeof(s));
	}
		return 0;
}

