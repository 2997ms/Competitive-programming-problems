int app1[30], app2[30];
int idx(char x)
{
    return x - 'a';
}

class Solution 
{
public:
    char findTheDifference(string s, string t) 
    {
        memset(app1, 0, sizeof(app1));
        memset(app2, 0, sizeof(app2));
        for (int i = 0; i < s.length(); i++)
        {
            app1[idx(s[i])]++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            app2[idx(t[i])]++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (app1[i] != app2[i])
            {
                return 'a' + i;
            }
        }
        return 'a';
    }
};
