#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;

#define maxn 75

int num;
//char *wang_reverse,*sub1,*sub2,*sub3,*sub4;
//char *res1,*res2,*res3,*res4,*res5,*res6,*res7,*res8;
char wang_reverse[80],sub1[80],sub2[80],sub3[80],sub4[80];
char res1[80],res2[80],res3[80],res4[80],res5[80],res6[80],res7[80],res8[80];
struct no
{
	char str[maxn];

}node[maxn*maxn];

void reverse1(char *str)
{
	int i,j,len;
	len=strlen(str);
	for(i=len-1,j=0;i>=0;i--,j++)
		wang_reverse[j]=str[i];
	wang_reverse[j]='\0';
}

void reverse2(char *str)
{
	int i,j,len;
	len=strlen(str);
	for(i=len-1,j=0;i>=0;i--,j++)
		sub3[j]=str[i];
	sub3[j]='\0';
}

void reverse3(char *str)
{
	int i,j,len;
	len=strlen(str);
	for(i=len-1,j=0;i>=0;i--,j++)
		sub4[j]=str[i];
	sub4[j]='\0';
}

void substr(char *str,int i)
{
	int j,len;

	for(j=0;j<i;j++)
		sub1[j]=str[j];
	sub1[j]='\0';
}

void substr_rever(char *str,int i)
{
	int x,j,len;

	len=strlen(str);
	for(j=len-1,x=0;j>=i;j--,x++)
		sub2[x]=str[j];
	sub2[x]='\0';
}

void add_str1(char *re1,char *re2)
{
	int len1=strlen(re1);
	int len2=strlen(re2);
	int i,j;

	for(i=0;i<len1;i++)
	{
		res1[i]=re1[i];
	}
	for(j=0;j<len2;j++)
	{
		res1[i]=re2[j];
		i++;
	}
}

void add_str2(char *re1,char *re2)
{
	int len1=strlen(re1);
	int len2=strlen(re2);
	int i,j;

	for(i=0;i<len1;i++)
	{
		res2[i]=re1[i];
	}
	for(j=0;j<len2;j++)
	{
		res2[i]=re2[j];
		i++;
	}
}

void add_str3(char *re1,char *re2)
{
	int len1=strlen(re1);
	int len2=strlen(re2);
	int i,j;

	for(i=0;i<len1;i++)
	{
		res3[i]=re1[i];
	}
	for(j=0;j<len2;j++)
	{
		res3[i]=re2[j];
		i++;
	}
}

void add_str4(char *re1,char *re2)
{
	int len1=strlen(re1);
	int len2=strlen(re2);
	int i,j;

	for(i=0;i<len1;i++)
	{
		res4[i]=re1[i];
	}
	for(j=0;j<len2;j++)
	{
		res4[i]=re2[j];
		i++;
	}
}

void add_str5(char *re1,char *re2)
{
	int len1=strlen(re1);
	int len2=strlen(re2);
	int i,j;

	for(i=0;i<len1;i++)
	{
		res5[i]=re1[i];
	}
	for(j=0;j<len2;j++)
	{
		res5[i]=re2[j];
		i++;
	}
}
void add_str6(char *re1,char *re2)
{
	int len1=strlen(re1);
	int len2=strlen(re2);
	int i,j;

	for(i=0;i<len1;i++)
	{
		res6[i]=re1[i];
	}
	for(j=0;j<len2;j++)
	{
		res6[i]=re2[j];
		i++;
	}
}
void add_str7(char *re1,char *re2)
{
	int len1=strlen(re1);
	int len2=strlen(re2);
	int i,j;

	for(i=0;i<len1;i++)
	{
		res7[i]=re1[i];
	}
	for(j=0;j<len2;j++)
	{
		res7[i]=re2[j];
		i++;
	}
}
void add_str8(char *re1,char *re2)
{
	int len1=strlen(re1);
	int len2=strlen(re2);
	int i,j;

	for(i=0;i<len1;i++)
	{
		res8[i]=re1[i];
	}
	for(j=0;j<len2;j++)
	{
		res8[i]=re2[j];
		i++;
	}
}

bool judge(char *str)
{
	int i;
	for(i=0;i<num;i++)
	{
		if(strcmp(str,node[i].str)==0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	char wang[80];
	//char wang_reverse[80],sub1[80],sub2[80],sub3[80],sub4[80];
	//char res1[80],res2[80],res3[80],res4[80],res5[80],res6[80],res7[80],res8[80];

	int test,i,len;
	scanf("%d",&test);

	while(test--)
	{
		scanf("%s",wang);
		num=0;
		len=strlen(wang);
		for(i=1;i <= len-1;i++)
		{
			reverse1(wang);//wang_reverse

			substr(wang,i);//sub1
			substr_rever(wang,i);//sub2

			reverse2(sub1);//sub3
			reverse3(sub2);//sub4

			add_str1(sub1,sub2);
			add_str2(sub2,sub1);

			add_str3(sub3,sub2);
			add_str4(sub2,sub3);

			add_str5(sub1,sub4);
			add_str6(sub4,sub1);

			add_str7(sub3,sub4);
			add_str8(sub4,sub3);

			if(judge(res1))
			{
				strcpy(node[num].str,res1);
				num++;
			}
			if(judge(res2))
			{
				strcpy(node[num].str,res2);
				num++;
			}
			if(judge(res3))
			{
				strcpy(node[num].str,res3);
				num++;
			}
			if(judge(res4))
			{
				strcpy(node[num].str,res4);
				num++;
			}
			if(judge(res5))
			{
				strcpy(node[num].str,res5);
				num++;
			}
			if(judge(res6))
			{
				strcpy(node[num].str,res6);
				num++;
			}
			if(judge(res7))
			{
				strcpy(node[num].str,res7);
				num++;
			}
			if(judge(res8))
			{
				strcpy(node[num].str,res8);
				num++;
			}
		}
		printf("%d\n",num);
	}
	//system("pause");
	return 0;
}