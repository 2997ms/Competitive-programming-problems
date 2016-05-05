#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
using std::queue;
#define min(x, y) ((x)<(y)?(x):(y))
#define MAXN 205
#define INF 20000
bool vis[MAXN];
int cnt, cnt_h, cnt_m, result;
int d[MAXN], pre[MAXN], cost[MAXN][MAXN], cap[MAXN][MAXN];
queue <int> q;
struct node
{
    int x, y;
}hos[MAXN], man[MAXN];
int step(int i, int j)
{
    return abs(man[i].x-hos[j].x) + abs(man[i].y-hos[j].y);
}
void make_map()
{
    int i, j;
    memset(cap, 0, sizeof(cap));
    for (i = 0; i < cnt_m; i++) // connect supersource
    {
        cap[0][i+2] = 1;
        cost[0][i+2] = 0;
    }
    for (i = 0; i < cnt_h; i++) // connect superend
    {
        cap[cnt_m+i+2][1] = 1;
        cost[cnt_m+i+2][1] = 0;
    }
    for (i = 0; i < cnt_m; i++)
        for (j = 0; j < cnt_h; j++)
        {
            cap[i+2][cnt_m+j+2] = 1;
            cost[i+2][cnt_m+j+2] = step(i, j);
            cost[cnt_m+j+2][i+2] = -cost[i+2][cnt_m+j+2]; // 逆边一定要记得加
        }
}
bool spfa()
{
    int i, u, head, tail;
    for (i = 1; i <= cnt; i++) // init
    {
        d[i] = INF;
        vis[i] = false;
    }
    d[0] = 0;
    while (!q.empty())
        q.pop();
    q.push(0);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        vis[u] = true;
        for (i = 1; i <= cnt; i++)
            if (cap[u][i] && d[i] > d[u] + cost[u][i]) // 松弛
            {
                d[i] = d[u] + cost[u][i];
                pre[i] = u;
                if (!vis[i])
                {
                    vis[i] = true;
                    q.push(i);
                }
            }
        vis[u] = false; // 取消标记反复搜索
    }
    if (d[1] < INF) // end
        return true;
    return false;
}
void compute()
{
    int i, cf;
    cf = INF;
    for (i = 1; i != 0; i = pre[i])
        cf = min(cf, cap[pre[i]][i]);
    for (i = 1; i != 0; i = pre[i])
    {
        cap[pre[i]][i] -= cf;
        cap[i][pre[i]] += cf;
        result += cost[pre[i]][i] * cf;
    }
}
int main()
{
    char c;
    int i, j, n, m;
    while (scanf("%d%d", &n, &m), n && m)
    {
        cnt_h = cnt_m = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
            {
                scanf(" %c", &c);
                if (c == 'H')
                {
                    hos[cnt_h].x = i;
                    hos[cnt_h].y = j;
                    cnt_h++;
                }
                else if (c == 'm')
                {
                    man[cnt_m].x = i;
                    man[cnt_m].y = j;
                    cnt_m++;
                }
            }
        cnt = cnt_h + cnt_m + 1;
        make_map();
        result = 0;
        while (spfa())
            compute();
        printf("%d\n", result);
    }
    return 0;
}