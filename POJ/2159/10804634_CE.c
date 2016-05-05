#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
	char a[105],b[105];int num1[105],num2[105];

	memset(num1,0,sizeof(num1));
	memset(num2,0,sizeof(num2));

	int i,y,k,j,n,m=0,l=0,count=1;

	for(i=0;;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]=='\n')
			break;
		for(y=0;y<i;y++)
		{
			if(a[i]==a[y])
			{
				num1[m]++;m++;
			}
		}
	}
	for(n=0;n<m;n++)
	{
		for(j=n+1;j<m;j++)
		{
			if(num1[n]>num1[j])
			{
				k=num1[n];num1[n]=num1[j];num1[j]=k;
		
			}
		}
	}
   for(i=0;;i++)
   {
	   scanf("%c",&b[i]);
		if(b[i]=='\n')
			break;
		for(y=0;y<i;y++)
		{		
			if(b[i]==b[y])
			{
				num2[l]++;
				l++;
			}
		}
   }
	for(n=0;n<l;n++)
	{
		for(j=i+1;j<l;j++)
		{
			if(num2[n]>num2[j])
			{
				k=num2[n];num2[n]=num2[j];num2[j]=k;
			}
		}
	}
	for(n=0;n<l;n++)
	{
		if(num2[n]!=num1[n])
		{
			count=0;break;
		}
	}
    if(count==0)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}
