#pragma warning(disable:4996) 
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int val[15];
int num[15];

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	
	int i, sum;
	int i1, i2, i3, i4, i5, i6, i7, i8, i9;
	int j1, j2, j3, j4, j5, j6, j7, j8, j9;

	for (i = 1; i <= 9; i++)
		scanf("%d", &val[i]);

	for (i1 = 0; i1 < 4; i1++)
	{
		for (i2 = 0; i2 < 4; i2++)
		{
			for (i3 = 0; i3 < 4; i3++)
			{
				for (i4 = 0; i4 < 4; i4++)
				{
					for (i5 = 0; i5 < 4; i5++)
					{
						for (i6 = 0; i6 < 4; i6++)
						{
							for (i7 = 0; i7 < 4; i7++)
							{
								for (i8 = 0; i8 < 4; i8++)
								{
									for (i9 = 0; i9 < 4; i9++)
									{
										num[1] = (val[1] + i1 + i2 + i4) % 4;
										num[2] = (val[2] + i1 + i2 + i3 + i5) % 4;
										num[3] = (val[3] + i2 + i3 + i6) % 4;
										num[4] = (val[4] + i1 + i4 + i5 + i7) % 4;
										num[5] = (val[5] + i1 + i3 + i5 + i7 + i9) % 4;
										num[6] = (val[6] + i3 + i5 + i6 + i9) % 4;
										num[7] = (val[7] + i4 + i7 + i8) % 4;
										num[8] = (val[8] + i5 + i7 + i8 + i9) % 4;
										num[9] = (val[9] + i6 + i8 + i9) % 4;

										sum = 0;
										for (i = 1; i <= 9; i++)
											sum += num[i];
										if (sum == 0)
										{
											for (j1 = 1; j1 <= i1; j1++)printf("1 ");
											for (j2 = 1; j2 <= i2; j2++)printf("2 ");
											for (j3 = 1; j3 <= i3; j3++)printf("3 ");
											for (j4 = 1; j4 <= i4; j4++)printf("4 ");
											for (j5 = 1; j5 <= i5; j5++)printf("5 ");
											for (j6 = 1; j6 <= i6; j6++)printf("6 ");
											for (j7 = 1; j7 <= i7; j7++)printf("7 ");
											for (j8 = 1; j8 <= i8; j8++)printf("8 ");
											for (j9 = 1; j9 <= i9; j9++)printf("9 ");
											return 0;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	//system("pause");
	return 0;
}