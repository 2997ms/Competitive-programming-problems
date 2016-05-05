#include <iostream>
#include <string>
#include<algorithm> 
using namespace std;
bool cmp(int a,int b)  
{  
    return a>b;  
}  
int poww(int x,int y)  
{  
    int xx=x;  
    for(int i=1;i<y;i++)  
        xx=xx*x;  
    return xx;  
}  
int main()
{
	char s[500],A1,A2,A3,A4,A5;
	int target,sign=0,count1,count2,count3,count4,count5,len;
	while(cin>>target>>s&&target!=0&&!(s[0]=='E'||s[1]=='N'||s[2]=='D'||s[3]=='\0'))
	{
		sign=0;
		len=strlen(s);
		sort(s,s+len,cmp); 
		for(count1=0;count1<len;count1++)
		{
			for(count2=0;count2<len;count2++)
			{
				if((count1)!=(count2))
				{
				for(count3=0;count3<len;count3++)
				{
					if(count1!=(count3)&&(count2)!=(count3))
					{
					for(count4=0;count4<len;count4++)
					{
						if(count1!=(count4)&&(count2)!=(count4)&&(count3)!=(count4))
						{
						  for(count5=0;count5<len;count5++)
						  {
							if(count1!=(count5)&&(count2)!=(count5)&&(count3)!=(count5)&&(count4)!=count5)
							{
								if((s[count1]-'A'+1)-poww((int)(s[count2]-'A'+1),2)+poww((int)(s[count3]-'A'+1),3)-poww((int)(s[count4]-'A'+1),4)+poww((int)(s[count5]-'A'+1),5)==target)
								{
								sign=1;
                                A1=s[count1];A2=s[count2];A3=s[count3];A5=s[count5];A4=s[count4];							
								break;
								}
							}
						  }
						}
						if(sign)
				      	  break;
					}
					}
					if(sign)
						break;
				}
				}
				if(sign)
					break;
			}
			
            if(sign)
					break;
		}
		if(!sign)
			cout<<"no solution"<<endl;
		else
			cout<<A1<<A2<<A3<<A4<<A5<<endl;
	}
		return 0;
}

