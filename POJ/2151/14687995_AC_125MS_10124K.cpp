#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int M, T, N;
double val[1005][35];
double dp[1005][35][35];//第i组在前j道题解决k道题的概率

int main()
{
	int i, j, k;
	double sum1,sum2,sum3,sum4;

	while (cin >> M >> T >> N)
	{
		if (M + T + N == 0)
		{
			break;
		}
		for (i = 1; i <= T; i++)
		{
			for (j = 1; j <= M; j++)
			{
				cin >> val[i][j];
			}
		}
		memset(dp, 0, sizeof(dp));
		
		for (i = 1; i <= T; i++)
		{
			dp[i][0][0] = 1.0;
		}

		for (i = 1; i <= T; i++)
		{
			for (j = 1; j <= M; j++)
			{
				dp[i][j][0] = dp[i][j - 1][0] * (1 - val[i][j]);
			}
		}

		for (i = 1; i <= T;i++)
		{
			for (j = 1; j <= M; j++)
			{
				for (k = 1; k <= j; k++)
				{
					dp[i][j][k] = dp[i][j - 1][k] * (1 - val[i][j]) + dp[i][j - 1][k - 1] * val[i][j];
				}
			}
		}
		sum2 = 1.0;
		for (i = 1; i <= T; i++)
		{
			sum1 = 0;
			for (j = 1; j <= M; j++)
			{
			   sum1 += dp[i][M][j];
			}
			sum2 = sum1*sum2;
		}
		sum4 = 1.0;
		for (i = 1; i <= T; i++)
		{
			sum3 = 0;
			for (j = 1; j <= N-1; j++)
			{
				sum3 += dp[i][M][j];
			}
			sum4 = sum4*sum3;
		}
		printf("%.3lf\n", sum2 - sum4);
	}
	return 0;
}
