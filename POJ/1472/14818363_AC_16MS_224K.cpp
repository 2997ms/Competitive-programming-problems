#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#pragma warning(disable:4996)
using namespace std;

int oper[15];
int coe[15];
string op, op2;

int change(string x)
{
	int res = 0;
	int i, len = x.length();
	for (i = 0; i < len; i++)
	{
		res = res * 10 + x[i] - '0';
	}
	return res;
}
int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int i, test, num, flag, another_flag;
	int j, coe_one, n_num;
	cin >> test;

	for (i = 1; i <= test; i++)
	{
		cout << "Program #" << i << endl;
		cin >> op;

		memset(coe, 0, sizeof(coe));
		num = 0;

		while (num != -1)
		{
			cin >> op;
			if (op == "LOOP")
			{
				cin >> op2;
				if (op2 == "n")
				{
					oper[num++] = -1;
				}
				else
				{
					oper[num++] = change(op2);
				}
			}
			else if (op == "END")
			{
				num--;
			}
			else if (op == "OP")
			{
				cin >> op2;
				coe_one = 1;
				n_num = 0;
				for (j = num - 1; j >= 0; j--)
				{
					if (oper[j] == -1)
					{
						n_num++;
					}
					else
					{
						coe_one = coe_one*oper[j];
					}
				}
				coe[n_num] = coe[n_num] + coe_one * change(op2);
			}
		}

		cout << "Runtime = ";

		flag = 0;
		another_flag = 0;
		for (j = 14; j >= 0; j--)
		{
			if (coe[j] == 0)
			{
				continue;
			}
			else
			{
				another_flag = 1;
				if (j == 0)
				{
					if (flag == 0)
					{
						flag = 1;
						cout << coe[j];
					}
					else
					{
						cout << "+" << coe[j];
					}
				}
				else if (j == 1)
				{
					if (flag == 0)
					{
						flag = 1;
						if (coe[j] != 1)
							cout << coe[j] << "*n";
						else
							cout << "n";
					}
					else
					{
						if (coe[j] != 1)
							cout << "+" << coe[j] << "*n";
						else
							cout << "+n";
					}
				}
				else
				{
					if (flag == 0)
					{
						flag = 1;
						if (coe[j] != 1)
							cout << coe[j] << "*n^" << j;
						else
							cout << "n^" << j;
					}
					else
					{
						if (coe[j] != 1)
							cout << "+" << coe[j] << "*n^" << j;
						else
							cout << "+n^" << j;
					}
				}

			}
		}
		if (another_flag == 0)
			cout << 0;
		cout << endl << endl;
	}

	//system("pause");
	return 0;
}