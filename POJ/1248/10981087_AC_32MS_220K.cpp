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
	char s[500];
	int target,sign=0,count1,count2,count3,count4,count5,len,strnum[500],A1,A2,A3,A4,A5,v,w,x,y,z;
	while(cin>>target>>s&&target)
	{
		sign=0;
		len=strlen(s);
		sort(s,s+len,cmp); 
		for(int i=0;i<len;i++)  
            strnum[i]=s[i]-'A'+1; 
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
								 A1=strnum[count1];A2=strnum[count2];A3=strnum[count3];A4=strnum[count4];A5=strnum[count5];  
                                            v=strnum[count1];  
                                            w=poww(strnum[count2],2);  
                                            x=poww(strnum[count3],3);  
                                            y=poww(strnum[count4],4);  
                                            z=poww(strnum[count5],5);  
                                            if(v-w+x-y+z==target)  
                                            {  
                                                sign=1;  
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
			printf("%c%c%c%c%c\n",A1+'A'-1,A2+'A'-1,A3+'A'-1,A4+'A'-1,A5+'A'-1);
	}
		return 0;
}

