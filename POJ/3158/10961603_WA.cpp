#include <iostream>
#include <cstdio>  
#include <cstdlib>  
#include <cstring>
#include <cmath>
using namespace std;
int qiu(char shang[105],char di[105])
{
	int dicount,shangcount,len1,len2,dicount1,count=0;
	len2=strlen(di);
	len1=strlen(shang);
	for(dicount=0;dicount<len2&&shangcount<len1;dicount++)
	{
		shangcount=0;
		for(dicount1=dicount;!(shang[shangcount]=='2'&&di[dicount1]=='2');)
		{
			count++;
			shangcount++;
			dicount1++;
			if(shang[shangcount]=='2'&&di[dicount1]=='2')
			{
				break;
			}
			if(shangcount==len1||dicount1==len2)
				return count;
		}
		count=0;
	}
	return count;
}
int main()
{
	char a[105],b[105];
	int len1,len2,finaljian=200;
	cin>>a>>b;
	len1=strlen(a);
	len2=strlen(b);
	if((len1+len2-qiu(a,b))<(len1+len2-qiu(b,a)))
		cout<<len1+len2-qiu(a,b)<<endl;
	else if((len1+len2-qiu(a,b))>(len1+len2-qiu(b,a)))
		cout<<len1+len2-qiu(b,a)<<endl;
    else if((len1+len2-qiu(a,b))==(len1+len2-qiu(b,a)))
		cout<<len1+len2-qiu(a,b)<<endl;
	return 0;
}


