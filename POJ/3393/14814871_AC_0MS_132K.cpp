//当y大于1582年且y不等于1700年的时候，它是闰年的条件是
//它能被4整除
//它不能被100整除除非它能被400整除

//当y小于1582年的时候它是闰年的条件是
//它能被4整除

//1752年的9月丢了11天，从3号到13号

//lucky month 这个月的最后一个工作日是星期五
//good month 这个月的第一个工作日是星期一
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;

int start_year, start_month, end_year, end_month;
int not_leap_year[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int leap_year[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool check_year(int x)//判断x年是不是闰年
{
	if (x == 1700)
		return true;
	if (x >= 1582)
	{
		if (x % 4 == 0)
		{
			if (x % 400 == 0)
			{
				return true;
			}
			if (x % 100 == 0)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (x % 4 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int cal(int year, int month)
{
	int i, j;
	int res = 0;
	for (i = 1; i <= year - 1; i++)
	{
		if (check_year(i))
		{
			for (j = 0; j < 12; j++)
			{
				if (i == 1752 && j == 8)
				{
					res += 19;
					continue;
				}
				res += leap_year[j];
			}
		}
		else
		{
			for (j = 0; j < 12; j++)
			{
				res += not_leap_year[j];
			}
		}
	}

	if (check_year(year))
	{
		for (j = 0; j < month; j++)
		{
			if (year == 1752 && j == 8)
			{
				res += 19;
				continue;
			}
			res += leap_year[j];
		}
	}
	else
	{
		for (j = 0; j < month; j++)
		{
			res += not_leap_year[j];
		}
	}
	return res;
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int test, i, j, ans1, ans2;

	scanf("%d", &test);
	while (test--)
	{
		scanf("%d%d%d%d", &start_year, &start_month, &end_year, &end_month);

		ans1 = 0;
		ans2 = 0;
		if (start_year == end_year)
		{
			int num = cal(start_year, start_month - 1);//计算这之前有多少天
			if (check_year(start_year))
			{
				for (i = start_month - 1; i <= end_month - 1; i++)
				{
					int temp = ((num + 1) + 5) % 7;
					if (temp == 1 || temp == 6 || temp == 0)
					{
						ans1++;
					}
					if (start_year == 1752 && i == 8)
					{
						num += 19;
					}
					else
						num = num + leap_year[i];
					temp = (num + 5) % 7;
					if (temp == 5 || temp == 6 || temp == 0)
					{
						ans2++;
					}
				}
			}
			else
			{
				for (i = start_month - 1; i <= end_month - 1; i++)
				{
					int temp = ((num + 1) + 5) % 7;
					if (temp == 1 || temp == 6 || temp == 0)
					{
						ans1++;
					}
					num = num + not_leap_year[i];
					temp = (num + 5) % 7;
					if (temp == 5 || temp == 6 || temp == 0)
					{
						ans2++;
					}
				}
			}
		}
		else
		{
			int num = cal(start_year, start_month - 1);

			if (check_year(start_year))
			{
				for (i = start_month - 1; i < 12; i++)
				{
					int temp = ((num + 1) + 5) % 7;
					if (temp == 1 || temp == 6 || temp == 0)
					{
						ans1++;
					}
					if (start_year == 1752 && i == 8)
					{
						num += 19;
					}
					else
						num = num + leap_year[i];
					temp = (num + 5) % 7;
					if (temp == 5 || temp == 6 || temp == 0)
					{
						ans2++;
					}
				}
			}
			else
			{
				for (i = start_month - 1; i < 12; i++)
				{
					int temp = ((num + 1) + 5) % 7;
					if (temp == 1 || temp == 6 || temp == 0)
					{
						ans1++;
					}
					num = num + not_leap_year[i];
					temp = (num + 5) % 7;
					if (temp == 5 || temp == 6 || temp == 0)
					{
						ans2++;
					}
				}
			}

			for (i = start_year + 1; i <= end_year - 1; i++)
			{
				if (check_year(i))
				{
					for (j = 0; j < 12; j++)
					{
						int temp = ((num + 1) + 5) % 7;
						if (temp == 1 || temp == 6 || temp == 0)
						{
							ans1++;
						}
						if (i == 1752 && j == 8)
						{
							num += 19;
						}
						else
							num = num + leap_year[j];
						temp = (num + 5) % 7;
						if (temp == 5 || temp == 6 || temp == 0)
						{
							ans2++;
						}
					}
				}
				else
				{
					for (j = 0; j < 12; j++)
					{
						int temp = ((num + 1) + 5) % 7;
						if (temp == 1 || temp == 6 || temp == 0)
						{
							ans1++;
						}
						num = num + not_leap_year[j];
						temp = (num + 5) % 7;
						if (temp == 5 || temp == 6 || temp == 0)
						{
							ans2++;
						}
					}
				}
			}

			if (check_year(end_year))
			{
				for (i = 0; i < end_month; i++)
				{
					int temp = ((num + 1) + 5) % 7;
					if (temp == 1 || temp == 6 || temp == 0)
					{
						ans1++;
					}
					if (end_year == 1752 && i == 8)
					{
						num += 19;
					}
					else
						num = num + leap_year[i];
					//num = num + leap_year[i];
					temp = (num + 5) % 7;
					if (temp == 5 || temp == 6 || temp == 0)
					{
						ans2++;
					}
				}
			}
			else
			{
				for (i = 0; i < end_month; i++)
				{
					int temp = ((num + 1) + 5) % 7;
					if (temp == 1 || temp == 6 || temp == 0)
					{
						ans1++;
					}
					num = num + not_leap_year[i];
					temp = (num + 5) % 7;
					if (temp == 5 || temp == 6 || temp == 0)
					{
						ans2++;
					}
				}
			}

		}

		printf("%d %d\n", ans2, ans1);
	}
	//system("pause");
	return 0;
}