#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
	char a[105],b[105];int num1[27],num2[27],e[101],d[101],i,count=1;;

	memset(num1,0,sizeof(num1));
	memset(num2,0,sizeof(num2));

	for(i=0;;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]=='\n')
			break;
		num1[a[i]-'A']++;
		
	}
   for(i=0;;i++)
   {
	   scanf("%c",&b[i]);
		if(b[i]=='\n')
			break;
	  num2[b[i]-'A']++;
   }
	for(i=0;i<27;i++)
       e[b[i]]++;
   for(i=0;i<101;i++)
   if(d[i]!=e[i])
{
	   count=0;break;}
    if(count==0)
		printf("NO\n");
	else
		printf("YES\n");   
	return 0;
}
