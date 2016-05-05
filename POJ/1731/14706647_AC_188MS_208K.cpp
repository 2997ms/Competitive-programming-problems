#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

char test[250];

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	while (cin >> test)
	{
		sort(test, test + strlen(test));
		do {
			cout << test << endl;
		} while (next_permutation(test, test + strlen(test)));
	}
	return 0;
}
