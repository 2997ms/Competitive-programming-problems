class Solution
{
public:
    int firstUniqChar(string s)
    {
        int app[30];
        memset(app, 0, sizeof(app));
        int len = s.length();

        for (int i = 0; i < len; i++)
        {
            int x = s[i] - 'a';
            app[x]++;
        }
        for (int i = 0; i < len; i++)
        {
            int x = s[i] - 'a';
            if (app[x] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};