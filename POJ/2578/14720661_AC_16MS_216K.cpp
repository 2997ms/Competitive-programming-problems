#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int a, b, c;
	cin >> a >> b >> c;
	
	if (a <= 168)
	{
		cout << "CRASH " << a << endl;
	}
	else if (b <= 168)
	{
		cout << "CRASH " << b << endl;
	}
	else if (c <= 168)
	{
		cout << "CRASH " << c << endl;
	}
	else
	{
		cout << "NO CRASH " << endl;
	}

	//system("pause");
	return 0;
}
