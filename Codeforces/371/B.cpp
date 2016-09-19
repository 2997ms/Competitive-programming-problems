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

const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

int n;
using rect = vector<int>;
vector<rect>answer;

int query(int x1, int y1, int x2, int y2)
{
    if (x1 > x2 || y1 > y2)
    {
        return 0;
    }
    printf("?");
    printf(" %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);

    int result = 0;
#ifdef LOCAL_JUDGE
    for (auto&& rect : answer) {
        result += x1 <= rect.at(0) && rect.at(2) <= x2 && y1 <= rect.at(1) && rect.at(3) <= y2;
    }
#else
    scanf("%d", &result);
#endif
    return result;
}

int bin_search(int le, int ri, function<bool(int)>check)
{
    while (le < ri)
    {
        int mid = (le + ri) >> 1;
        if (check(mid))
        {
            ri = mid;
        }
        else
        {
            le = mid + 1;
        }
    }
    return ri;
}

rect find_one(int x1, int y1, int x2, int y2)
{
    int res_x1 = bin_search(x1, x2, [&](int xx) {return query(xx + 1, y1, x2, y2) == 0; });
    int res_x2 = bin_search(x1, x2, [&](int xx) {return query(res_x1, y1, xx, y2) >= 1; });
    int res_y1 = bin_search(y1, y2, [&](int yy) {return query(res_x1, yy + 1, res_x2, y2) == 0; });
    int res_y2 = bin_search(y1, y2, [&](int yy) {return query(res_x1, res_y1, res_x2, yy) >= 1; });

    return vector<int>{res_x1, res_y1, res_x2, res_y2};
}

int main()
{   
#ifdef LOCAL_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    n = 100;
    answer.push_back({ 8,7,90,37 });
    answer.push_back({ 4,64,4,100 });
#else
    scanf("%d", &n);
#endif
    int x = bin_search(1, n, [&](int xx) {return query(1, 1, xx, n) >= 1; });
    vector<rect> res;

    if (query(x + 1, 1, n, n) == 1)
    {
        res.push_back(find_one(1, 1, x, n));
        res.push_back(find_one(x + 1, 1, n, n));
    }
    else
    {
        int y= bin_search(1, n, [&](int yy) {return query(1, 1, n, yy) >= 1; });
        res.push_back(find_one(1, 1, n, y));
        res.push_back(find_one(1, y + 1, n, n));
    }
    printf("!");

    for (auto r : res)
    {
        for (int i = 0; i < 4; i++)
        {
            printf(" %d", r.at(i));
        }
    }
    //system("pause");
    return 0;
}