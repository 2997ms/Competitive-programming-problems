#include <iostream>   
#include <string>   
#include <algorithm>   
using namespace std;  
  
int solve(string str1, string str2)  
{  
    int i, j, k, len1, len2, ans;  
    bool flag;  
    len1 = str1.length();  
    len2 = str2.length();  
    for (i = 0; i < len1; i++){  
        flag = 1;  
        for (j = i; j < len1 && j < i + len2; j++){  
            if (str1[j] == '2' && str2[j - i] == '2'){  
                flag = 0;  
            }  
        }  
        if (flag){  
            return max(len1, i + len2);  
        }  
    }  
    return len1 + len2;  
}  
  
int main()  
{  
    int ans;  
    string sec1, sec2;  
    cin >> sec1 >> sec2;  
    ans = min(solve(sec1, sec2), solve(sec2, sec1));  
    cout << ans << endl;  
      
    system("pause");  
}  
