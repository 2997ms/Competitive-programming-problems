#include <iostream>
#include <string>
using namespace std;
char answer[400][200],code[400];
int panduan(char a[200],char b[200])
{
	int count,len1,len2;
	len1=strlen(a);
	len2=strlen(b);
	for(count=0;count<len1&&count<len2;count++)
	{
		if(a[count]!=b[count])
			return a[count]-b[count];
	}
	return len1-len2;
}
void jiaohuan(char a[200],char b[200])
{
	int count,len1,len2,temp1;
	char temp;
	len1=strlen(a);
	len2=strlen(b);
	for(count=0;count<len1&&count<len2;count++)
	{
		temp=a[count];
		a[count]=b[count];
		b[count]=temp;
	}
	temp1=0;
	if(a[count])
	{
		while(a[count])
		{
		  b[count]=a[count];
		  count++;
		  temp1++;
		}
	a[count-temp1]='\0';
	b[count]='\0';
	}
	temp1=0;
	if(b[count])
	{
		while(b[count])
		{
		  a[count]=b[count];
		  count++;
		  temp1++;
		}
	b[count-temp1]='\0';
	a[count]='\0';
	}
}

int main()
{
	int count1,count2,count3,count4,flag1=0,flag2=0,flag[200]={0},sum=0;
	for(count4=1;;count4++)
	{
		cin>>answer[count4];
		if(answer[count4][0]=='X')
			break;
	}
	for(count1=1;count1<count4;count1++)
	{
		for(count2=count1+1;count2<count4;count2++)
		{
			if(panduan(answer[count1],answer[count2])>0)
				jiaohuan(answer[count1],answer[count2]);
		}
	}
	for(;;)
	{
		cin>>code;
		sum=0;flag1=0;
		memset(flag,0,sizeof(flag));
		if(code[0]=='X')
		    break;
		for(count2=1;count2<count4;count2++)//每一组字符
		{
			for(count3=0;count3<strlen(code);count3++)//code上的每一个字符
			{
		      for(count1=0;count1<strlen(answer[count2]);count1++)
			  {
			    if(code[count3]==answer[count2][count1]&&!flag[count1])
				{
				  flag[count1]++;
				  flag1++;
				}
			  }
			  if(!flag1)
				  break;
			}
			if(flag1==strlen(code)&&flag1==strlen(answer[count2]))
			{
				cout<<answer[count2]<<endl;
				flag2++;
			}
			flag1=0;
		    memset(flag,0,sizeof(flag));
		}
		if(!flag2)
			cout<<"NOT A VALID WORD"<<endl;
		cout<<"******"<<endl;
		flag2=0;
	}
	return 0;
}


