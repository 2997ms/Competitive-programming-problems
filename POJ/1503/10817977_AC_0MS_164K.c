#include <stdio.h>
#include<string.h>
#include <stdlib.h>
char s[1001];
int sum[1002];
int main()
{
 int i,j;
 while(gets(s)) 
 {
  j=strlen(s);
  if(s[0]=='0'&&j==1)
   break;
  for(i=j-1;i>=0;i--) 
   sum[j-i-1]+=(s[i]-'0');
 }
 j=1001; 
 while(!sum[j])
  j--;
 for(i=0;i<j;i++) 
 { 
  sum[i+1]+=sum[i]/10;
  sum[i]=sum[i]%10;
 }
 for(i=j;i>=0;i--) 
  printf("%d",sum[i]);
 printf("\n");
 return 0;
}

