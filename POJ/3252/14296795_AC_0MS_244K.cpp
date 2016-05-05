#include<iostream>
using namespace std;

int c[33][33]={0};
int bin[35];  //十进制n的二进制数

/*打表，计算nCm*/

void play_table(void)
{
    for(int i=0;i<=32;i++)
        for(int j=0;j<=i;j++)
            if(!j || i==j)
                c[i][j]=1;
            else
                c[i][j]=c[i-1][j-1]+c[i-1][j];
//    c[0][0]=0;
    return;
}

/*十进制n转换二进制，逆序存放到bin[]*/

void dec_to_bin(int n)
{
    bin[0]=0;   //b[0]是二进制数的长度
    while(n)
    {
        bin[++bin[0]]=n%2;
        n/=2;
    }
    return;
}

/*计算比十进制数n小的所有RN数*/

int round(int n)
{
    int i,j;
    int sum=0;  //比十进制数n小的所有RN数
    dec_to_bin(n);

    /*计算长度小于bin[0]的所有二进制数中RN的个数*/

    for(i=1;i<bin[0]-1;i++)
        for(j=i/2+1;j<=i;j++)
            sum+=c[i][j];

    /*计算长度等于bin[0]的所有二进制数中RN的个数*/

    int zero=0;  //从高位向低位搜索过程中出现0的位的个数
    for(i=bin[0]-1;i>=1;i--)
        if(bin[i])   //当前位为1
            for(j=(bin[0]+1)/2-(zero+1);j<=i-1;j++)
                sum+=c[i-1][j];
        else
            zero++;

    return sum;
}

int main(void)
{
    play_table();

    int a,b;
    cin>>a>>b;
    cout<<round(b+1)-round(a)<<endl;

    return 0;
}