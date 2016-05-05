#include <set>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

#define eps 1e-6
#define pi acos(-1.0)
#define inf 107374182
#define inf64 1152921504606846976
#define lc l,m,tr<<1
#define rc m + 1,r,tr<<1|1
#define iabs(x)  ((x) > 0 ? (x) : -(x))
#define clear1(A, X, SIZE) memset(A, X, sizeof(A[0]) * (SIZE))
#define clearall(A, X) memset(A, X, sizeof(A))
#define memcopy1(A , X, SIZE) memcpy(A , X ,sizeof(X[0])*(SIZE))
#define memcopyall(A, X) memcpy(A , X ,sizeof(X))
#define max( x, y )  ( ((x) > (y)) ? (x) : (y) )
#define min( x, y )  ( ((x) < (y)) ? (x) : (y) )

using namespace std;

struct node
{
    double num[28];
    //int cnt[28];
    node()
    {
        clearall(num,0);
        //clearall(cnt,0);
    }
    void clen()
    {
        clearall(num,0);
        //clearall(cnt,0);
    }
};

struct node matrix[30];
int n,m,len,p;
bool free_x[305];

double X[305];

inline double zero(double x)
{
    if(fabs(x)>eps)return x;
    return 0;
}

void Debug(void)
{
    puts("");
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            cout << matrix[i].num[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int Guass()
{
    int i,j,k,col;
    clearall(X,0);
    clearall(free_x,1);//把解集清空，所有变量都标为自由变量

    //Debug();

    for (k = 0,col = 0; k < m && col < n; ++k, ++col) //枚举行列
    {
        int max_r = k;//找到该col列元素绝对值最大的那行与第k行交换.(为了在除法时减小误差)
        for (i = k + 1; i < m; ++i)
        {
            if (iabs(matrix[i].num[col]) > iabs(matrix[max_r].num[col])) max_r = i;
        }
        if (max_r != k) //交换
        {
            for (i = k; i < n + 1; ++i) swap(matrix[k].num[i],matrix[max_r].num[i]);
        }
        if (iabs(matrix[k].num[col])<eps ) //如果对应该列都为0，枚举该行的下一列
        {
            k--;
            continue;
        }
        for (i = k + 1; i < m; ++i) //将k后边的col进行初等变换成行阶梯矩阵
        {
            if (iabs(matrix[i].num[col])>eps)
            {
                double d=matrix[i].num[col]/matrix[k].num[col];
                for (j = col; j < n + 1; ++j)
                {
                    matrix[i].num[j] =matrix[i].num[j] - d*matrix[k].num[j];
                }
            }
        }
    }

    //Debug();
    // 1. 无解的情况: 化简的增广阵中存在(0, 0, ..., a)这样的行(a != 0). 即R(A) != R(A')无解
    for (i = k; i < m; ++i)
    {
        if (iabs(matrix[i].num[col]) >eps) return -1;
    }
    // 2. 无穷解的情况: 在n * (n + 1)的增广阵中出现(0, 0, ..., 0)这样的行，即说明没有形成严格的上三角阵.
    // 且出现的行数即为自由变元的个数.   即R(A) = R(A') < n
    //printf("%d %d\n",k,n);
    if (k < n)
    {
        //注释处为求多解的自由变量
        // 首先，自由变元有n - k个，即不确定的变元至少有n - k个.
        int num = 0,freeidx;
        for (i = k - 1; i >= 0; --i)
        {
            num = 0;// 用于判断该行中的不确定的变元的个数，如果超过1个，则无法求解，它们仍然为不确定的变元.
            double tmp = matrix[i].num[n];
            // 第i行一定不会是(0, 0, ..., 0)的情况，因为这样的行是在第k行到第m行.
            // 同样，第i行一定不会是(0, 0, ..., a), a != 0的情况，这样的无解的.
            for (j = 0; j < n; ++j)
            {
                if (iabs(matrix[i].num[j]) > eps && free_x[j])
                {
                    num++;
                    freeidx = j;
                }
            }
            if (num > 1) continue; // 无法求解出确定的变元.
            // 说明就只有一个不确定的变元free_index，那么可以求解出该变元，且该变元是确定的.
            tmp = matrix[i].num[n];
            for (j = 0; j < n; ++j)
            {
                if (iabs(matrix[i].num[j])>eps && j != freeidx) tmp -= matrix[i].num[j]*X[j];
            }
            X[freeidx] = tmp/matrix[i].num[freeidx];
            free_x[freeidx] = 0;
        }
        return n - k;
    }
    // 3. 唯一解的情况: 在n * (n + 1)的增广阵中形成严格的上三角阵.
    // 计算出Xn-1, Xn-2 ... X0.
    for (i = k - 1; i >= 0; --i)
    {
        double tmp = matrix[i].num[n];
        for (j = i + 1; j < n; ++j)
        {
            tmp =tmp- matrix[i].num[j]*X[j];
        }
        X[i] = tmp/matrix[i].num[i];
    }
    return 0;
}
char s[250];
void dfs(node &a)
{
    node temp;
    int num,cnt=0;
    while(s[p]!=')')
    {
        if(s[p]>='a'&&s[p]<='z')
        {
            a.num[s[p]-'a']+=1;
            p++;
            cnt++;
        }
        else if(s[p]==' ')p++;
        else if(s[p]=='-')
        {
            p++;
            num=0;
            while(s[p]>='0'&&s[p]<='9')
            {
                num*=10;
                num+=s[p]-'0';
                p++;
            }
            a.num[n]-=num;
            cnt++;
        }
        else if(s[p]>='0'&&s[p]<='9')
        {
            num=0;
            while(s[p]>='0'&&s[p]<='9')
            {
                num*=10;
                num+=s[p]-'0';
                p++;
            }
            a.num[n]+=num;
            cnt++;
        }
        else if(s[p]=='(')
        {
            p++;
            temp.clen();
            dfs(temp);
            cnt++;
            for(int i=0; i<=n; i++)
            {
                a.num[i]+=temp.num[i];
            }
        }
    }
    if(cnt)
    {
        for(int i=0; i<27; i++)
        {
            a.num[i]/=cnt;
        }
    }
    p++;
    /*printf("%d\n",cnt);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<27; j++)
        {
            if(j!=0)printf(" ");
            printf("%.2lf",a.num[j]);
        }
        puts("");
    }*/
    return ;
}
int main()
{
   // freopen("data.out","w",stdout);
    int case1=1;
    while(scanf("%d",&n),n)
    {
        m=n;
        getchar();
        clearall(matrix,0);
        for(int i=0; i<n; i++)
        {
            gets(s);
            len=strlen(s);
            p=0;
            while(s[p]!='(')
            {
                p++;
            }
            p++;
            dfs(matrix[i]);
            for(int j=0; j<n; j++)
            {
                matrix[i].num[j]=-matrix[i].num[j];
            }
            matrix[i].num[i]++;
        }

        int sta=Guass();
        /*for(int i=0; i<n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(j!=0)printf(" ");
                printf("%.2lf",matrix[i].num[j]);
            }
            puts("");
        }
        puts("");*/
        printf("Game %d\n",case1++);

        for(int i=0; i<n; i++)
        {
            printf("Expected score for %c ",i+'a');
            if(sta==-1)
            {
                puts("undefined");
            }
            else
            {

                    if(sta==0) printf("= %.3lf\n",zero(X[i]));
                    else if(free_x[i])puts("undefined");
                    else printf("= %.3lf\n",zero(X[i]));
            }
        }
        puts("");
    }
    return 0;
}
