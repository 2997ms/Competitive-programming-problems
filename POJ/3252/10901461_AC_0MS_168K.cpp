#include <stdio.h>
int C[32][32];
void Begin()//构造出杨辉三角
{
    int i,j;
    for (i=0;i<32;i++)
		C[0][i]=C[1][i]=0;
    C[0][0]=C[1][1]=1;
    for (i=2;i<32;i++)
        for (C[i][0]=0,j=1;j<32;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
}
int RN(int n)
{
    int a[40],i,j,t,s=0;
    for (t=0;n>0;n>>=1,t++)
		a[t]=n&1;//进制转换  
	for (i=1;i<t;i++)
        for (j=i>>1;j>0;j--)
			s+=C[i][j];//计算第一区间   
		for (n=0,i=t-2;i>=0;i--)//计算之后的区间     
			if (a[i]==1)
				for (n++,j=(t>>1)-n;j>=0;j--)
					s+=C[i+1][j+1];
				return s;
}
int main(){ 
	int a,b; 
	Begin();
    scanf("%d%d",&a,&b);
    printf("%d\n",RN(b+1)-RN(a));//因为RN(n)并不包括n，所以需要略作改动    
	return 0;
}
