#include<stdio.h>
#include<string.h>
int main()
{char a[100002],b[100002];
 int i,j;
 while(scanf("%s %s",a,b)!=EOF)
   {i=0,j=0;
    for(;j<strlen(b);j++)
     {
	  if(a[i]==b[j]) 
	   i++;
     }
     if(i==strlen(a))printf("Yes\n");
      else printf("No\n");
   }
 return 0;
}
