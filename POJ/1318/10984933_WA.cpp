#include <iostream>
#include <string>
using namespace std;

int main()
{
	char answer[400][200],code[400];
	int count1,count2,count3,count4,flag1=0,flag2=0,flag[200]={0},sum=0;
	for(count4=1;;count4++)
	{
		cin>>answer[count4];
		if(answer[count4][0]=='X')
			break;
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


