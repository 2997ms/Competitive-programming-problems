#include <stdio.h>
#include <stdlib.h>

main()
{
	char a[105],b[105],temp;
	
	int n=0,i=0;

	scanf("%s",a);

	getchar();

	scanf("%s",b);

	while (a[n])
	{
		if(a[n]<65||a[n]>90)
		{
			printf("NO\n");

			return 0;
		}
		n++;
	}
	if(n==1)
	{
		printf("YES\n");
		
		return 0;
	}
	for(;n>=2;n--)
	{
		for(;i<n&&a[i+1];i++)
		{
		  if(a[i]>a[i+1])
		  {
			temp=a[i+1];

			a[i+1]=a[i];

			a[i]=temp;
		  }
		}
		i=0;
	}
	while (b[n])
	{
		if(b[n]<65||b[n]>90)
		{
			printf("NO\n");

			return 0;
		}
		n++;
	}
	for(;n>=2;n--)
	{
		for(i=0;i<n&&b[i+1];i++)
		{
		  if(b[i]>b[i+1])
		  {
			temp=b[i+1];

			b[i+1]=b[i];

			b[i]=temp;
		  }
		}
		i=0;
	}
	for(i=0;a[i+1];i++)
	{
		if(a[i]-b[i]!=a[i+1]-b[i+1])
		{
			printf("NO\n");

			return 0;
		}
	}
	if(a[i+1]==0)
	
		printf("YES\n");
	
	return 0;
}
