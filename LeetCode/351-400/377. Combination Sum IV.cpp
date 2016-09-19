#pragma comment(linker, "/STACK:102400000,102400000") 
#pragma warning(disable:4996)
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
#include <list>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define eps 1e-10
#define LL_INF 0x33ffffffffffffff
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

const int maxn = 2e5 + 1;
const ll mod = 998244353;
const double PI = acos(-1.0);

int dp[maxn];

class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        int sz = nums.size();
        if (sz == 0)
        {
            return 0;
        }
        int i, j, k;
        sort(nums.begin(), nums.end());

        mem(dp, 0);
        dp[0] = 1;
        for (i = 1; i <= target;i++)
        {
            rep(h, 0, sz)
            {
                if (i >= nums[h])
                {
                    dp[i] += dp[i - nums[h]];
                }
            }
        }
        return dp[target];
    }
}t;

