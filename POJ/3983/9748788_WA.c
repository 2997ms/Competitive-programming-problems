#include <stdio.h>
#include <stdlib.h>

int jia(int a,int b)
{
	return a+b;
}
int jian(int a,int b)
{
	return a-b;
}
int cheng(int a,int b)
{
	return a*b;
}
int chu(int a,int b)
{
	return a/b;
}

main()
{
	int a,b,c,d;

	scanf("%d%d%d%d",&a,&b,&c,&d);

	if(jia(jia(jia(a,b),c),d)==24)
		printf("%d+%d+%d+%d",a,b,c,d);
if(jia(jia(jian(a,b),c),d)==24)
		printf("%d-%d+%d+%d",a,b,c,d);//1
if(jia(jia(cheng(a,b),c),d)==24)
		printf("%d*%d+%d+%d",a,b,c,d);
if(b)if(jia(jia((double)chu(a,b),c),d)==24)
		printf("%d/%d+%d+%d",a,b,c,d);
if(jia(jian(jia(a,b),c),d)==24)
		printf("%d+%d-%d+%d",a,b,c,d);
if(jia(jian(jian(a,b),c),d)==24)
		printf("%d-%d-%d+%d",a,b,c,d);
if(jia(jian(cheng(a,b),c),d)==24)
		printf("%d*%d-%d+%d",a,b,c,d);
if(b)if(jia(jian((double)chu(a,b),c),d)==24)
		printf("%d/%d-%d+%d",a,b,c,d);
if(jia(cheng(jia(a,b),c),d)==24)
		printf("(%d+%d)*%d+%d",a,b,c,d);
if(jia(cheng(jian(a,b),c),d)==24)
		printf("(%d-%d)*%d+%d",a,b,c,d);
if(jia(cheng(cheng(a,b),c),d)==24)
		printf("%d*%d*%d+%d",a,b,c,d);
if(b)if(jia(cheng((double)chu(a,b),c),d)==24)
		printf("%d/%d*%d+%d",a,b,c,d);
if(jia(chu(jia(a,b),c),d)==24)
		printf("(%d+%d)/%d+%d",a,b,c,d);
if(c)if(jia((double)chu(jian(a,b),c),d)==24)
		printf("(%d-%d)/%d+%d",a,b,c,d);
if(c)if(jia((double)chu(cheng(a,b),c),d)==24)
		printf("%d*%d/%d+%d",a,b,c,d);
if(b&&c)if(jia((double)chu((double)chu(a,b),c),d)==24)
		printf("%d/%d/%d+%d",a,b,c,d);
	if(jian(jia(jia(a,b),c),d)==24)
		printf("%d+%d+%d-%d",a,b,c,d);
if(jian(jia(jian(a,b),c),d)==24)
		printf("%d-%d+%d-%d",a,b,c,d);
if(jian(jia(cheng(a,b),c),d)==24)
		printf("%d*%d+%d-%d",a,b,c,d);
if(b)if(jian(jia((double)chu(a,b),c),d)==24)
		printf("%d/%d+%d-%d",a,b,c,d);
if(jian(jian(jia(a,b),c),d)==24)
		printf("%d+%d-%d-%d",a,b,c,d);
if(jian(jian(jian(a,b),c),d)==24)
		printf("%d-%d-%d-%d",a,b,c,d);
if(jian(jian(cheng(a,b),c),d)==24)
		printf("%d*%d-%d-%d",a,b,c,d);
if(b)if(jian(jian((double)chu(a,b),c),d)==24)
		printf("%d/%d-%d-%d",a,b,c,d);
if(jian(cheng(jia(a,b),c),d)==24)
		printf("(%d+%d)*%d-%d",a,b,c,d);
if(jian(cheng(jian(a,b),c),d)==24)
		printf("(%d-%d)*%d-%d",a,b,c,d);
if(jian(cheng(cheng(a,b),c),d)==24)
		printf("%d*%d*%d-%d",a,b,c,d);
if(b)if(jian(cheng((double)chu(a,b),c),d)==24)
		printf("%d/%d*%d-%d",a,b,c,d);
if(c)if(jian((double)chu(jia(a,b),c),d)==24)
		printf("(%d+%d)/%d-%d",a,b,c,d);
if(c)if(jian((double)chu(jian(a,b),c),d)==24)
		printf("(%d-%d)/%d-%d",a,b,c,d);
if(jian(chu(cheng(a,b),c),d)==24)
		printf("%d*%d/%d-%d",a,b,c,d);
if(b&&c)if(jian((double)chu((double)chu(a,b),c),d)==24)
		printf("%d/%d/%d-%d",a,b,c,d);
         	if(cheng(jia(jia(a,b),c),d)==24)
		printf("(%d+%d+%d)*%d",a,b,c,d);
if(cheng(jia(jian(a,b),c),d)==24)
		printf("(%d-%d+%d)*%d",a,b,c,d);
if(cheng(jia(cheng(a,b),c),d)==24)
		printf("(%d*%d+%d)*%d",a,b,c,d);
if(b)if(cheng(jia((double)chu(a,b),c),d)==24)
		printf("(%d/%d+%d)*%d",a,b,c,d);
if(cheng(jian(jia(a,b),c),d)==24)
		printf("(%d+%d-%d)*%d",a,b,c,d);
if(cheng(jian(jian(a,b),c),d)==24)
		printf("(%d-%d-%d)*%d",a,b,c,d);
if(cheng(jian(cheng(a,b),c),d)==24)
		printf("(%d*%d-%d)*%d",a,b,c,d);
if(b)if(cheng(jian((double)chu(a,b),c),d)==24)
		printf("(%d/%d-%d)*%d",a,b,c,d);
if(cheng(cheng(jia(a,b),c),d)==24)
		printf("(%d+%d)*%d*%d",a,b,c,d);
if(cheng(cheng(jian(a,b),c),d)==24)
		printf("(%d-%d)*%d*%d",a,b,c,d);
if(cheng(cheng(cheng(a,b),c),d)==24)
		printf("%d*%d*%d*%d",a,b,c,d);
if(b)if(cheng(cheng((double)chu(a,b),c),d)==24)
		printf("%d/%d*%d*%d",a,b,c,d);
if(c)if(cheng((double)chu(jia(a,b),c),d)==24)
		printf("(%d+%d)/%d*%d",a,b,c,d);
if(c)if(cheng((double)chu(jian(a,b),c),d)==24)
		printf("(%d-%d)/%d*%d",a,b,c,d);
if(c)if(cheng((double)chu(cheng(a,b),c),d)==24)
		printf("%d*%d/%d*%d",a,b,c,d);
if(b&&c)if(cheng((double)chu((double)chu(a,b),c),d)==24)
		printf("%d/%d/%d*%d",a,b,c,d);
            if(d)	if((double)chu(jia(jia(a,b),c),d)==24)
		printf("(%d+%d+%d)/%d",a,b,c,d);
if((double)chu(jia(jian(a,b),c),d)==24)
		printf("(%d-%d+%d)/%d",a,b,c,d);
if((double)chu(jia(cheng(a,b),c),d)==24)
		printf("(%d*%d+%d)/%d",a,b,c,d);
if((double)chu(jia(chu(a,b),c),d)==24)
		printf("(%d/%d+%d)/%d",a,b,c,d);
if((double)chu(jian(jia(a,b),c),d)==24)
		printf("(%d+%d-%d)/%d",a,b,c,d);
if((double)chu(jian(jian(a,b),c),d)==24)
		printf("(%d-%d-%d)/%d",a,b,c,d);
if((double)chu(jian(cheng(a,b),c),d)==24)
		printf("(%d*%d-%d)/%d",a,b,c,d);
if((double)chu(jian(chu(a,b),c),d)==24)
		printf("(%d/%d-%d)/%d",a,b,c,d);
if((double)chu(cheng(jia(a,b),c),d)==24)
		printf("(%d+%d)*%d/%d",a,b,c,d);
if((double)chu(cheng(jian(a,b),c),d)==24)
		printf("(%d-%d)*%d/%d",a,b,c,d);
if((double)chu(cheng(cheng(a,b),c),d)==24)
		printf("%d*%d*%d/%d",a,b,c,d);
if((double)chu(cheng((double)chu(a,b),c),d)==24)
		printf("%d/%d*%d/%d",a,b,c,d);
if((double)chu((double)chu(jia(a,b),c),d)==24)
		printf("(%d+%d)/%d/%d",a,b,c,d);
if((double)chu((double)chu(jian(a,b),c),d)==24)
		printf("(%d-%d)/%d/%d",a,b,c,d);
if((double)chu((double)chu(cheng(a,b),c),d)==24)
		printf("%d*%d/%d/%d",a,b,c,d);  
   if(jia(jia(cheng(b,c),d),a)==24)
		printf("%d+(%d*%d)+%d",a,b,c,d);
if(jia(jia((double)chu(b,c),d),a)==24)
		printf("%d+(%d/%d)+%d",a,b,c,d);
if(jia(jian(cheng(b,c),d),a)==24)
		printf("%d+(%d*%d)-%d",a,b,c,d);
if(jia(jian((double)chu(b,c),d),a)==24)
		printf("%d+%d/%d-%d",a,b,c,d);
if(jia(cheng(cheng(b,c),d),a)==24)
		printf("%d+(%d*%d*%d)",a,b,c,d);
if(jia(cheng((double)chu(b,c),d),a)==24)
		printf("%d+(%d/%d*%d)",a,b,c,d);
if(jia((double)chu(jia(b,c),d),a)==24)
		printf("(%d+((%d+%d)/%d)",a,b,c,d);
if(jia((double)chu(jian(b,c),d),a)==24)
		printf("(%d+((%d-%d)/%d)",a,b,c,d);
if(jia(chu(cheng(b,c),d),a)==24)
		printf("%d+(%d*%d/%d)",a,b,c,d);//
if(c*d)if(jia(chu(chu(b,c),d),a)==24)
		printf("%d+(%d/%d/%d)",a,b,c,d);
         	if(cheng(jia(jia(b,c),d),a)==24)
		printf("%d*(%d+%d+%d)",a,b,c,d);
if(cheng(jia(jian(b,c),d),a)==24)
		printf("%d*(%d-%d+%d)",a,b,c,d);
if(cheng(jia(cheng(b,c),d),a)==24)
		printf("%d*(%d*%d+%d)",a,b,c,d);
if(cheng(jia(chu(b,c),d),a)==24)
		printf("%d*((%d/%d)+%d)",a,b,c,d);
if(cheng(jian(jia(b,c),d),a)==24)
		printf("%d*(%d+%d-%d)",a,b,c,d);
if(cheng(jian(jian(b,c),d),a)==24)
		printf("%d*(%d-%d-%d)",a,b,c,d);
if(cheng(jian(cheng(b,c),d),a)==24)
		printf("%d*(%d*%d-%d)",a,b,c,d);
if(c)if(cheng(jian(chu(b,c),d),a)==24)
		printf("(%d*(%d/%d-%d)",a,b,c,d);
if(cheng(cheng(jia(b,c),d),a)==24)
		printf("(%d*((%d+%d)*%d)",a,b,c,d);
if(cheng(cheng(jian(b,c),d),a)==24)
		printf("(%d*((%d-%d)*%d)",a,b,c,d);
if(cheng(cheng(chu(b,c),d),a)==24)
		printf("%d*(%d/%d)*%d",a,b,c,d);
if(d)if(cheng(chu(jia(b,c),d),a)==24)
		printf("%d*((%d+%d)/%d)",a,b,c,d);
if(d)if(cheng(chu(jian(b,c),d),a)==24)
		printf("%d*((%d-%d)/%d)",a,b,c,d);
if(c*d)if(cheng(chu(chu(b,c),d),a)==24)
		printf("%d*(%d/%d/%d)",a,b,c,d);//eawffffsadgfddasfgwd
if(jia(jia(cheng(c,d),b),a)==24)
		printf("%d+%d+(%d*%d)",a,b,c,d);//wenti
if(d)if(jia(jia(chu(c,d),b),a)==24)
		printf("%d+%d+(%d/%d)",a,b,c,d);

if(jia(jian(b,cheng(c,d)),d)==24)
		printf("%d+%d-(%d*%d)",a,b,c,d);
if(d)if(jia(jian(b,chu(c,d)),a)==24)
		printf("%d+%d-(%d/%d)",a,b,c,d);
if(jia(cheng(jia(c,d),b),a)==24)
		printf("%d+(%d*(%d+%d))",a,b,c,d);
if(jia(cheng(jian(c,d),b),a)==24)
		printf("%d+(%d*(%d-%d))",a,b,c,d);
if(jia(chu(b,jia(c,d)),a)==24)
		printf("%d+(%d/(%d+%d))",a,b,c,d);
if(c-d)if(jia(chu(b,jian(c,d)),a)==24)
		printf("%d+%d/(%d-%d)",a,b,c,d);
if(c*d&&c/d)if(jia(chu(b,chu(c,d)),d)==24)
		printf("%d+(%d/(%d/%d))",a,b,c,d);
     
if(cheng(jia(cheng(c,d),b),a)==24)
		printf("%d*(%d+%d*%d)",a,b,c,d);
if(d)if(cheng(jia(chu(c,d),b),a)==24)
		printf("(%d*(%d+%d/%d)",a,b,c,d);
if(cheng(jian(b,jia(c,d)),a)==24)
		printf("%d*(+%d-(%d+%d)",a,b,c,d);
if(cheng(jian(b,jian(c,d)),a)==24)
		printf("%d*(%d-(%d-%d))",a,b,c,d);
if(cheng(jian(b,cheng(c,d)),a)==24)
		printf("%d*(%d-(%d*%d))",a,b,c,d);
if(cheng(jian(b,chu(c,d)),a)==24)
		printf("(%d*(%d-%d/%d)",a,b,c,d);
if(cheng(cheng(jia(a,b),c),d)==24)
		printf("(%d+%d)*%d*%d",a,b,c,d);
if(cheng(cheng(jian(a,b),c),d)==24)
		printf("(%d-%d)*%d*%d",a,b,c,d);
if(cheng(cheng(cheng(a,b),c),d)==24)
		printf("%d*%d*%d*%d",a,b,c,d);
if(cheng(cheng(chu(a,b),c),d)==24)
		printf("%d/%d*%d*%d",a,b,c,d);
if(cheng(chu(jia(a,b),c),d)==24)
		printf("(%d+%d)/%d*%d",a,b,c,d);
if(cheng(chu(jian(a,b),c),d)==24)
		printf("(%d-%d)/%d*%d",a,b,c,d);
if(cheng(chu(cheng(a,b),c),d)==24)
		printf("%d*%d/%d*%d",a,b,c,d);
if(cheng(chu(chu(a,b),c),d)==24)
		printf("%d/%d/%d*%d",a,b,c,d);
            

}