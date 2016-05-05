#include <iostream>
using namespace std;

int main()
{
	int Test,n,result;
	cin >> Test;

	while (Test--)
	{
		cin >> n;
		result = 0;

		while (n > 0)
		{
			result += n / 5;
			n = n / 5;
		}
		cout << result << endl;
	}
	return 0;
}