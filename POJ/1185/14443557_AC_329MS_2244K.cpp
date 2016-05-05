#include <cstdio>
#include <cstring>
#define MAXR 110 //行数
#define MAXC 15  //列数
#define MAXM 70  //状态数
#define max(a,b) a>b?a:b //返回较大值
#define CL(a) memset(a,0,sizeof(a)) //初始化清空数组
#define legal(a,b) a&b //判断两个状态共存时是否合法，合法为0，不合法为非0

int row,col;  //行列
int nums;  //仅是两个炮兵不互相攻击的条件下，符合条件的状态个数
int base[MAXR];  //第i行的原地图压缩成的一个状态
int state[MAXM]; //仅是两个炮兵不互相攻击的条件下，符合条件的状态（一个十进制数）
int soldier[MAXM]; //对应着，在state[i]状态下能放多少个士兵
int dp[MAXR][MAXM][MAXM];
//dp[i][j][k] 表示第i行状态为state[j]，第i-1行状态为state[k]时的最优解
char g[MAXR][MAXC];

int main()
{
    CL(base); CL(state); CL(soldier); CL(dp);
    nums=0;

    scanf("%d%d",&row,&col);
    for(int i=0; i<row; i++)  //先计算原始地图的状态数
    {
        scanf("%s",g[i]);
        for(int j=0; j<col; j++)
        if(g[i][j]=='H') base[i]+=1<<j; //像0110000，这里计算为6
    }

    for(int i=0; i<(1<<col); i++)  //仅是两个炮兵不互相攻击的条件下计算所有状态
    {
        if( legal(i,i<<1) || legal(i,i<<2)) continue; //i这个状态出现了士兵两两攻击
        int k=i;
        while(k) //这个循环计算状态i的二进制形式里面有多少个1，也就是放了多少个士兵
        {
            soldier[nums]+=k&1; //等价于k%2，相当于判断k的二进制形式里面有多少个1
            k=k>>1;
        }
        state[nums++]=i; //保存这个合法的状态
    }

    /***************************************/
    //for(int i=0; i<nums; i++) printf("%d %d\n",state[i],soldier[i]);
    /***************************************/

    for(int i=0; i<nums; i++) //先初始化dp[0][i][0]，即初始化第1行的情况
    {
        if(legal(state[i],base[0])) continue;
        //在state[i]的基础上，还要满足士兵不能放在山上，这个判断就是处理这个问题的
        dp[0][i][0]=soldier[i];
    }
    for(int i=0; i<nums; i++) //接着初始化dp[1][i][j]，即第2行的情况
    {
        if(legal(state[i],base[1])) continue;
        for(int j=0; j<nums; j++) //枚举第1行的状态
        {
            if(legal(state[j],base[0])) continue;
            if(legal(state[i],state[j])) continue;
            dp[1][i][j]=max(dp[1][i][j] , dp[0][j][0]+soldier[i]);
            //状态转移方程
        }
    }

    for(int r=2; r<row; r++) //第3行开始DP直到最后
        for(int i=0; i<nums; i++) //枚举第r行的状态
        {
            if(legal(state[i],base[r])) continue;
            for(int j=0; j<nums; j++) //枚举第r-1行的状态
            {
                if(legal(state[j],base[r-1])) continue;
                if(legal(state[i],state[j])) continue;
                //第r行的士兵和第r-1行的士兵相互攻击
                for(int k=0; k<nums; k++) //枚举第r-2行的状态
                {
                    if(legal(state[k],base[r-2])) continue;

                    if(legal(state[j],state[k])) continue;
                    //第r-1行的士兵和第r-2行的士兵相互攻击
                    if(legal(state[i],state[k])) continue;
                    //第r行的士兵和第r-1
                    dp[r][i][j]=max(dp[r][i][j] , dp[r-1][j][k]+soldier[i]);
                }
            }
        }

    int ans=0;
    for(int i=0; i<nums; i++)
        for(int j=0; j<nums; j++) //枚举dp[row-1][i][j]
            ans=max(ans,dp[row-1][i][j]);
    printf("%d\n",ans);

    return 0;
}