//cf 768E

#include <cstdio>
#include <cstring>

bool vis[100];

int mex() {
    for(int i = 0; ; i++) if(!vis[i]) return i;
}

int sg[11][1 << 10];

int main()
{
    memset(sg, -1, sizeof(sg));
    for(int i = 0; i < (1 << 10); i++) sg[0][i] = 0;
    for(int i = 1; i <= 10; i++) {
        sg[i][0] = 0;
        for(int j = 1; j < (1 << 10); j++) {
            memset(vis, false, sizeof(vis));
            for(int k = 0; k < i; k++) if((j >> k) & 1)
                vis[sg[i - k - 1][j ^ (1 << k)]] = true;
            sg[i][j] = mex();
        }
    }

    for(int i = 0; i <= 10; i++)
        printf("i = %d: sg = %d\n", i, sg[i][(1 << i) - 1]);

    return 0;
}