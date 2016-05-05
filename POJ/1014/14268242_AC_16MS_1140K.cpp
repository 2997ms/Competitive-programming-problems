#include <iostream>
using namespace std;

const    int        maxn = 8, maxm = 120002;

int        marble[maxn], total;
bool    f[maxn][maxm];

void init()
{
    int        i;
    bool    end = true;

    total = 0;
    for (i = 1; i <= 6; i++)
    {
        cin >> marble[i];
        total += marble[i] * i;
        if (marble[i] != 0)
            end = false;
    }
    if (!total)
        exit(0);
}

void work()
{
    int        i, j, goal = total / 2, k;

    memset(f, 0, sizeof(f));
    f[0][0] = true;
    for (i = 0; i <= 6; i++)
    {
        for (j = goal; j >= 0; j--)
        {
            if (!f[i][j])
                continue;
            for (k = 0; k <= marble[i]; k++)
            {
                if (j + k * i > goal)
                    break;
                if (f[i + 1][j + k * i])
                    break;
                f[i + 1][j + k * i] = true;
            }
        }
    }
    if (f[7][goal])
        printf("Can be divided.\n\n");
    else
        printf("Can't be divided.\n\n");
}

int main()
{
    int        t = 0;
    bool    first;

    //freopen("t.txt", "r", stdin);
    first = true;
    while (true)
    {
        t++;
        init();
        printf("Collection #%d:\n", t);
        if (total % 2 != 0)
        {
            printf("Can't be divided.\n\n");
            continue;
        }
        work();
    }
    return 0;
}