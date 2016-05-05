
#include <iostream>
#include <string>
#include<algorithm> 
using namespace std;
bool cmp(int a,int b)  
{  
    return a>b;  
}  
int main()
{
	char s[50];
	int target,sign=0,count1,count2,count3,count4,count5,len;
	while(cin>>target>>s&&target!=0)
	{
		sign=0;
		len=strlen(s);
		sort(s,s+len,cmp); 
		for(count1=0;count1<len;count1++)
		{
			for(count2=0;count2<len;count2++)
			{
				for(count3=0;count3<len;count3++)
				{
					for(count4=0;count4<len;count4++)
					{
						for(count5=0;count5<len;count5++)
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
	}
		return 0;
}


