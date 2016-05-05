#include<string.h> int power(int x,int n)
{
int s,i; i=0;s=1; while(i< n)
{s*=x;i++;} return s; }
int main()
{
int x,y,z,a,b,target,sign; char str[30]; int x1,y1,z1,a1,b1;
scanf("%d",&target); getchar();
gets(str); while(target !=0 || strcmp(str,"END") != 0) 
{
sign =0;
for(x=0;x<strlen(str);x++) 
for(y=0;y<strlen(str);y++)
for(z=0;z<strlen(str);z++)
for(a=0;a<strlen(str);a++)
for(b=0;b<strlen(str);b++) 
{
x1= str[x] -'A' +1; 
y1= power( str[y] -'A' +1,2);
z1= power( str[z] -'A' +1,3);
a1 =power( str[a] -'A' +1,4);
b1= power( str[b] -'A' +1,5); if( x1 - y1 + z1 -a1 + b1 == target 
&& (str[x] -'A')!=(str[y] -'A') && (str[x] -'A')!=(str[z] -'A') &&(str[x] -'A')!=(str[a] -'A') &&(str[x] -'A')!=(str[b] -'A') 
&& (str[y] -'A')!=(str[z] -'A') && (str[y] -'A')!=(str[a] -'A') &&(str[y] -'A')!=(str[b] -'A')
&& (str[z] -'A')!=(str[a] -'A') && (str[z] -'A')!=(str[b] -'A')
&& (str[a] -'A')!=(str[b] -'A') )
{
printf("%c%c%c%c%c\n",str[x],str[y],str[z],str[a],str[b]);sign=1; }
} if(sign==0)printf("no solution\n"); 
scanf("%d",&target);getchar(); 
gets(str);
}
return 0;
}