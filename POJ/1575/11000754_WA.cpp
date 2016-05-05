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
	int count;
	for(count=1;count<len;count++)
	{
		if((s[count]=='a'||s[count]=='e'||s[count]=='i'||s[count]=='o'||s[count]=='u')&&(s[count-1]=='a'||s[count-1]=='e'||s[count-1]=='i'||s[count-1]=='o'||s[count-1]=='u')&&(s[count+1]=='a'||s[count+1]=='e'||s[count+1]=='i'||s[count+1]=='o'||s[count+1]=='u'))
			return 0;
		if((s[count]!='a'&&s[count]!='e'&&s[count]!='i'&&s[count]!='o'&&s[count]!='u')&&(s[count-1]!='a'&&s[count-1]!='e'&&s[count-1]!='i'&&s[count-1]!='o'&&s[count-1]!='u')&&(s[count+1]!='a'&&s[count+1]!='e'&&s[count+1]!='i'&&s[count+1]!='o'&&s[count+1]!='u'))
			return 0;
	}
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

