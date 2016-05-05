#include<stdio.h>
#include<algorithm>
main()
{int t,n,a,b,i,j;
scanf("%d",&t);
while(t--)
{scanf("%d",&n);
int s[401]={0};
for(j=0;j<n;j++)
 {scanf("%d%d",&a,&b);
 if(a>b)
  a+=b,b=a-b,a=a-b;
 for(i=a-1+a%2;i<=b+b%2;i++)
  s[i]++;
 }
std::sort(s,s+401);
printf("%d\n",s[400]*10);
}
}
