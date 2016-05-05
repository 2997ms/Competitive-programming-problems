#include <iostream>
#include <string>
using namespace std;
int panduan1(string s,int len)
{
	int count;
	for(count=0;count<len;count++)
	{
		if(s[count]=='a'||s[count]=='e'||s[count]=='i'||s[count]=='o'||s[count]=='u')
			return 1;
	}
	return 0;
}
int panduan2(string s,int len)
{
	int count;
	for(count=1;count<len;count++)
	{
		if(s[count]==s[count-1])
		{
			if(s[count]=='e'||s[count]=='o')
			{}
			else
			return 0;
		}
	}
	return 1;
}
int panduan3(string s,int len)
{
	int count,count1[30]={0},count2[6]={0};
	for(count=0;count<len;count++)
	{
		if(s[count]=='a')
			count2[1]++;
		if(s[count]=='e')
			count2[2]++;
		if(s[count]=='i')
			count2[3]++;
		if(s[count]=='o')
			count2[4]++;
		if(s[count]=='u')
			count2[5]++;
		if(s[count]>='b'&&s[count]<='d')
			count1[s[count]-'b'+1]++;
		if(s[count]>='f'&&s[count]<='h')
			count1[s[count]-'b']++;
		if(s[count]>='j'&&s[count]<='n')
			count1[s[count]-'b'-1]++;
		if(s[count]>='p'&&s[count]<='t')
			count1[s[count]-'b'-2]++;
		if(s[count]>='v'&&s[count]<='z')
			count1[s[count]-'b'-3]++;
	}
	if(len>=3)
	{
	   for(count=1;count<=3&&count<len;count++)
	   {
		if(count2[count]&&count2[count+1]&&count2[count+2])
			return 0;
	   }
	    for(count=1;count<=21;count++)
		{
		 if(count1[count]&&count1[count+1]&&count1[count+2])
			return 0;
		}
	}
	else
		return 1;
	return 1;
}

int main()
{
	char s[100];
	int len;
	while(cin>>s)
	{
		if(s[0]=='e'&&s[1]=='n'&&s[2]=='d'&&s[3]=='\0')
			break;
		len=strlen(s);
		if(panduan1(s,len)&&panduan2(s,len)&&panduan3(s,len))
			cout<<'<'<<s<<'>'<<" is acceptable."<<endl;
		else
	        cout<<'<'<<s<<'>'<<" is not acceptable."<<endl;
	}
	return 0;
}

