#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#define N 12
using namespace std;
int b[N][N],a[N][N],tag[N],pt[N],row_i[N],row_j[N];
int ans[N];
int main()
{
    //freopen("data.in","r",stdin);
    memset(b,0,sizeof(b));
    b[1][1] = 1; b[1][2] = 1; b[1][4] = 1;
    b[2][1] = 1; b[2][2] = 1; b[2][3] = 1; b[2][5] = 1;
    b[3][2] = 1; b[3][3] = 1; b[3][6] = 1;
    b[4][1] = 1; b[4][4] = 1; b[4][5] = 1; b[4][7] = 1;
    b[5][1] = 1; b[5][3] = 1; b[5][5] = 1; b[5][7] = 1; b[5][9] = 1;
    b[6][3] = 1; b[6][5] = 1; b[6][6] = 1; b[6][9] = 1;
    b[7][4] = 1; b[7][7] = 1; b[7][8] = 1;
    b[8][5] = 1; b[8][7] = 1; b[8][8] = 1; b[8][9] = 1;
    b[9][6] = 1; b[9][8] = 1; b[9][9] = 1;
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        a[1][10] = (4-k)%4;
        for(int i=2;i<=9;i++)
        {
            scanf("%d",&k);
            a[i][10] = (4-k)%4;
        }
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                a[i][j] = b[i][j];
            }
        }
        for(int i=1;i<=9;i++)
        {
            tag[i] = 11;
            for(int j=1;j<=10;j++)
            {
                if(a[i][j])
                {
                    tag[i] = j;
                    break;
                }
            }
        }
        memset(pt,0,sizeof(pt));
        pt[tag[1]] = 1;
        for(int i=2;i<=9;i++)
        {
            while(true)
            {
                int x = tag[i];
                if(x==11||x==10)
                {
                    break;
                }
                if(!pt[x])
                {
                    pt[x] = i;
                    break;
                }
                int j = pt[x];
                int val_j = a[j][x];
                int val_i = a[i][x];
                for(int u=1;u<=10;u++)
                {
                    row_j[u] = (a[j][u]*val_i)%4;
                    row_i[u] = (a[i][u]*val_j)%4;
                    row_i[u] = ((row_i[u] - row_j[u])%4+4)%4;
                    a[i][u] = row_i[u];
                }
                tag[i] = 11;
                for(int u =1;u<=10;u++)
                {
                    if(a[i][u])
                    {
                        tag[i] = u;
                        break;
                    }
                }
            }
        }
        for(int i=9;i>=1;i--)
        {
            int pos = pt[i];
            int s = 0;
            for(int j=i+1;j<=9;j++)
            {
                s = (s+ans[j]*a[pos][j])%4;
            }
            s = ((a[pos][10]-s)%4+4)%4;
            for(int j=0;;j++)
            {
                if((a[pos][i]*j)%4==s)
                {
                    ans[i] = j;
                    break;
                }
            }
        }
        bool w=false;
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=ans[i];j++)
            {
                if(!w)
                {
                    printf("%d",i);
                    w = true;
                }else
                {
                    printf(" %d",i);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
