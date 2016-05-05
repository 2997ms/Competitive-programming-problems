#include <iostream>
#include <cstdio>  
#include <cstdlib>  
#include <cstring>
#include <cmath>
using namespace std;
int qiu(char shang[105],char di[105])
{
	int dicount,shangcount,len1,len2,jian,finaljian=0;
	len2=strlen(di);
	len1=strlen(shang);
	for(dicount=0;dicount<len2;dicount++)
	{
		shangcount=0;
		jian=0;
		if(!(di[dicount]=='2'&&shang[shangcount]=='2'))
		{
			dicount++;
			shangcount++;
			jian++;
			for(;dicount<len2&&shangcount<len1;dicount++,shangcount++)
			{
				if(!(di[dicount]=='2'&&shang[shangcount]=='2'))
				{
					jian++;
				}
				else
				{
					finaljian=0;
					break;
				}
				if(jian>finaljian)
					finaljian=jian;
			}
		}
	}
	return finaljian;
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


