/*
 题意是给出了两个集合，找出集合中公共元素。
 自己写麻烦了，对每个数组之后排序，然后两指针往后找就好了。
 */
//#pragma comment(linker, "/STACK:102400000,102400000")
#pragma warning(disable:4996)
#include <fstream>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
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

const int maxn = 100005;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);

class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int>res;
        map<int, int>n1;
        map<int, int>n2;
        
        int i, j, k;
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        rep(i, 0, sz1)
        {
            n1[nums1[i]]++;
        }
        rep(i, 0, sz2)
        {
            n2[nums2[i]]++;
        }
        for (map<int, int>::iterator it1 = n1.begin(); it1 != n1.end(); it1++)
        {
            for (map<int, int>::iterator it2 = n2.begin(); it2 != n2.end(); it2++)
            {
                if ((*it1).first == (*it2).first)
                {
                    repp(i, 1, min((*it1).second, (*it2).second))
                    {
                        res.push_back((*it1).first);
                    }
                }
            }
        }
        return res;
    }
};
