#include<stdio.h>
    int a[17],b[17],t[17];
int check()
{
    int i,sum=0;
    for (i=1;i<=16;i++)
        sum+=b[i];
    if (sum==16||sum==0)
        return 1;
    return 0;
}
int turn(int s)
{
    int x,y;
    x=(s-1)/4+1;y=(s-1)%4+1;
    if (x>1)
        b[s-4]=1-b[s-4];
    if (x<4)
        b[s+4]=1-b[s+4];
    if (y>1)
        b[s-1]=1-b[s-1];
    if (y<4)
        b[s+1]=1-b[s+1];
    b[s]=1-b[s];
}
int main()
{
    int i,j,step,ans;
    char ch;
    for (i=1;i<=4;i++)
    {
        for (j=1;j<=4;j++)
        {
            scanf("%c",&ch);
            if (ch=='w')
                a[i*4-4+j]=1;
            else
                a[i*4-4+j]=0;
        }
        scanf("%c",&ch);
    }
    ans=17;
    for (t[1]=0;t[1]<=1;t[1]++)
    for (t[2]=0;t[2]<=1;t[2]++)    
    for (t[3]=0;t[3]<=1;t[3]++)
    for (t[4]=0;t[4]<=1;t[4]++)
    for (t[5]=0;t[5]<=1;t[5]++)
    for (t[6]=0;t[6]<=1;t[6]++)
    for (t[7]=0;t[7]<=1;t[7]++)
    for (t[8]=0;t[8]<=1;t[8]++)
    for (t[9]=0;t[9]<=1;t[9]++)
    for (t[10]=0;t[10]<=1;t[10]++)
    for (t[11]=0;t[11]<=1;t[11]++)
    for (t[12]=0;t[12]<=1;t[12]++)
    for (t[13]=0;t[13]<=1;t[13]++)
    for (t[14]=0;t[14]<=1;t[14]++)
    for (t[15]=0;t[15]<=1;t[15]++)
    for (t[16]=0;t[16]<=1;t[16]++)
    {
        for (i=1;i<=16;i++)
            b[i]=a[i];
        for (i=1;i<=16;i++)
            if (t[i])
                turn(i);
        if (check())
        {
            step=0;
            for (i=1;i<=16;i++)
                    step=step+t[i];
            if (step<ans)
                ans=step;
        }
    }
    if (ans<=16)
        printf("%d\n",ans);
     else
         printf("Impossible");
}
