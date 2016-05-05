#include<stdio.h>
#include<string.h>
int main()
{char a[100002],b[100002];
 int i,j;
 while(scanf("%s %s",a,b)!=EOF)
   {i=0,j=0;
    for(;b[j];j++)
     {
	  if(a[i]==b[j]) 
	   i++;
     }
     if(a[i]=='\0')printf("Yes\n");
      else printf("No\n");
   }
 return 0;
}