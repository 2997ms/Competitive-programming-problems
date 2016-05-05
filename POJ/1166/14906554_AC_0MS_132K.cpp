#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

int a[10][10];
int x[10];
bool free_x[10];
int sum;

int Gauss(int equ,int var)
{
    memset(x,0,sizeof(x));
    memset(free_x,1,sizeof(free_x));

    int k=0,col=0;
    while(k<equ && col<var)
    {
        if(a[k][col]==0)
            for(int i=k+1;i<equ;i++)
                if(a[i][col])
                    for(int j=col;j<=var;j++)
                        swap(a[i][j],a[k][j]);

        if(a[k][col]==0)
        {
            col++;
            continue;
        }

        for(int i=k+1;i<equ;i++) if(a[i][col])
        {
            int ta =a[i][col];
            int tb =a[k][col];

            for(int j=col;j<=var;j++)
            {
                a[i][j]=a[i][j]*tb-a[k][j]*ta;
                a[i][j]=(a[i][j]%4+4)%4;
            }
        }
        k++;
        col++;
    }

    for(int i=var-1;i>=0;i--)
    {
        int temp=a[i][var];
        for(int j=i+1;j<var;j++) if(a[i][j])
            temp-=a[i][j]*x[j];
        temp=(temp%4+4)%4;
        for(x[i]=0;x[i]<=3;x[i]++)  // 转5次和转1次没区别，所以只有4种
            if((x[i]*a[i][i]%4+4)%4==temp) // 尝试解
                break;
        x[i]%=4;
        sum+=x[i];
    }
    return 0;
}

int main()
{
//    freopen("in.txt","r",stdin);

    a[0][0]=a[1][0]=a[3][0]=a[4][0]=1;
    a[0][1]=a[1][1]=a[2][1]=1;
    a[1][2]=a[2][2]=a[4][2]=a[5][2]=1;
    a[0][3]=a[3][3]=a[6][3]=1;
    a[1][4]=a[3][4]=a[4][4]=a[5][4]=a[7][4]=1;
    a[2][5]=a[5][5]=a[8][5]=1;
    a[3][6]=a[4][6]=a[6][6]=a[7][6]=1;
    a[6][7]=a[7][7]=a[8][7]=1;
    a[4][8]=a[5][8]=a[7][8]=a[8][8]=1;

    for(int i=0;i<9;i++)
    {
        scanf("%d",&a[i][9]);
        a[i][9]=(4-a[i][9])%4; // 要转的次数
    }
    Gauss(9,9);
    for(int j=0;j<9;j++)
        while(x[j])
        {
            printf("%d",j+1);
            x[j]--;
            sum--;
            printf(sum>0?" ":"\n");
        }
}
