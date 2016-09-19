class Solution 
{
public:
    string longestPalindrome(string s)
    {
        if (s.length() == 0)return "";
        int len = s.length();
        int res = 1;
        string r = "";
        r = r + s[0];
        for (int pos = 0; pos < len; pos++)
        {
            int pre = pos - 1;
            int aft = pos + 1;
            int ans = 1;
            while (pre >= 0 && aft < len)
            {
                if (s[pre] == s[aft])
                {
                    pre--;
                    aft++;
                    ans += 2;
                }
                else
                {
                    break;
                }
            }
            if (ans > res)
            {
                res = ans;
                r = s.substr(pre + 1, ans);
            }

            ans = 0;
            pre = pos;
            aft = pos + 1;

            while (pre >= 0 && aft < len)
            {
                if (s[pre] == s[aft])
                {
                    pre--;
                    aft++;
                    ans += 2;
                }
                else
                {
                    break;
                }
            }
            if (ans > res)
            {
                res = ans;
                r = s.substr(pre + 1, ans);
            }
        }
        return r;
    }
}t;