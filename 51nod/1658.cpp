/*理想中的最大答案就比最初多两个*/
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

int n, res;
string s;

int main()
{
   
    int i, j;
    cin >> n;
    cin >> s;

    res = 1;
    for (i = 1; i < n; i++)
    {   
        if (s[i] != s[i - 1])
        {
            res++;
        }
    }
    res = min(n, res + 2);
    cout << res << endl;
    return 0;
}