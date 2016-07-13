/*
 题意：
 有n个数的vector，将这些数分成三组，每一组至少有一个数，要求求出每一组数的异或值，加起来最大。
 题解：
 dp的方法是想到了，想的思路也差不离，但总是在细节处理上不够。
 
 这个题总结的话有几个点没有想到：
 1：当初想用dp[256][256][256]表示当前能够达到的值，其实不用，因为是异或值，所以可以只保留两个，剩下的那个用总异或的值异或回来就好了。那这样，就会有如何保证每一组至少有一个数呢，用[8]来记录。
 */
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <fstream>
#include <iostream>
#include <functional>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <ctime>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

#define eps 1e-10
#define LL_INF 0x3fffffffffffffff
#define INF 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define pper(i,n,m) for(int i = n;i >= m; i--)
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int maxn= 100005;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);

bool dp[55][256][256][8];

class TrySail
{
public:
    int get(vector <int> st)
    {
        int i,j,k,d;
        int sz = st.size();
        mem(dp,0);
        int sv = 0;
        dp[0][0][0][0] = 1;
        for(i=0;i<sz;i++)
        {
            sv = sv ^ st[i];
            for(j=0;j<=255;j++)
            {
                for(k=0;k<=255;k++)
                {
                    for ( d = 0; d <= 7; d++)
                    {
                        if ( dp[i][j][k][d] )
                        {
                            dp[i + 1][j][k][d|4] = 1;
                            dp[i + 1][j ^ st[i]][k][d|1] = 1;
                            dp[i + 1][j][k ^ st[i]][d|2] = 1;
                        }
                    }
                }
            }
        }
        int res=0;
        for(i = 0; i <= 255;i++)
        {
            for(j = 0;j <= 255;j++)
            {
                if(!dp[sz][i][j][7])continue;
                res = max(res , (sv^i^j) + i + j);
            }
        }
        return res;
    }
};

