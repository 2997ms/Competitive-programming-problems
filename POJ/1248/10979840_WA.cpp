#include <iostream>
#include <string>
using namespace std;

int main()
{
	char s[50],max[50];
	int target,sign=0,count1,count2,count3,count4,count5;
    max[1]=-1;max[2]=-1;max[3]=-1;max[4]=-1;max[5]=-1;
	while(cin>>target>>s&&target!=0&&!(s[0]=='E'||s[1]=='N'||s[2]=='D'||s[3]=='\0'))
	{
		sign=0;
		for(count1=0;count1<strlen(s);count1++)
		{
			for(count2=0;count2<strlen(s);count2++)
			{
				for(count3=0;count3<strlen(s);count3++)
				{
					for(count4=0;count4<strlen(s);count4++)
					{
						for(count5=0;count5<strlen(s);count5++)
						{
							if((s[count1]-'A'+1)-(s[count2]-'A'+1)*(s[count2]-'A'+1)+(s[count3]-'A'+1)*(s[count3]-'A'+1)*(s[count3]-'A'+1)-(s[count4]-'A'+1)*(s[count4]-'A'+1)*(s[count4]-'A'+1)*(s[count4]-'A'+1)+(s[count5]-'A'+1)*(s[count5]-'A'+1)*(s[count5]-'A'+1)*(s[count5]-'A'+1)*(s[count5]-'A'+1)==target&&(s[count1])!=(s[count2])&&(s[count1])!=(s[count3])&&(s[count1])!=(s[count4])&&(s[count1])!=(s[count5])&&(s[count2])!=(s[count3])&&(s[count2])!=(s[count4])&&(s[count2])!=(s[count5])&&(s[count3])!=(s[count4])&&(s[count3])!=(s[count5])&&(s[count4])!=(s[count5]) )
							{
								sign=1;
								max[1]=s[count1];max[2]=s[count2];max[3]=s[count3];max[4]=s[count4];max[5]=s[count5];
							}
						}
					}
				}
			}
		}
		if(!sign)
			cout<<"no solution"<<endl;
		else
		{
			cout<<max[1]<<max[2]<<max[3]<<max[4]<<max[5]<<endl;
		}
		max[1]=-1;max[2]=-1;max[3]=-1;max[4]=-1;max[5]=-1;
	}
		return 0;
}

